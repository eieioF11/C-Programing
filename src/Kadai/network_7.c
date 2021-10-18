#include <stdio.h>
#include <string.h>      // memset
#include <unistd.h>      // write, read, close
#include <sys/types.h>   // getaddrinfo, freeaddrinfo, socket, connect
#include <sys/socket.h>  // getaddrinfo, freeaddrinfo, socket, connect
#include <netdb.h>       // getaddrinfo, freeaddrinfo
#include <stdlib.h>      // exit
#include <pwd.h>         // getpwuid

#define SERVER "172.16.41.1"

int main(int argc, char *argv[])
{
  int sock;
  struct addrinfo hints, *res;
  FILE *fp;
  int err;
  char port[] = "10001"; 
  struct passwd *pwd;    

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  if((err = getaddrinfo(SERVER, port, &hints, &res)) != 0) {
    printf("getaddrinfo: %s\n", gai_strerror(err)); 
    exit(1);                                       
  }
  sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (sock < 0) {              
    perror("socket");          
    exit(1);
  }
  if(connect(sock, res->ai_addr, res->ai_addrlen) != 0) {
    perror("connect");        
    exit(1);
  }
  freeaddrinfo(res);          
  fp = fdopen(sock, "r+");    

  pwd = getpwuid(getuid());    
  fprintf(fp, "%s\n", pwd->pw_name); 
  fflush(fp);

  close(sock);
  return 0;
}
