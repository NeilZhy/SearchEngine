#include <fstream>
#include <string>
#include <iostream>
#include <regex>

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

            //std::string commond = "cd ./htmlsource\nremame 's/ /_/g' *\ncd ..\ni=0\nfor x in `ls ./htmlsource`\ndo\n\tmv './htmlsource/$x' './htmlsource/$i.html'\n\t((i++))\ndone";
            //system(commond.c_str());

            int i = 0;
            std::string file_name = ".html";
            std::string replace_name = ".replace";
            for(i = 0;i <=9;i++)
            {
                file_name = std::to_string(i) + file_name;
                replace_name = std::to_string(i) + replace_name;
                std::cout<<file_name<<std::endl;
                std::ifstream in(_old_path + file_name);
                std::ofstream out(_new_path + replace_name);
                file_name = ".html";
                replace_name = ".replace";
                //std::ofstream out("mapreplaces.htm");
                std::string string_result;
                std::string filename;
                std::string line;
                std::string fmt = " ";
                //std::regex regexstr1("/^<[a-zA-Z]+>.*</[a-zA-Z]+>$/");      //去脚本
                std::regex regexstr2("<[^>]*>");                            //去标签
                std::regex regexstr3("&(lt|#60);");                         //去lt
                std::regex regexstr4("&(gt|#62);");                         //去gt
                std::regex regexstr5("&(nbsp|#160);");                      //去nbsp
                std::regex regexstr6("/[\r\n]/g");
                //<script[^>]*?>.*?</script>

                if(in) // 有该文件
                {
                    while (getline (in, line)) // line中不包括每行的换行符
                    {
                        //line = std::regex_replace(line, regexstr1, fmt);
                        if(line == "<script>")
                        {
                            while(getline(in, line))
                            {
                                if(line == "</script>")
                                    break;
                            }
                        }
                        line = std::regex_replace(line, regexstr2, fmt);
                        line = std::regex_replace(line, regexstr3, fmt);
                        line = std::regex_replace(line, regexstr4, fmt);
                        line = std::regex_replace(line, regexstr5, fmt);
                        line = std::regex_replace(line, regexstr6, fmt);
                        out << line << std::endl;
                    }
                }
                else // 没有该文件
                {
                    std::cout <<"no such file" << std::endl;
                }
            }
            return 0;
        }

    private:
        std::string _old_path;
        std::string _new_path;
};

int main()
{
    InvertedIndex index("./htmlsource/", "./htmlsource_rep/");
    index.DetTag();
    return 0;
}


