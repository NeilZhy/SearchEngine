#include <fstream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "boost/regex.hpp"
#include "cppjieba/Jieba.hpp"


using namespace std;


//cppjieba -- 词典的路径信息
const char* const DICT_PATH = "/usr/local/src/cppjieba/dict/jieba.dict.utf8";
const char* const HMM_PATH = "/usr/local/src/cppjieba/dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "/usr/local/src/cppjieba/dict/user.dict.utf8";
const char* const IDF_PATH = "/usr/local/src/cppjieba/dict/idf.utf8";
const char* const STOP_WORD_PATH = "/usr/local/src/cppjieba/dict/stop_words.utf8";


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

        int forward_index()
        {

            int i = 0;
            unordered_map<int, vector<string>> forward_hash;
            WordSegmentation words;   //分词之后排除标点.空格
            vector<string> word_vector;
            std::string replace_name = ".replace";
            for(i = 0;i <=9;i++)
            {
                replace_name = std::to_string(i) + replace_name;
                std::ifstream in(_new_path + replace_name);
                replace_name = ".replace";
                string line;

                vector<string>::iterator it;

                if(in) // 有该文件
                {
                    while (getline (in, line)) // line中不包括每行的换行符
                    {
                        word_vector = words(line);
                        //vector<string> vs;
                        //pair<int, vector<string>> in_hash(i, vs);
                        //forward_hash.insert(in_hash);
                        if(!word_vector.empty())
                        {
                            it = word_vector.begin();
                            while(it != word_vector.end())
                            {
                                //cout<<(*it)<<endl;
                                (forward_hash[i]).push_back(*it);
                                it++;
                            }
                        }
                    }
                }
                else // 没有该文件
                {
                    std::cout <<"no such file" << std::endl;
                }


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


