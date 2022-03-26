# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/msg.h>
# include <iostream>
# include <cstring>
# include <cstdlib>
# define MSGMAX 1024
# define MSGKEY 354

using namespace std;

struct my_msgbuf
{
  long mtype;
  char mtext[MSGMAX];
};

void createQueue()
{
    int fd = msgget(MSGKEY, IPC_CREAT | IPC_EXCL | 0642);
    cout<<"Message Queue created...\n";
}

void sendMessage(int msgKey)
{
    cout<<"Type your message here (new line — Enter, send — '/send'):\n";
    int fd = msgget(MSGKEY, 0 | IPC_EXCL | 0642);
    
    my_msgbuf mobj = { msgKey, "" };
    while (true)
    {
        char mtext[MSGMAX];
        char* temp;
        cout<<">";
        cin>>mtext;
        
        if(mtext == string("/send")){
            break;
        }
        strcat(mtext, "\n");
        strcat(mobj.mtext, mtext);
    }

    msgsnd(fd, &mobj, strlen(mobj.mtext)+1, IPC_NOWAIT);
    cout<<"Message sent...\n";
}

void recieveMessage(int msgKey)
{  
    cout<<"Message recived...\n";
    my_msgbuf mobj = { msgKey, "" };
    int fd = msgget(MSGKEY, 0 | IPC_EXCL | 0642);
    msgrcv(fd, &mobj, MSGMAX, 0, IPC_NOWAIT | MSG_NOERROR);
    cout<<mobj.mtext<<endl;
}

void readMessgae(int msgKey)
{
    cout<<"Message peeked...\n";
    my_msgbuf mobj = { msgKey, "" };
    int fd = msgget(MSGKEY, 0 | IPC_EXCL | 0642);
    msgrcv(fd, &mobj, MSGMAX, 0, IPC_NOWAIT | MSG_NOERROR);
    cout<<mobj.mtext<<endl;
    msgsnd(fd, &mobj, strlen(mobj.mtext)+1, IPC_NOWAIT);
}

void deleteQUeue()
{
    int fd = msgget(MSGKEY, 0 | IPC_EXCL | 0642);
    msgctl(fd, IPC_RMID, 0);
    cout<<"Message Queue deleted...\n";
}


int main(int argc, char** argv)
{
    if (argc < 2 ) { cout<<"error: wrong args\n"; return -1; }

    if(argv[1] == string("c")){  createQueue(); }

    if(argv[1] == string("s")){ sendMessage(atoi(argv[2])); }

    if(argv[1] == string("r")){ recieveMessage(atoi(argv[2])); }

    if(argv[1] == string("p")){ readMessgae(atoi(argv[2])); }

    if(argv[1] == string("d")){ deleteQUeue(); }
}