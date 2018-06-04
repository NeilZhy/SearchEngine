#include "set_inverted_index.h"


//class cppjieba
WordSegmentation::WordSegmentation()
    : _jieba(DICT_PATH
            , HMM_PATH
            , USER_DICT_PATH
            , IDF_PATH
            , STOP_WORD_PATH)//初始化Jieba类对象
{
    cout << "cppjieba init!" << endl;
}

vector<string> WordSegmentation::operator()(const string str)//返回str的分词结果
{
    vector<string> words;
    vector<string> word;
    //_jieba.CutAll(str, words);//FullSegment
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

int AA::bb()
{
    cout<<"aaaaaaaaaa"<<endl;
}

//class InvertedIndex
//建立倒排索引
InvertedIndex::InvertedIndex()
    {}


//递归处理文件，将文件的url放在了vector中，这里的下标就是docid
void InvertedIndex::make_url_to_vector(string path)
{
    DIR* dir = opendir(path.c_str());//打开指定目录
    dirent* p = NULL;//定义遍历指针
    while((p = readdir(dir)) != NULL)//开始逐个遍历
    {
        if(p->d_type == 8)    //d_type: 8是文件 ，4是目录
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
        //这里需要注意，linux平台下一个目录中有"."和".."隐藏文件，需要过滤掉
        else if(p->d_name[0] != '.')//d_name是一个char数组，存放当前遍历到的文件名
        {
            string file_path = path + "/" + string(p->d_name);
            //cout<<name<<endl;
            make_url_to_vector(file_path);
        }
    }
    closedir(dir);//关闭指定目录
}


//先建立正排索引，再建立倒排索引，然后序列化，将结果保存在文件中



//处理每一个文件，将结果记录在哈希表中，哈希表中记录的结果包括
//int forward_index(string file_name,lm::forward_hash& hash,inverm::invered_hash& invered_hash)   //在递归中，将结果保存在哈希表中,然后在递归的外面统一的将序列化的结果放在文件中
int InvertedIndex::forward_index()
{

    unordered_map<int, vector<string>> forward_hash;  //正排索引，文章编号->该文件的所有的单词
    WordSegmentation words;   //分词之后排除标点.空格,创建用于分词的对象
    vector<string> word_vector;
    //在for循环中，每次解析一篇文章
    //第一个while中，每次获取一个文章中的一行字符串进行jieba分词，获取一个分词的列表
    //第二个while循环中，是将分词的结果放在了哈希表中
    int n = 0;
    for(int i=0;i<_file_path.size();i++)   //这里是类的成员变量，在调用forward_index之前，一定要先处理文件，将文件的的url和文件的绝对路径 放在了vector中
    {
        std::ifstream in(_file_path[i]);
        cout<<_file_path[i]<<endl;
        string line;

        vector<string>::iterator it_word;

        if(in) // 有该文件
        {
            while (getline (in, line)) // line中不包括每行的换行符
            {
                word_vector = words(line);  //调用结巴分词，word_vector中放置的是一个个单词
                if(!word_vector.empty())
                {
                    it_word = word_vector.begin();
                    while(it_word != word_vector.end())
                    {
                        (forward_hash[i]).push_back(*it_word);    //将分词放入到了哈希表中
                        it_word++;
                    }
                }
            }
        }
        else // 没有该文件
        {
            std::cout <<"no such file" << std::endl;
        }
        n++;
    }

    cout<<"             总共的文件数是       "<<n<<endl;
    n = 0;

    docinfo info;   //倒排索引中，value的值，记录docid和该单词出现的次数
    //进行倒排索引  关键词 -- 文章标号 哈希表中存储
    //第一个while是遍历正排中的所有docid
    //第二个while是遍历每个docid对应的单词
    auto it_forward = forward_hash.begin();
    while(it_forward != forward_hash.end())
    {
        n++;
        auto it_word_vector = (it_forward->second).begin();  //it__word_vector是正排索引中，对应的vector<string>迭代器
        while(it_word_vector != (it_forward->second).end())
        {
            //判断当前的string是否存在倒排索引的哈希表中，如果不在就加入，单词作为key，文章标号作为value
            //当前处理只是将文章的标号加入了，当一个词出现多次的时候，并没有统计出来
            //需要考虑的情况有，一篇文章中一个单词出现了多次，这个时候只记录一个标号
            //如果在不同的文章中出现了同一个单词，下面的这个方式是不会加入新的文章标号的
            //
            auto it_inverted_exist = _inverted_index.find(*it_word_vector);   //判断当前单词是否存在倒排哈希表中
            if((it_inverted_exist == _inverted_index.end()))    //当前单词不存在与倒排哈希表中
            {
                //不存在，确定对应的哈希word，然后将文章的标号放入到哈希表的value位置
                info.docid = it_forward->first;
                (_inverted_index[*it_word_vector]).push_back(info);
            }
            else  //当前单词已经存在于哈希表中
            {
                //如果哈希表中已经存在那个key了，判断这个单词是不是在同一片文章中出现的，如果是同一篇文章中的，就直接在文章编号的地方加1就好
                if(it_forward->first != ((it_inverted_exist->second).back()).docid)
                {
                    info.docid = it_forward->first;
                    (_inverted_index[*it_word_vector]).push_back(info);
                }
                else
                {
                    (it_inverted_exist->second).back().times++;
                }

            }
            it_word_vector++;
        }
        ++it_forward;
    }

    cout<<"          建立哈希的值是  "<<n<<endl;
    n = 0;

    //根据倒排索引的结果，进行序列化，然后写入到文件中
    inverm::invered_hash invered_hash;
    auto it_inver = _inverted_index.begin();
    while(it_inver != _inverted_index.end())
    {
        n++;
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

    cout<<"             序列化的个数是       "<<n<<endl;

    ofstream file_inver("/root/git/SearchEngine/api/proto/index/index.pro.db", ios::binary);
    if(file_inver)
    {
        cout<<"序列化success"<<endl;
    }
    string file_str_inver;
    if (!invered_hash.SerializeToString(&file_str_inver))    //序列化结构体的时候，只需要序列化大的就OK了
    {
        cerr << "Failed to write msg." << endl;
        return -1;
    }
    file_inver.write(file_str_inver.data(),file_str_inver.size());
    file_inver.close();



    ////for test 查看是否成功将数据放在了哈希中
    //unordered_map<int, vector<string>>::iterator map_it = forward_hash.begin();
    //while(map_it != forward_hash.end())
    //{
    //    vector<string> vs = (*map_it).second;
    //    vector<string>::iterator st_it = vs.begin();
    //    while(st_it != vs.end())
    //    {
    //        cout<<(*st_it)<<endl;
    //        st_it++;
    //    }
    //    map_it++;
    //}

    return 0;
}

//反序列化
//将结果保存了类的对象的成员变量中
//这里将序列化程序单独的运行，然后启动服务的时候，才会调用反序列化，直接读取文件就可

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

    cout<<"      反序列的word是"<<hash.index_size()<<endl;

}

vector<string> InvertedIndex::get_docid(const string& word)
{
    vector<docinfo> url = _inverted_index[word];
    vector<string> stringurl;
    for(int i = 0;i<url.size();i++)
    {
        cout<<_url[url[i].docid]<<endl;
        stringurl.push_back(_url[url[i].docid]);
    }
    return stringurl;
}


