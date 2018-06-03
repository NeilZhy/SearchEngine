#include"httpd.h"
#include<iconv.h>
#include<stdlib.h>
#include<string.h>
#include<sys/sendfile.h>
#include<ctype.h>
#include<htmlcxx/html/ParserDom.h>
#include<string>
#include<fstream>
#include<iostream>
#include<io.h>
#include<string>
#include<vector>
#include<sstream>
#include<ctemplate/template.h>

using namespace std;
using namespace htmlcxx;

string replaceALL(string src, const string& target,const string& subs) 
{
    string tmp(src);
    string::size_type pos =tmp.find(target),targetSize =target.size(),resSize =subs.size();  
    while(pos!=string::npos)//found  
    {  
        tmp.replace(pos,targetSize,subs);   
        pos =tmp.find(target, pos + resSize);   
    }  
    return tmp;
}

void print_log(char *msg,int level)
{
#ifdef _STDOUT_
    const char* const level_msg[] =
    {
        "SUCCESS",
        "NOTICE",
        "WARNING",
        "ERROR",
        "FATAL",
    };
    printf("[%s][%s]\n",msg,level_msg[level%5]);
#else
#endif
}

 int startup(const char* ip,int port)
 {
     int sock = socket(AF_INET,SOCK_STREAM,0);
     if(sock < 0)
     {
         print_log(strerror(errno),FATAL);
         exit(2);
     }
 
    int opt = 1;
     setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
 
     struct sockaddr_in local;
     local.sin_family = AF_INET;
     local.sin_port = htons(port);
     local.sin_addr.s_addr = inet_addr(ip);
     if(bind(sock,(struct sockaddr*)&local,sizeof(local))<0)
     {
         print_log(strerror(errno),FATAL);
        exit(3);
     }
     if(listen(sock,10)<0)
     {
         print_log(strerror(errno),FATAL);
         exit(4);
     }
     return sock;
 }

static int get_line(int sock,char line[],int size)
 {
     //read 1 char ,one by one
     char c = '\0';
     int len = 0;
     while(c != '\n' && len < size -1)
     {   
         int r = recv(sock,&c,1,0);
         if(r > 0)
         {
             if(c == '\r')
             {
                 int ret = recv(sock,&c,1,MSG_PEEK);
                 if(ret > 0)
                 {
                     if(c == '\n')
                     {
                         recv(sock,&c,1,0);
                     }
                     else
                     {
                         c = '\n';
                     }
           }
             }// \r -> \n,\r\n ->\n
             //c == \n
             line[len++] = c;
         }
         else
         {
             c = '\n';
         }
 
     }
     line[len] = '\0';
     //printf("line : %s\n",line);
     return len;
 }
 
 static void echo_string(int sock)
 {}


int echo_www(int sock,char* path,int size) //GET
{
    int fd = open(path,O_RDONLY);
    if(fd < 0)
    {
        echo_string(sock);
        print_log(strerror(errno),FATAL);
        return 8;
    }

    const char *echo_line="HTTP/1.0 200 OK\r\n";
    send(sock,echo_line,strlen(echo_line),0);
    const char *null_line="\r\n";
    send(sock,null_line,strlen(null_line),0);


    //success
    if(sendfile(sock,fd,NULL,size)<0)
    {
        echo_string(sock);
        print_log(strerror(errno),FATAL);
        return 9;
   }
   close(fd);
}


 void drop_header(int sock)
 {
     char line[1024];
     int  ret = -1;
     do
     {
         ret = get_line(sock,line,sizeof(line));
     }while(ret > 0&&strcmp(line,"\n"));
 }
 

//参数query_str实际就是336
int connetser(char *query_str)
{
	int sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock < 0)
	{
    	printf("sock error\n");
	}
    int opt = 1;
    setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(80);
    local.sin_addr.s_addr=inet_addr("1.85.11.58");
    int a =  connect(sock,(struct sockaddr*)&local,sizeof(local));
    //if(a == 0)
    //{
    //  printf("我们已经爬到了网站上面啦！！！\n");
    //}


    char echo_line[420] = "GET /chaxun/bus/busreserch2.asp?keyword=";
    char echo_line2[] = "&submit= HTTP/1.1\r\nHost: www.xianyz.com\r\nUser-Agent: Mozilla/5.0 (X11; Linux i686; rv:52.0 ) Gecko/20100101 Firefox/52.0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: en-US,en;q=0.5\r\nAccept-Encoding: gzip, deflate\r\nCookie: ASPSESSIONIDASSDBCAD=ONPANMLFCHMBOJHPNDBFFBOJK\r\nConnection: keep-alive\r\nUpgrade-Insecure-Requests: 1\r\n\r\n";
    strcat(echo_line,query_str);  //传入的参数，是为了这里接到请求报头上面来的
    strcat(echo_line,echo_line2);
    send(sock,echo_line,strlen(echo_line),0);
    //printf("正在查询，请稍后\n");
    char buf[5000];
    char arr[5000];
    char *pin = buf;
    char *pout = arr;
    memset(arr,0,5000);
    size_t olen = 5000;
    memset(buf,0,5000);
    int m1 = recv(sock,buf,4999,0);
    char buf2[5000];
    memset(buf2,0,5000);


	char *ifok = buf;
	ifok += 117;
	char ifokarr[5] = {0};
	int ii = 0;
	for(ii;ii<4;ii++)
	{
		ifokarr[ii] = *ifok;
		ifok++;
	}

	ii = atoi(ifokarr);
	if(ii > 2500)
	{
	  int m2 = recv(sock,buf2,4999,0);
      strcat(buf,buf2);
	}
    size_t len = strlen(buf); 
    iconv_t cd = iconv_open("utf-8","gb2312");
    if(cd == 0)
    {
        printf("error");
        return 0;
    }

    if(iconv(cd,&pin,&len,&pout,&olen) == -1)
    {
        printf("转码错误\n");
    }

    iconv_close(cd);


