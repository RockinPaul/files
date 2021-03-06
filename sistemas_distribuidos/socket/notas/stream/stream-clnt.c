/* Arquivo: stream-clnt.c
 * Autor:   Roland Teodorowitsch
 * Data:    1 set. 2006
 */


#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include "stream.h"


int main(int argc, char *argv[])
{
  double nota;
  struct hostent *hostinfo;
  struct sockaddr_in address;
  int sockfd,result;
  socklen_t addr_len;

  if (argc!=3)  {
     fprintf(stderr,"Uso:\n%s <nome_do_servidor> <matricula>\n\n",argv[0]);
     return(1);
  }
  hostinfo = gethostbyname(argv[1]);
  if (!hostinfo)  {
     fprintf(stderr,"%s: erro em gethostbyname().\n",argv[0]);
     exit(1);
  }
  if (hostinfo->h_addrtype!=AF_INET)  {
     fprintf(stderr,"%s: \"%s\" nao e' uma maquina IP.\n",argv[0],argv[1]);
     exit(1);
  }
  addr_len = sizeof(address);
  bzero((char *)&address,addr_len);
  address.sin_family = AF_INET;
  bcopy((char *)hostinfo->h_addr,(char *)&address.sin_addr.s_addr,hostinfo->h_length);
  address.sin_port = htons(SOCKET_PORT);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  result = connect (sockfd, (struct sockaddr *)&address, addr_len);
  if (result == -1)  {
     fprintf(stderr,"%s: erro em connect(): %s\n",argv[0],strerror(errno));
     exit(1);
  }
  write(sockfd,argv[2],sizeof(char)*(TAM_MATRICULA+1));
  read(sockfd,&nota,sizeof(double));
  close(sockfd);

  printf ("Matricula: %s\n",argv[2]);
  if (nota<-1.0)
     printf("Resultado: problemas no servidor!\n");
  else if (nota<0.0) 
     printf("Resultado: matricula nao encontrada!\n");
  else
     printf("Nota: %.1lf\n",nota);
  return (0);
}

