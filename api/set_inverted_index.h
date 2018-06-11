#ifndef SET_INVERTED_INDEX_H
#define SET_INVERTED_INDEX_H

#include <fstream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <dirent.h> 

#include "boost/regex.hpp"
#include "cppjieba/Jieba.hpp"
#include "proto/inverted.pb.h"

using namespace std;

//cppjieba -- 词典的路径信息
const char* const DICT_PATH = "/usr/local/src/cppjieba/dict/jieba.dict.utf8";
const char* const HMM_PATH = "/usr/local/src/cppjieba/dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "/usr/local/src/cppjieba/dict/user.dict.utf8";
const char* const IDF_PATH = "/usr/local/src/cppjieba/dict/idf.utf8";
const char* const STOP_WORD_PATH = "/usr/local/src/cppjieba/dict/stop_words.utf8";

//倒排索引,记录文章编号，单词出现次数
struct docinfo
{
    docinfo()
        :docid(-1)
        ,times(1)
    {}
    bool operator==(const docinfo& b)
    {
        if((this->docid == b.docid) && (this->times == b.times))
            return true;
        return false;
    }
    int docid;
    int times;
};

struct page_struct
{
    string title;
    string content;
    string url;
};

//cppjieba
class WordSegmentation
{
    public:
        WordSegmentation();
        vector<string> operator()(const string str);
    private:
        cppjieba::Jieba _jieba;
};


class InvertedIndex
{
    public:
        InvertedIndex();
        void make_url_to_vector(string path);
        int forward_index();
        vector<int> get_docid(const string& word);
        void creat_inverted_index();
        //for test
        //这里需要考虑返回值，给外面返回什么东西
        void creat_pages(const string& word, vector<page_struct>& pages);


    private:
        //保存url
        vector<string> _url;
        //保存文件路径
        vector<string> _file_path;
        //倒排索引hash
        unordered_map<string, vector<docinfo>> _inverted_index;
};

#endif
