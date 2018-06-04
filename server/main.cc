#include<pthread.h>
#include"httpd.h"
#include "../api/set_inverted_index.h"



//int main()
//{
//    InvertedIndex index;
//    index.make_url_to_vector("/root/git/SearchEngine/data/www.boost.org");
//    index.forward_index();
//
//    cout<<"请输入单词"<<endl;
//    string word;
//    cin>>word;
//    index.get_docid(word);
//
//    return 0;
//}


static void usage(const char *proc)
{
    printf("Usage: %s [local_ip] [local_port]\n",proc);
}

int main(int argc,char *argv[])
{
   if(argc != 3)
   {
       usage(argv[0]);
       return 1;
   }

   //WordSegmentation  jieba;
   //vector<string> word = jieba("你好 hi how old are you，你今天早上吃饭了吗");
   //for(auto i:word)
   //{
   //    cout<<i<<endl;
   //}

   struct sock_index args;

   InvertedIndex index;
   index.make_url_to_vector("/root/git/SearchEngine/data/www.boost.org");
   index.forward_index();
   cout<<endl;

   //cout<<"请输入单词"<<endl;
   //string word;
   //cin>>word;


   int listen_sock = startup(argv[1],atoi(argv[2]));
   while(1)
   {
       struct sockaddr_in client;
       socklen_t  len = sizeof(client);
       int new_sock = accept(listen_sock,(struct sockaddr*)&client,&len);
       if(new_sock < 0)
       {
        print_log(strerror(errno),FATAL);
           continue;
       }
       //链接成功了
       //printf("sock  port [%s : %d]\n",inet_ntoa(client.sin_addr),    ntohs(client.sin_port));

       pthread_t id;
       args.sock = new_sock;
       args.index = &index;
       int ret = pthread_create(&id,NULL,handler_request,(void *)&args);
       if(ret != 0)
       {
           print_log(strerror(errno),WARNING);
           close(new_sock);
      }
       else
       {
           pthread_detach(id);
       }
  }
   close(listen_sock);

   return 0;
}
