#include<stdio.h>
#include<stdlib.h>

// execl(path,path,NULL)

void mymath(char* arg)
{
	//此时我们已经拿到了数据了，如果是百度的，我们可以根据词条进行搜索
	//data1=100&data2=200
	char *argv[3];
	int i = 0;
	char *start = arg;
	while(*start)
	{
		if(*start == '=')
		{
			start++;
			argv[i++] == start;
			continue;
		}
		if(*start == '&')
		{
			*start == '\0';
		}
		start++;
	}
	argv[i] = NULL;
	int data1 = atoi(argv[0]);
	int data2 = atoi(argv[1]);
	printf("<html><body><h3>");
	printf("%d + %d = %d\n",data1 , data2,data1 + data2);
	printf("</h3></body></html>");
}


//这个进程会被紫禁城替换掉的，这个时候是不会替换掉了环境变量的
int main()
{
	printf("<html><body><h3>");
	printf("hello world");
	printf("</h3></body></html>");
	printf("hello ,hello ,hello ,hello ,hello\n");
	char *method  = NULL;
	char *query_string = NULL;
	char *string_arg  = NULL;
	int content_len = -1;
	char buf[1024];
	if((method = getenv("METHOD")) )
	{
		if(strcasecmp(method,"GET") == 0)  //GET
		{
			if((query_string = getenv("QUERY_STRING")))
			{
				string_arg = query_string;
			}
		}
		else  //POST
		{
			if(getenv("CONTENT_LENGTH"))
			{
				content_len = atoi(getenv("CONTENT_LENGTH"));
				//data
				int i = 0;
				for(i;i<content_len;i++)
				{
					read(0,&buf[i],1);
				}
				buf[i] = '\0';
				string_arg = buf;
			}
		}
	}
	
	// no care fangfa 
	
	mymath(string_arg);

	return 0;
}

