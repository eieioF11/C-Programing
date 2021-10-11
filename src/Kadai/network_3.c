#include "stdio.h"
#include "sys/socket.h"
#include "arpa/inet.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"

#define N 256

int main(void)
{
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
	int ss = accept(s,(struct sockaddr *)&client_addr,&len);

	char data[N];//送信データ
	read(ss,data,N);
	printf("%s\n",data);
	strcpy(data,"Server Test\n");
	write(ss,data,strlen(data));
	
	close(ss);
	close(s);
	return 0;
}
