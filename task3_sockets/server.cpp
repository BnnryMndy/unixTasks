# include <sys/types.h>
# include <sys/socket.h>

int main(int argc, char** argv)
{
    sID = socket(AF_UNIX,SOCK_STREAM,0); /*Создание сокета*/
    unlink("./echo.server"); /*Удалить файл, в случае, если он сохранился от предыдущего запуска сервера*/
    struct sockaddr_un saddr;
    saddr.sun_family = AF_UNIX;
    strcpy(saddr.sun_path,"./echo.server");
    cout<<"socket created\n";

    /*Связывание сокета с адресом*/
    if (bind(sID, (struct sockaddr *)&saddr, sizeof(saddr)) < 0)
        { perror("bind"); exit(1); }
    cout<<"Socket bounded with "<< saddr.sun_path <<endl;

    if (listen(sID, 5) < 0) { perror("listen"); exit(1); }
    cout<<"Socket listening"<<endl;


    while(true) /*Ожидаем клиентов*/
    {
        int newsock = accept(sID, NULL, 0);
        if (newsock < 0) { continue; }
        /* Когда accept() разблокируется, в переменной newsock будет дескриптор нового сокета для общения с прибывшим клиентом*/
        cout<<"New client comming! New socket ID = "<< newsock <<endl;
        if (!fork()) /*Новый процесс для работы с новым клиентом*/
        {
            close(sID); /*Главный сокет в новом процессе не нужен*/

            /*Обмен данными с клиентом через клиентский сокет newsock*/
            int MAXBUF = 1000; /*Максимальный размер принимаемого буфера*/
            char buf[MAXBUF];
            bzero(&buf, MAXBUF);
            if (recv(newsock, &buf, MAXBUF, 0) < 0) { perror("recv"); exit(-1); }
            printf("Recieve message: %s\n", buf);
            
            char eched[MAXBUF];
            strcpy(eched,"Echo - ");
            strcat(eched, buf);

            gets(eched);
            if (send(s, eched, strlen(eched)+1, 0) <= 0)
                { perror("send"); exit(-1); }
            cout<<"Message send"<<endl;

            exit(0);
        }
        close(newsock);

    }
}