#include <fstream>
#include <string>
#include <iostream>
#include <regex>


int main()

{
    std::ifstream in("map.htm");
    std::ofstream out("mapreplace.htm");
    //std::ofstream out("mapreplaces.htm");
    std::string string_result;
    std::string filename;
    std::string line;
    std::string fmt = " ";
    //std::regex regexstr1("<script[^>]*?>.*?</script>");
    //<script\s*.*?</script>
    //std::regex regexstr1("/<script\b[^<]*(?:(?!</script>)<[^<]*)*</script>/gi");
    //std::regex regexstr1("<script[^>]*?>[\\s\\S]*?<\\/script>");
    //<\\s*script[^>]*>((?!</?\\s*script\\s*)(\n|.))*</\\s*script\\s*>
    //(?s)<script.*?>.*?</script>
    ///^\<[a-zA-Z]+\>.*\<\/[a-zA-Z]+\>$/
    //   /^\<[a-zA-Z]+\>.*\<\/[a-zA-Z]+\>$/
    std::regex regexstr1("/^<[a-zA-Z]+>.*</[a-zA-Z]+>$/");
    std::regex regexstr2("<[^>]*>");
    std::regex regexstr3("&(lt|#60);");
    std::regex regexstr4("&(gt|#62);");
    std::regex regexstr5("&(nbsp|#160);");
    //<script[^>]*?>.*?</script>

    if(in) // 有该文件
    {
        while (getline (in, line)) // line中不包括每行的换行符
        {
            line = std::regex_replace(line, regexstr1, fmt);
            line = std::regex_replace(line, regexstr2, fmt);
            line = std::regex_replace(line, regexstr3, fmt);
            line = std::regex_replace(line, regexstr4, fmt);
            line = std::regex_replace(line, regexstr5, fmt);
            out << line << std::endl;
        }
    }
    else // 没有该文件
    {
        std::cout <<"no such file" << std::endl;
    }

    return 0;
}


