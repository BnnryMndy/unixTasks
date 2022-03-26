#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <signal.h>

using namespace std;

void mainClosed(int sig_num){
	cout<<"\nParrent:\tI catched signal... finished..."<<"\n";
}

void childClosedSelf(int sig_num){
	cout<<"\nChild:\tI catched signal... finished..."<<"\n";
}

void childClosed(int sig_num){
	cout<<"Parrent:\tmy child..."<<"\n";
	pause();
}

int main(int argc, char** arvg){
	
	if(!fork())
	{
		/*child's code*/
		signal(SIGINT, childClosedSelf);
		std::cout<<"Child:\tI am started with PID "<<getpid()<<"\n";
		std::cout<<"Child:\tMy parrnet PID "<<getppid()<<"\n";
		pause();
	}
	else
	{
		/*parent's code will be here*/
		signal(SIGCHLD, childClosed);
		signal(SIGINT, mainClosed);
		signal(SIGABRT, mainClosed);
		std::cout<<"Parent:\tI am started with PID "<<getpid()<<"\n";
		pause();
	}
}