//这里把recv函数返回的数值大小返回来，因为我们在读取数据的时候，可能存在一个问题就是，打印的时候可能遇到了\0然后就没有打印完全

	if(ii>2500)
	{
        //FILE* pf = fopen("txt","a+");
        //fwrite(arr,1,strlen(arr),pf);
        //string filename = "336.html";
        //fstream in(filename.c_str());
        //string html;
        //if(!in)
        //{
        //    cout<<"error"<<endl;
        //}
        //string htmltmp;
        //while(in>>htmltmp)
        //{
        //    html += htmltmp;
        //}
        //cout<<"  html    "<<html<<endl;
	    HTML::ParserDom parser;
	    tree<HTML::Node> dom = parser.parseTree(arr);
        tree<HTML::Node>::iterator it = dom.begin();
        //tree<HTML::Node>::iterator end = dom.end();
        //cout<<"dom   "<<endl<<dom<<endl;
	    //HTML::ParserDom par;
	    //tree<HTML::Node> d = par.parseTree(html);
        //tree<HTML::Node>::iterator ithtml = d.begin();
        //cout<<d<<endl;
        //ithtml += 15;
        ////ithtml->text() = "hahahahhaha";
        //cout<<"      ithtml      "<<ithtml->text()<<endl;
        string prev = "<html><head><meta charset=\"utf-8\"></html><div class=\"container-fluid\"><div class=\"row-fluid\"> <div class=\"span12\"><h3 class=\"text-center\"> 西安公交查询系统</h3><form name=\"input\" action=\"haha.html\" method=\"get\">车次号: <input type=\"text\" name=\"user\"><input type=\"submit\" value=\"查询\">";
        string next = "<p> </p></div></div></div>";

        //输出所有的文本节点内容
	    it+=130;
        string path = "./wwwroot/train_number/";
        path += query_str;
        path += ".html";
	    ofstream fout(path);
        //fout<<"<html><head><meta charset=\"utf-8\"><title>公交查询系统</title></head><body>"<<it->text()<<"</body></html>";
        string str = it->text();   //str中的内容就是各个站点
        str = replaceALL(str,"、"," ");
        string middle;
        string tmp;
        vector<string> mini;
        stringstream ss(str);
        while(ss>>tmp)
        {
            middle += "<p>";
            middle += tmp;
            middle += "</p>";
            //mini.push_back(tmp);
        }
        string text = prev + middle + next;
        fout<<text;
	    fout<<flush;
	    fout.close();
        return 0;
	}
	else
	{
		cout<<"\n\n\n\n\n\n\n访问的页面不存在\n";
		//处理其他的事情

	    ofstream fout("./wwwroot/haha.html");
        fout<<"<html><head><meta charset=\"utf-8\"><title>出错</title></head><body><p>对不起，访问的页面不存在</p></body></html>";
	    fout<<flush;
	    fout.close();
        return -1;
	}
 }


