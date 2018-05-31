//这里是把分词给封装 起来了

#ifndef _MY_WORD_SEGMENTATION_H_
#define _MY_WORD_SEGMENTATION_H_
#include "cppjieba/Jieba.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using std::cout;
using std::endl;
using std::string;
using std::vector;

//const char * const DICT_PATH = "/home/long361/jieba/cppjieba/dict/jieba.dict.utf8";//最大概率法(MPSegment: Max Probability)分词所使用的词典路径
//const char * const HMM_PATH = "/home/long361/jieba/cppjieba/dict/hmm_model.utf8";//隐式马尔科夫模型(HMMSegment: Hidden Markov Model)分词所使用的词典路径
//const char * const USER_DICT_PATH = "/home/long361/jieba/cppjieba/dict/user.dict.utf8";//用户自定义词典路径
//const char* const IDF_PATH = "/home/long361/jieba/cppjieba/dict/idf.utf8";//IDF路径
//const char* const STOP_WORD_PATH = "/home/long361/jieba/cppjieba/dict/stop_words.utf8";//停用词路径



const char* const DICT_PATH = "/usr/local/src/cppjieba/dict/jieba.dict.utf8";
const char* const HMM_PATH = "/usr/local/src/cppjieba/dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "/usr/local/src/cppjieba/dict/user.dict.utf8";
const char* const IDF_PATH = "/usr/local/src/cppjieba/dict/idf.utf8";
const char* const STOP_WORD_PATH = "/usr/local/src/cppjieba/dict/stop_words.utf8";

class WordSegmentation//使用结巴分词库进行分词
{
    public: WordSegmentation()
            : _jieba(DICT_PATH
                    , HMM_PATH
                    , USER_DICT_PATH
                    ,DF_PATH
                    ,TOP_WORD_PATH)//初始化Jieba类对象
    
        cout << "cppjieba init!" << endl;
    }
    vector<string> operator()(const string str)//返回str的分词结果
    {
        vector<string> words;
        //_jieba.CutAll(str, words);//FullSegment
        _jieba.Cut(str, words, true);
        return words;
    }
    private: cppjieba::Jieba _jieba;
};
#endif
