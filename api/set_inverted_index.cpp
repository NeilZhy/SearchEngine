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


//处理每一个文件，将结果记录在哈希表中，哈希表中记录的结果包括
//int forward_index(string file_name,lm::forward_hash& hash,inverm::invered_hash& invered_hash)   //在递归中，将结果保存在哈希表中,然后在递归的外面统一的将序列化的结果放在文件中
int InvertedIndex::forward_index()
{

    lm::forward_hash hash;
    vector<lm::Str> Str_vector;   //这里定义Str_vector的原因是，为了下面给哈希表中的数据赋值
    lm::Str str;
    unordered_map<int, vector<string>> forward_hash;  //正排索引，文章编号->该文件的所有的单词
    WordSegmentation words;   //分词之后排除标点.空格,创建用于分词的对象
    vector<string> word_vector;
    std::string replace_name = ".replace";
    for(int i=0;i<_file_path.size();i++)
    {
    auto* index = hash.add_index();
    index->set_key(i);
    std::ifstream in(_file_path[i]);
    cout<<_file_path[i]<<endl;
    string line;


    vector<string>::iterator it;

    if(in) // 有该文件
    {
        while (getline (in, line)) // line中不包括每行的换行符
        {
            word_vector = words(line);  //调用结巴分词，word_vector中放置的是一个个单词
            //vector<string> vs;
            //pair<int, vector<string>> in_hash(i, vs);
            //forward_hash.insert(in_hash);
            if(!word_vector.empty())
            {
                it = word_vector.begin();
                while(it != word_vector.end())
                {
                    //cout<<(*it)<<endl;
                    auto* Str_vector = index->add_value_vector(); 
                    str.set_str(*it);
                    *Str_vector = str;
                    (forward_hash[i]).push_back(*it);    //将分词放入到了哈希表中
                    it++;
                }
            }
        }
    }
    else // 没有该文件
    {
        std::cout <<"no such file" << std::endl;
    }



    //进行倒排索引  关键词 -- 文章标号 哈希表中存储
    auto it_forward = forward_hash.begin();
    while(it_forward != forward_hash.end())
    {
        auto it_vector = (it_forward->second).begin();  //it_vector是正排索引中，对应的vector<string>迭代器
        while(it_vector != (it_forward->second).end())
        {
            //判断当前的string是否存在正排索引的哈希表中，如果不在就加入，单词作为key，文章标号作为value
            //当前处理只是将文章的标号加入了，当一个词出现多次的时候，并没有统计出来
            //需要考虑的情况有，一篇文章中一个单词出现了多次，这个时候只记录一个标号
            //如果在不同的文章中出现了同一个单词，下面的这个方式是不会加入新的文章标号的
            auto it_inverted = _inverted_index.find(*it_vector);   //倒排索引,记录所要查找的单词是否存在的迭代器
            if((it_inverted == _inverted_index.end()))
            {
                //如果不存在，直接将结果放进去就好了
                (_inverted_index[*it_vector]).push_back(it_forward->first);
            }
            else
            {
                //如果哈希表中已经存在那个key了，这个时候判断vector中是否有要插入的数据
                if((find((it_inverted->second).begin(),(it_inverted->second).end(),it_forward->first)) == (it_inverted->second).end())
                    (_inverted_index[*it_vector]).push_back(it_forward->first);

            }
            it_vector++;
        }
        ++it_forward;
    }



    ////根据倒排索引的结果，进行序列化，然后写入到文件中
    //inverm::invered_hash invered_hash;
    //auto it_inver = _inverted_index.begin();
    //while(it_inver != _inverted_index.end())
    //{
    //    auto* index = invered_hash.add_index();
    //    index->set_key(it_inver->first);
    //    auto it_vector = (it_inver->second).begin();
    //    while(it_vector != (it_inver->second).end())
    //    {
    //        auto* docid = index->add_docid_vector();
    //        docid->set_docid(*it_vector);
    //        it_vector++;
    //    }
    //    it_inver++;
    //}

    //ofstream file_inver("./proto/index/loginver", ios::binary);
    //string file_str_inver;
    //if (!invered_hash.SerializeToString(&file_str_inver))    //序列化结构体的时候，只需要序列化大的就OK了
    //{
    //    cerr << "Failed to write msg." << endl;
    //    return -1;
    //}
    //file_inver.write(file_str_inver.data(),file_str_inver.size());
    //file_inver.close();



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
    }
    return 0;
}


vector<string> InvertedIndex::get_docid(const string& word)
{
    vector<int> url = _inverted_index[word];
    vector<string> stringurl;
    for(int i = 0;i<url.size();i++)
    {
        cout<<_url[url[i]]<<endl;
        stringurl.push_back(_url[url[i]]);
    }
    return stringurl;
}







