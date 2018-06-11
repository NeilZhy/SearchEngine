#include "set_inverted_index.h"


//cppjieba
WordSegmentation::WordSegmentation()
    : _jieba(DICT_PATH
            , HMM_PATH
            , USER_DICT_PATH
            , IDF_PATH
            , STOP_WORD_PATH)
{
    cout << "segmentation success!" << endl;
}

vector<string> WordSegmentation::operator()(const string str)
{
    vector<string> words;
    vector<string> word;
    //_jieba.CutAll(str, words);FullSegment
    _jieba.Cut(str, words, true);
    vector<string>::iterator it = words.begin();
    while(it != words.end())
    {
        if((*it).length() != 1)
            word.push_back(*it);
        it++;
    }
    return word;
}


bool compare_info(const docinfo& a,const docinfo & b)
{
    return a.docid > b.docid;
}
//class InvertedIndex
//建立倒排索引
InvertedIndex::InvertedIndex()
{}


//递归处理文件，保存路径和url
void InvertedIndex::make_url_to_vector(string path)
{
    DIR* dir = opendir(path.c_str());
    dirent* p = NULL;
    //递归遍历
    while((p = readdir(dir)) != NULL)
    {
        //d_type: 8是文件 ，4是目录
        if(p->d_type == 8)
        {
            string file_url = p->d_name;
            _file_path.push_back(path + "/" + file_url);
            if(file_url[0] == '-')
            {
               file_url[0] = '?';
               file_url.pop_back();
               file_url.pop_back();
               file_url.pop_back();
               file_url.pop_back();
            }
            file_url = path + "/" + file_url;
            _url.push_back(file_url.substr(28));
        }
        //过滤linux目录中"."和".."隐藏文件
        //d_name是一个char数组，存放当前遍历到的文件名
        else if(p->d_name[0] != '.')
        {
            string file_path = path + "/" + string(p->d_name);
            make_url_to_vector(file_path);
        }
    }
    closedir(dir);
}


//正排索引，倒排索引，序列化
int InvertedIndex::forward_index()
{
    //正排索引，docid->单词集合
    unordered_map<int, vector<string>> forward_hash;
    WordSegmentation words;
    vector<string> word_vector;
    //遍历文档，处理每个单词
    for(int i=0;i<_file_path.size();i++)
    {
        std::ifstream in(_file_path[i]);
        cout<<_file_path[i]<<endl;
        string line;

        vector<string>::iterator it_word;

        if(in)
        {
            while (getline (in, line))
            {
                //结巴分词，返回单词vec
                word_vector = words(line);
                if(!word_vector.empty())
                {
                    it_word = word_vector.begin();
                    while(it_word != word_vector.end())
                    {
                        (forward_hash[i]).push_back(*it_word);
                        it_word++;
                    }
                }
            }
        }
        else
        {
            std::cout <<"no such file" << std::endl;
        }
    }


    //倒排索引中，value的值，记录docid和单词出现的次数
    docinfo info;
    //遍历正排索引，创建倒排索引
    //单词 -- 文章标号,出现次数
    auto it_forward = forward_hash.begin();
    while(it_forward != forward_hash.end())
    {
        auto it_word_vector = (it_forward->second).begin();
        while(it_word_vector != (it_forward->second).end())
        {
            //判断当前单词是否在hash表中
            auto it_inverted_exist = _inverted_index.find(*it_word_vector);
            //不存在，新增k-v
            if((it_inverted_exist == _inverted_index.end()))
            {
                info.docid = it_forward->first;
                (_inverted_index[*it_word_vector]).push_back(info);
            }
            //存在
            else
            {
                //判断单词是否在同一片文章中
                //不同文档，新增k-v
                if(it_forward->first != ((it_inverted_exist->second).back()).docid)
                {
                    info.docid = it_forward->first;
                    (_inverted_index[*it_word_vector]).push_back(info);
                }
                //同一文档，次数++
                else
                {
                    (it_inverted_exist->second).back().times++;
                }

            }
            it_word_vector++;
        }
        ++it_forward;
    }


    //序列化
    inverm::invered_hash invered_hash;
    auto it_inver = _inverted_index.begin();
    while(it_inver != _inverted_index.end())
    {
        auto* index = invered_hash.add_index();
        index->set_key(it_inver->first);
        auto it_vector = (it_inver->second).begin();
        while(it_vector != (it_inver->second).end())
        {
            auto* doc_info = index->add_docid_vector();
            doc_info->set_docid((*it_vector).docid);
            doc_info->set_times((*it_vector).times);
            it_vector++;
        }
        it_inver++;
    }


    ofstream file_inver("/root/git/SearchEngine/api/proto/index/index.pro.db", ios::binary);
    if(file_inver)
    {
        cout<<"序列化success"<<endl;
    }
    string file_str_inver;
    if (!invered_hash.SerializeToString(&file_str_inver))
    {
        cerr << "Failed to write msg." << endl;
        return -1;
    }
    file_inver.write(file_str_inver.data(),file_str_inver.size());
    file_inver.close();


    return 0;
}

