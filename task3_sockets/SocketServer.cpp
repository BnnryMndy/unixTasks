#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

using namespace std;

int sID;

void catch_signal(int sig_num)
{
  if(sig_num==2)
  {
    shutdown(sID, 2);
    cout<<"Server shutdown...\nHave a nice day ^-^ "<<"\n";
    exit(0);
  }
}

int main(int argc, char const *argv[])
{
  signal(SIGINT, catch_signal);


  sID = socket(AF_UNIX, SOCK_STREAM, 0);
  if(sID < 0) { perror("socket"); exit(1);}
  cout<<"Create socket, ID = "<<sID<<endl;


  remove("./echo.server"); //unlink() doesn't work on c++ 14 or higher
  struct sockaddr_un saddr;
  saddr.sun_family = AF_UNIX;
  strcpy(saddr.sun_path,"./echo.server");


  if (bind(sID, (struct sockaddr *)&saddr, sizeof(saddr)) < 0)
    { perror("bind"); exit(1); }
  cout<<"Socket bounded..."<<endl;

  if (listen(sID, 5) < 0) { perror("listen"); exit(1); }
  cout<<"Socket listening ..."<<endl;

  while (true)
  {
    int newsock = accept(sID, NULL, 0);
    if (newsock < 0) { continue; }
    cout<<"New client comming..."<<endl;
    if (!fork())
    {
      close(sID);

      while (true)
      {
        int MAXBUF = 1024;
        char buf[MAXBUF];

        bzero(&buf, MAXBUF);
        if (recv(newsock, &buf, MAXBUF, 0) < 0) { perror("recv"); exit(-1); }
        if (!strlen(buf))
        {
          printf("Client disconnected ...\n");
          break;
        }
        else
        {
          printf("Recieve message: %s\n", buf);
          printf("message length: %i\n", strlen(buf));

            char eched[MAXBUF];
            strcpy(eched,"Echo - ");
            strcat(eched, buf);

          if (send(newsock, eched, strlen(eched)+1, 0) <= 0)
            {perror("send"); exit(-1);}
          cout<<"Message send"<<endl;
        }
      }

      exit(0);
    }
    close(newsock);
  }
  return 0;
}
