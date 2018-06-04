#ifndef SET_INVERTED_INDEX_H
#define SET_INVERTED_INDEX_H

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



//cppjieba
class WordSegmentation//使用结巴分词库进行分词
{
    public:
        WordSegmentation();
        vector<string> operator()(const string str);    //返回str的分词结果
    private:
        cppjieba::Jieba _jieba;
};

class AA
{
    public:
        AA()
        {}
        int bb();
};

class InvertedIndex
{
    public:
        InvertedIndex();
        void make_url_to_vector(string path);
        int forward_index();
        vector<string> get_docid(const string& word);


    private:
        vector<string> _url;                                //用户保存url
        vector<string> _file_path;                          //用于保存文件路径
        unordered_map<string, vector<int>> _inverted_index; //用于存在倒排索引 单词 -> docid数组
};

#endif