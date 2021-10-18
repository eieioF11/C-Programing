#include "stdio.h"
#include "sys/socket.h"
#include "arpa/inet.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#define N 256

int client = 1;

void send_time(int ss)
{
	char data[N] = "";
	time_t curtime;
	int i;
	
	sprintf(data,"%d台目\n",client++);
	write(ss,data,strlen(data));
	
	for(i = 1;i<=10;i++)
	{
		time(&curtime);
		strcpy(data,ctime(&curtime));
		write(ss,data,strlen(data));
		sleep(1);
	}
	close(ss);
}

int main(void)
{
	pthread_t thread; //スレット
	int s = socket(AF_INET,SOCK_STREAM,0);
	
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(8000);
	if(bind(s,(struct sockaddr *)&addr,sizeof(addr)) < 0)
	{
		perror("bind");
		exit(1);
	}

	listen(s,5);//クライアントからの接続要求待機

	struct sockaddr_in client_addr;
	socklen_t len = sizeof(struct sockaddr_in);
	while(1)
	{
		int ss = accept(s,(struct sockaddr *)&client_addr,&len);
		if(ss<0)
		{
			perror("accept");
			exit(1);
		}
		pthread_create(&thread,NULL,(void *)send_time,(void *) ss);
	}
	close(s);
	return 0;
}
