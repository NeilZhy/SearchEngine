#include<pthread.h>
#include"httpd.h"
#include "../api/set_inverted_index.h"


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


   struct sock_index args;

   //创建倒排索引
   InvertedIndex index;
   index.make_url_to_vector("/root/git/SearchEngine/data/www.boost.org");
   index.creat_inverted_index();
   cout<<"索引初始化成功"<<endl;


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
