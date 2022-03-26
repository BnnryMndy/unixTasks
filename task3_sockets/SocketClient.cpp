#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdio>
#include <signal.h>

using namespace std;

int sID;

void catch_signal(int sig_num)
{
  if(sig_num==2)
  {
    shutdown(sID, 2);
    cout<<"Client shutdown...\nHave a nice day ^-^ "<<"\n";
    exit(0);
  }
}

int main(int argc, char const *argv[])
{

  signal(SIGINT, catch_signal);

  sID = socket(AF_UNIX, SOCK_STREAM, 0);
  if(sID < 0) { perror("socket"); exit(1);}
  cout<<"Create stream socket, ID = "<<sID<<endl;

  struct sockaddr_un saddr;
  saddr.sun_family = AF_UNIX;
  strcpy(saddr.sun_path,"./echo.server");
  if (connect(sID, (struct sockaddr *)&saddr, sizeof(saddr)) < 0)
    { perror("connect"); exit(1); }
  cout<<"Socket connected..."<<endl;

  while (true)
  {
    std::cout << ">";

    char msg[100];
    cin.getline(msg,100);
    if(!strcmp(msg,""))
      break;

    if (send(sID, msg, strlen(msg)+1, 0) <= 0)
      {perror("send"); exit(-1); }
    cout<<"Send to server:"<<msg<<endl;
    std::cout << "message length:"<<strlen(msg) << '\n';

    int MAXBUF = 1024; /*Максимальный размер принимаемого буфера*/

    char buf[MAXBUF];
    bzero(&buf, MAXBUF);
    if (recv(sID, &buf, MAXBUF, 0) < 0) { perror("recv"); exit(-1); }
    printf("Recieve message: %s\n", buf);
  }

  return 0;
}
