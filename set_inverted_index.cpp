#include <fstream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <dirent.h>//遍历系统指定目录下文件要包含的头文件  

#include "boost/regex.hpp"
#include "cppjieba/Jieba.hpp"

#include "proto/forward.pb.h"
#include "proto/inverted.pb.h"


using namespace std;


//cppjieba -- 词典的路径信息
const char* const DICT_PATH = "/usr/local/src/cppjieba/dict/jieba.dict.utf8";
const char* const HMM_PATH = "/usr/local/src/cppjieba/dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "/usr/local/src/cppjieba/dict/user.dict.utf8";
const char* const IDF_PATH = "/usr/local/src/cppjieba/dict/idf.utf8";
const char* const STOP_WORD_PATH = "/usr/local/src/cppjieba/dict/stop_words.utf8";


void List(const string& path)
{
    DIR* dir = opendir(path.c_str());//打开指定目录
    dirent* p = NULL;//定义遍历指针
    while((p = readdir(dir)) != NULL)//开始逐个遍历
    {
        if(p->d_type == 8)    //d_type: 8是文件 ，4是目录
        {
            string name = p->d_name;
            if(name[0] == '-')
            {
                name[0] = '?';
                name.pop_back();
                name.pop_back();
                name.pop_back();
                name.pop_back();
            }
            cout<<path<<"/"<<name<<endl;
        }
        //这里需要注意，linux平台下一个目录中有"."和".."隐藏文件，需要过滤掉
        else if(p->d_name[0] != '.')//d_name是一个char数组，存放当前遍历到的文件名
        {
            string name = path + "/" + string(p->d_name);
            //cout<<name<<endl;
            List(name);
        }
    }
    closedir(dir);//关闭指定目录
}

    //List("/root/github/SearchEngine/www.boost.org");

//cppjieba
class WordSegmentation//使用结巴分词库进行分词
{
    public:
        WordSegmentation()
            : _jieba(DICT_PATH
                    , HMM_PATH
                    , USER_DICT_PATH
                    , IDF_PATH
                    , STOP_WORD_PATH)//初始化Jieba类对象
        {
            cout << "cppjieba init!" << endl;
        }

        vector<string> operator()(const string str)//返回str的分词结果
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
    private:
        cppjieba::Jieba _jieba;
};


//建立倒排索引
class InvertedIndex
{
    public:
        InvertedIndex(const std::string old_path = "",const std::string new_path = "")
            :_old_path(old_path)
            ,_new_path(new_path)
        {}

        ~InvertedIndex()
         {}

        //去除标签
        int DetTag()
        {
            if(_old_path == "" || _new_path == "")
            {
                return -1;
            }

            int i = 0;
            std::string file_name = ".html";
            std::string replace_name = ".replace";
            for(i = 0;i <=9;i++)
            {
                file_name = std::to_string(i) + file_name;
                replace_name = std::to_string(i) + replace_name;
                std::ifstream in(_old_path + file_name);
                std::ofstream out(_new_path + replace_name);
                file_name = ".html";
                replace_name = ".replace";
                std::string string_result;
                std::string filename;
                std::string line;
                std::string fmt = " ";

                //boost::regex regexstr1("<script[^>]*?>.*?</script>");                            //去标签
                boost::regex regexstr2("<[^>]*>");                            //去标签
                boost::regex regexstr3("&(lt|#60);");                         //去lt
                boost::regex regexstr4("&(gt|#62);");                         //去gt
                boost::regex regexstr5("&(nbsp|#160);");                      //去nbsp

                if(in) // 有该文件
                {
                    while (getline (in, line)) // line中不包括每行的换行符
                    {
                        if(line == "<script>")
                        {
                            while(getline(in, line))
                            {
                                if(line == "</script>")
                                    break;
                            }
                        }
                        //line = boost::regex_replace(line, regexstr1, fmt);
                        line = boost::regex_replace(line, regexstr2, fmt);
                        line = boost::regex_replace(line, regexstr3, fmt);
                        line = boost::regex_replace(line, regexstr4, fmt);
                        line = boost::regex_replace(line, regexstr5, fmt);
                        out << line<<std::endl;
                    }
                }
                else // 没有该文件
                {
                    std::cout <<"no such file" << std::endl;
                }
            }
            return 0;
        }

        //处理每一个文件，将结果记录在哈希表中，哈希表中记录的结果包括
        //int forward_index(string file_name,lm::forward_hash& hash,inverm::invered_hash& invered_hash)   //在递归中，将结果保存在哈希表中,然后在递归的外面统一的将序列化的结果放在文件中
        int forward_index()
        {

            int i = 0;
            lm::forward_hash hash;
            vector<lm::Str> Str_vector;   //这里定义Str_vector的原因是，为了下面给哈希表中的数据赋值
            lm::Str str;
            unordered_map<int, vector<string>> forward_hash;  //正排索引，文章编号->该文件的所有的单词
            WordSegmentation words;   //分词之后排除标点.空格,创建用于分词的对象
            vector<string> word_vector;
            std::string replace_name = ".replace";
            for(i = 0;i <=9;i++)
            {
                auto* index = hash.add_index();
                index->set_key(i);
                replace_name = std::to_string(i) + replace_name;
                std::ifstream in(_new_path + replace_name);
                replace_name = ".replace";
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


                //将正排索引序列化之后的数据写入到文件中
                ofstream file("./proto/index/log", ios::binary);
                string file_str;
                if (!hash.SerializeToString(&file_str))    //序列化结构体的时候，只需要序列化大的就OK了
                {
                    cerr << "Failed to write msg." << endl;
                    return -1;
                }
                file.write(file_str.data(),file_str.size());
                file.close();

                //进行倒排索引  关键词 -- 文章标号 哈希表中存储
                unordered_map<string, vector<int>> inverted_index;
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
                        auto it_inverted = inverted_index.find(*it_vector);   //倒排索引,记录所要查找的单词是否存在的迭代器
                        if((it_inverted == inverted_index.end()))
                        {
                            //如果不存在，直接将结果放进去就好了
                            (inverted_index[*it_vector]).push_back(it_forward->first);
                        }
                        else
                        {
                            //如果哈希表中已经存在那个key了，这个时候判断vector中是否有要插入的数据
                            if((find((it_inverted->second).begin(),(it_inverted->second).end(),it_forward->first)) == (it_inverted->second).end())
                                (inverted_index[*it_vector]).push_back(it_forward->first);

                        }
                        it_vector++;
                    }
                    ++it_forward;
                }


                //根据正排索引的结果，建立倒排索引
                inverm::invered_hash invered_hash;
                auto it_inver = inverted_index.begin();
                while(it_inver != inverted_index.end())
                {
                    auto* index = invered_hash.add_index();
                    index->set_key(it_inver->first);
                    auto it_vector = (it_inver->second).begin();
                    while(it_vector != (it_inver->second).end())
                    {
                        auto* docid = index->add_docid_vector();
                        docid->set_docid(*it_vector);
                        it_vector++;
                    }
                    it_inver++;
                }

                ofstream file_inver("./proto/index/loginver", ios::binary);
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
            }
            return 0;
        }




    private:
        std::string _old_path;
        std::string _new_path;
};

int main()
{
    InvertedIndex index("./htmlsource/", "./del_tag_html/");
    index.DetTag();
    index.forward_index();

    return 0;
}


