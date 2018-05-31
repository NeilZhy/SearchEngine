#include "cppjieba/Jieba.hpp"
#include <fstream>
//#include "WordSegmentation.hpp"

using namespace std;

//词典的路径信息
const char* const DICT_PATH = "/usr/local/src/cppjieba/dict/jieba.dict.utf8";
const char* const HMM_PATH = "/usr/local/src/cppjieba/dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "/usr/local/src/cppjieba/dict/user.dict.utf8";
const char* const IDF_PATH = "/usr/local/src/cppjieba/dict/idf.utf8";
const char* const STOP_WORD_PATH = "/usr/local/src/cppjieba/dict/stop_words.utf8";


int main(int argc, char** argv)
{

//    WordSegmentation jiebaword;
//    vector<string> words = jiebaword("我们是一家人！");
  cppjieba::Jieba jieba(DICT_PATH,
        HMM_PATH,
        USER_DICT_PATH,
        IDF_PATH,
        STOP_WORD_PATH);
  vector<string> words;
  //vector<cppjieba::Word> jiebawords;
  string s;
  //string result;


  std::ifstream in("./0.replace");
  if(!in)
  {
      cout<<"出错了，文件没有打开"<<endl;
  }
  while(getline(in,s))
  {
      //s = "他来到了网易杭研大厦";
      if(s == " ")
          continue;
      //cout << s << endl;
      jieba.Cut(s, words, true);
      //cout << limonp::Join(words.begin(), words.end(), "/") << endl;
      //cout<<words<<endl;
      vector<string>::iterator it = words.begin();
      //while(it != words.end())
      //{
      //    cout<<*it<<" ";
      //    it++;
      //}
  }
  return 0;
}
