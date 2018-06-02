#ifndef _HTTPD_H_
#define _HTTPD_H_
#include<stdio.h>

#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>

#include "../api/set_inverted_index.h"
 
 
#define SUCCESS 0
#define NOTICE 1
#define WARNING 2
#define ERROR 3
#define FATAL 4

#define SIZE 1024
void print_log(char* msg,int level);
int startup(const char *ip,int port);
void *handler_request(void *arg);

struct sock_index 
{
    int sock;
    InvertedIndex* index;
};

#endif

