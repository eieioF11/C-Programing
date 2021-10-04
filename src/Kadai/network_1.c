#include "stdio.h"
#include "sys/socket.h"
#include "arpa/inet.h"
#include "unistd.h"
#include "stdlib.h"

#define N 256

int main(void)
{
	int s = socket(AF_INET,SOCK_STREAM,0);
	
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("172.16.30.142");
	addr.sin_port = htons(8000);
	if(connect(s,(struct sockaddr *)&addr,sizeof(addr)) < 0)
	{
		perror("connect error");
		exit(1);
	}

	char data[N] = "Text Data\n";
	write(s,data,N);
	char rdata[N];
	read(s,rdata,N);
	printf("%s\n",rdata);
	close(s);
	return 0;
}
