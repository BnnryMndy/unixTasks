#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<sys/msg.h>

using namespace std;

int main()
{
	shmget(IPC_PRIVATE, 100, IPC_CREAT | 0666);
	perror("shmget");
	semget(IPC_PRIVATE, 2, IPC_CREAT | 0666);
	perror("semget");
	msgget(IPC_PRIVATE, IPC_CREAT | 0666);
	perror("msgget");
	return 0;
}
