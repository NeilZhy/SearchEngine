
        ////去除标签
        //int DetTag(const string& old_path)
        //{
        //    if(old_path == "")
        //    {
        //        return -1;
        //    }
        //    string new_path = old_path + "1";

        //    std::ifstream in(old_path);
        //    std::ofstream out(new_path);
        //    std::string line;
        //    std::string fmt = " ";

        //    //boost::regex regexstr1("<script[^>]*?>.*?</script>");                            //去标签
        //    boost::regex regexstr1("<[^>]*>");                            //去标签
        //    boost::regex regexstr2("<script[^>]*?>.*?</script>");                      //去nbsp

        //    boost::regex regexstr3("&(lt|#60);");                         //去lt
        //    boost::regex regexstr4("&(gt|#62);");                         //去gt
        //    boost::regex regexstr5("&(nbsp|#160);");                      //去nbsp
        //    boost::regex regexstr6("&(quot|#34);");                      //去nbsp
        //    boost::regex regexstr7("&(amp|#38);");                      //去nbsp
        //    boost::regex regexstr8("&(iexcl|#161);");                      //去nbsp
        //    boost::regex regexstr9("&(cent|#162);");                      //去nbsp
        //    boost::regex regexstr10("&(pound|#163);");                      //去nbsp
        //    boost::regex regexstr11("&(copy|#169);");                      //去nbsp

        //    boost::regex regexstr12("<style[^>]*?>[\\s\\S]*?<\\/style>");                      //去nbsp
        //    //boost::regex regexstr13("<!-- [^(>)]* -->");                      //去nbsp
        //    boost::regex regexstr13("<!--[^>]*-->");                      //去nbsp
        //    //boost::regex regexstr13("-->");                      //去nbsp
        //    //boost::regex regexstr14("<!--.*");                      //去nbsp
        //    //boost::regex regexstr6("<script[^>]*?>.*?</script>");                      //去nbsp
        //    //boost::regex regexstr7("([\\r\\n])[\\s]+");                      //去nbsp
        //    //boost::regex regexstr16("&#(\\d+);");                      //去nbsp
        //    string replace;
        //    if(in) // 有该文件
        //    {
        //        while (getline (in, line)) // line中不包括每行的换行符
        //        {
        //            replace += line;
        //        }
        //        replace = boost::regex_replace(replace, regexstr1, fmt);
        //        replace = boost::regex_replace(replace, regexstr2, fmt);
        //        replace = boost::regex_replace(replace, regexstr3, fmt);
        //        replace = boost::regex_replace(replace, regexstr4, fmt);
        //        replace = boost::regex_replace(replace, regexstr5, fmt);
        //        replace = boost::regex_replace(replace, regexstr7, fmt);
        //        replace = boost::regex_replace(replace, regexstr8, fmt);
        //        replace = boost::regex_replace(replace, regexstr9, fmt);
        //        replace = boost::regex_replace(replace, regexstr10, fmt);
        //        replace = boost::regex_replace(replace, regexstr11, fmt);
        //        replace = boost::regex_replace(replace, regexstr12, fmt);
        //        replace = boost::regex_replace(replace, regexstr13, fmt);
        //        //replace = boost::regex_replace(replace, regexstr14, fmt);
        //        //replace = boost::regex_replace(replace, regexstr15, fmt);
        //        //replace = boost::regex_replace(replace, regexstr16, fmt);
        //        //replace = boost::regex_replace(replace, regexstr17, fmt);
        //        out << replace<<std::endl;
        //    }
        //    else // 没有该文件
        //    {
        //        std::cout <<"no such file" << std::endl;
        //    }
        //    return 0;
        //}