void *handler_request(void *arg)
{
	//unsigned long sock = (unsigned long)arg;
    struct sock_index* psi = (struct sock_index*)arg; 
	unsigned long sock = psi->sock;
    InvertedIndex* pindex = psi->index;
#ifdef _DEBUG_
     char line[1024];
     do{
         int ret = get_line(sock,line,sizeof(line));
         if(ret > 0)
         {
             printf("%s",line);
         }
         else
         {
             printf("request .......done\n");
             break;
         }
       }
     while(1);
#else
 
     int ret = 0;
     char buf[SIZE];
     char method[SIZE/10];
     char url[SIZE];
     char path[SIZE];
     int i,j;
     int cgi = 0;
     char* query_string = NULL;
 
     if(get_line(sock,buf,sizeof(buf)) <= 0)
     {
         echo_string(sock);//fail
         ret = 5;
         goto end;
	 }
	 //buf里面放置的内容就是我的url和方法的信息，就是我的整个请求行
     i = 0; //method -> index
     j = 0; //buf->index

     //GET / http/1.1
     while(!isspace(buf[j])\
             &&j < sizeof(buf)\
             &&i < sizeof(method) - 1)
     {
         method[i] = buf[j];
         i++;
         j++;
     }
     method[i] = 0;
	//method里面的内容是方法，这里一般就是GET
	 if(strcasecmp(method,"GET") &&strcasecmp(method,"POST"))
     {
         echo_string(sock);
         ret = 6;
         goto end;
     }
	 if(strcasecmp(method,"post") == 0)
     {
         cgi = 1;
     }
     //buf -> "GET / http/1.0"
     while(isspace(buf[j])&&j<sizeof(buf))
     {
         j++;
     }

     i = 0;
     //while(isspace(buf[j])&&j<sizeof(buf)&&i<sizeof(url))
     while(!isspace(buf[j])&&j<sizeof(buf)&&i<sizeof(url))
     {
         url[i] = buf[j];
         i++;
         j++;
     }
     url[i] = 0;
     //printf("method : %s url :%s\n",method,url);
     //pan duan shibushi you ? hao   
     //while循环中做的事情，是将url截断
     //使query_string指向了336
     query_string = url;
     while(*query_string != '\0')
     {
         if(*query_string == '?')
         {
             *query_string = '\0';
             query_string++;
             cgi = 1;
             break;
         }
         query_string++;
     }
     //pinjie genmulu
     sprintf(path,"wwwroot%s",url);
     if(path[strlen(path) - 1] == '/')// '/'
     {
         strcat(path,"index.html");
     }
 
	 struct stat st;
     if(stat(path,&st) != 0)
     {
         //访问的路径不存在
         echo_string(sock);
         ret  = 7;
         goto end;
     }
     else
     {
         //success
         //mulu
         if(S_ISDIR(st.st_mode))
         {
             strcat(path,"/index.html");
         }
         else if((st.st_mode & S_IXUSR)||(st.st_mode & S_IXGRP)||(st.st_mode & S_IXOTH))
         {
             //cheng xu
			 cgi = 1;
         }
		 else
         {
			 //printf("这里不管是不是正确的路径，都进入到这个函数内部了，是什么原因\n");
		 }
         //ok -> cgi=?,path,query_string,method
        //上面有一个分心path的程序部分，就是处理那个query的那个部分的地方，我哪里把cgi
		//写成是1了，就导致了总是进入到下面的内容 中了，所以我这里先把这个if给注释掉了
		// if(cgi)
        // {
        //   //exe_cgi();
        // }
        // else
        // {
        //     printf("method : %s\n url :%s \n path : %s\n cgi : %d\nquery_string:%s\n    ",method,url,path,cgi,query_string);
        //    drop_header(sock);  //!!!!!!!!      
        //    echo_www(sock,path,st.st_size);  //GET
        // }
        //
        //
        //
        // 将要访问一个查询的时候，首先检查本地有没有这个文件
        // 如果有直接返回，如果没有使用 爬虫爬取数据，将生成的网页放在指定的目录下面
        

         int flag = 1; 
		if(cgi)
		{
		    query_string+=5;	//这里query_string是一个指针，维护着url
                                //query_string + 5之后应该获取的就是用户想要查询的车次
            path[8] = '\0';
            strcat(query_string,".html");
            strcat(path,"train_number/");
            strcat(path,query_string);
            if(!access(path,0)) //判断车次文件夹是否有数据
            {
                printf("\n\n\n\n\n\n文件存在path %s       query_stri%s\n\n\n\n",path,query_string);
            }
            else  //如果没有数据，爬取数据放在目录下面
            {
                //query_string[3] = '\0';
                char *p = query_string;
                while(*p != '\0')
                {
                    p++;
                }
                p -= 5;
                *p = '\0';
                printf("\n\n\n\n\n%s\n\n\n\n\n",query_string);

                string word = query_string;
                cout<<word<<endl;

                printf("path :   %s\n",path);
                path[0] = '\0';
                strcat(path, "/root/git/SearchEngine/html.html");
                vector<string> url = pindex->get_docid(word);

                //将结果写入到socket中，返回即可
                //使用ctemplate函数处理
                drop_header(sock);  //!!!!!!!!      
                const char *echo_line="HTTP/1.0 200 OK\r\n";
                send(sock,echo_line,strlen(echo_line),0);
                const char *null_line="\r\n";
                send(sock,null_line,strlen(null_line),0);

                ctemplate::TemplateDictionary dict(" ");
                dict.SetValue("url",url[0]);
                std::string output;
                ctemplate::ExpandTemplate("./wwwroot/template/temp.html", ctemplate::DO_NOT_STRIP, &dict, &output);
                send(sock,output.c_str(),output.size(),0);
                cout<<output<<endl;
                flag = 0;
            }
		}
        //printf("method : %s\n url :%s \n path : %s\n cgi : %d\nquery_string:%s\n    ",method,url,path,cgi,query_string);
        if(flag)
        {
            drop_header(sock);  //!!!!!!!!      
            stat(path,&st);  //这里设置的目的，是为了是st和最近的文件进行绑定，以便获取文件的长度
            echo_www(sock,path,st.st_size);  //GET
        }
     }



 end:
     printf("quit client ...\n");
     close(sock);
	return (void*)ret;
 #endif
}