//反序列化,倒排hash保存在对象成员变量中
void InvertedIndex::creat_inverted_index()
{
    docinfo info;
    inverm::invered_hash hash;
    string path = "/root/git/SearchEngine/api/proto/index/index.pro.db";
    ifstream file(path.c_str(), ios::binary);
    string content;


    file.seekg(0, file.end);
    int length = file.tellg();
    file.seekg(0, file.beg);
    content.resize(length + 1);
    file.read(const_cast<char*>(content.data()), length);
    file.close();

    if(hash.ParseFromString(content))
    {
        cerr<<"Failed to parse address bool"<<endl;
    }

    for(int i = 0;i<hash.index_size();++i)
    {
        auto msg = hash.index(i);
        for(int j = 0;j<msg.docid_vector_size();++j)
        {
            info.docid = (msg.docid_vector(j)).docid();
            info.times = (msg.docid_vector(j)).times();
            _inverted_index[msg.key()].push_back(info);
        }
    }

}

//获取url,多个单词结果取交集，按一定规则排序
vector<int> InvertedIndex::get_docid(const string& word)
{
    WordSegmentation words;
    vector<vector<docinfo>> url_v_v;
    vector<docinfo> url;
    //对参数分词,每个单词对应一个vec放入二维vec中
    vector<string> word_vector = words(word);
    for(auto w : word_vector)
    {
        url = _inverted_index[w];
        url_v_v.push_back(url);
    }

    //交集集合
    vector<int> docid;
    //选择一组倒排项中的每个单词和其他组进行比较
    //如果每组都有，向交集中加入
    int flag = 1;
    for(auto url_comp : url)
    {
        for(auto url_v : url_v_v)
        {
            if(find(url_v.begin(), url_v.end(), url_comp) == url_v.end())
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            docid.push_back(url_comp.docid);
        }
        flag = 1;
    }
    //排序


    return docid;
}

void InvertedIndex::creat_pages(const string& word, vector<page_struct>& pages)
{
    WordSegmentation words;
    vector<string> word_vector = words(word);
    vector<int> docid = get_docid(word);
    //int nums = docid.size();
    //if(nums <= 0)
    //{
    //    //没有匹配到
    //}
    //else if(nums < 10)
    //{
    //    //只有一个页面
    //    nums = 1;
    //}
    //else
    //{
    //    nums = nums / 10;   //一页展示是个记录
    //    if(nums > 10)
    //        nums = 10;     //最多展示十页
    //}

    //记录标题内容路径，写入结构体
    page_struct page;
    string title;
    string content;
    string url;
    vector<string> path;
    //string temp = 0;  //标识文章
    //string rep = 0;   //标识替换内容
    //string path_i = "";
    //string title_i = "";
    //string url_i = "";
    //string content_i = "";
    for(int i = 0;i<docid.size();i++)
    {
        //暂时最多展示十页
        if(i >= 100)
        {
            break;
        }
        //获取url和path
        //url.push_back(_url[docid[i]]);
        path.push_back(_file_path[docid[i]]);
        //for test
        //cout<<url[i]<<endl;
        //根据path获取文章标题和内容
        ifstream read(path[i].c_str());
        //todo 通过html页面提取标题
        getline(read, title);
        getline(read, title);
        if(title[title.length() - 1] == '>' || title.length() < 3)
        {
            getline(read, title);
            while(title.length() < 3)
            {
                getline(read, title);
            }
        }
        while(getline(read, content))
        {
            if(content.find(word_vector[0]) != string::npos)
            {
                break;
            }
        }
        page.title = title;
        page.content = content;
        page.url = _url[docid[i]];
        pages.push_back(page);
        read.close();

        //temp = to_string(i / 10);
        //rep = to_string(i % 10);

        //path_i = "/root/git/SearchEngine/server/wwwroot/template/" + temp + "temp.html";
        //ctemplate::TemplateDictionary dict(" ");
        //dict.SetValue("url",url[0]);
        //std::string output;
        //ctemplate::ExpandTemplate("./wwwroot/template/temp.html", ctemplate::DO_NOT_STRIP, &dict, &output);


        //ofstream write;
        //write.open("/root/git/SearchEngine/server/wwwroot/template/temp1.html", ios::app);
        //write << "hahahahh" << endl;
        //write.close();
    }
}
