//#include <iostream>
//#include <unordered_map>
//#include <vector>
//#include <string>
//using namespace std;

//哈希
//int main()
//{
//    unordered_map<int, vector<string>> hash;
//    vector<string> vs;
//    vs.push_back("aaaa");
//    //std::pair<int,vector<string>> ha (1,vs);
//    //hash.insert(ha);
//    hash[1].push_back("bbbbbbbbbbbbb");
//    vector<string> a = hash[1];
//    cout<<a[0]<<endl;
//    //hash.insert(std::make_pair<int, vector<string>>(1,vs));
//    //myre.insert (std::make_pair<std::string,double>("eggs",6.0));
//    //cout<<hash[1].second[0]<<endl;
//    return 0;
//}


#include <dirent.h>//遍历系统指定目录下文件要包含的头文件  
#include <iostream>  
using namespace std;  
  

void List(const string path)
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

int main()  
{  
    List("/root/github/SearchEngine/www.boost.org");
    return 0;
} 


//#include <stdio.h>  
//#include <dirent.h>  
//#include <string.h>  
//  
//void List(char *path)  
//{  
//    struct dirent *ent = NULL;  
//    DIR *pDir;  
//    if((pDir = opendir(path)) != NULL)  
//    {  
//        while(NULL != (ent = readdir(pDir)))  
//        {  
//            if(ent->d_type == 8)                 // d_type：8-文件，4-目录  
//                printf("File:\t%s\n", ent->d_name);  
//            else if(ent->d_name[0] != '.')  
//            {  
//                printf("\n[Dir]:\t%s\n", ent->d_name);  
//                List(ent->d_name);                   // 递归遍历子目录  
//                printf("返回[%s]\n\n", ent->d_name);  
//            }  
//        }  
//        closedir(pDir);  
//    }  
//    else  
//        printf("Open Dir-[%s] failed.\n", path);  
//}  
//  
//int main()   
//{           
//    char path[] = "/root/github/SearchEngine/www.boost.org";  
//    List(path);  
//  
//    return 0;   
//}  
