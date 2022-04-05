all: main
	./main
clean:
	rm -rf main *.o
main.o: main.cpp
	g++ -c -o main.o main.cpp
hello.o: hello.cpp
	g++ -c -o hello.o hello.cpp
fact.o: fact.cpp
	g++ -c -o fact.o fact.cpp
fibon.o: fibon.cpp
	g++ -c -o fibon.o fibon.cpp
main: main.o hello.o fact.o fibon.o
	g++ -o main main.o hello.o fact.o fibon.o
install:
	install ./main /home/user/unix/task6_make/make_level_2
uninstall:
	rm -rf /home/user/unix/task6_make/make_level_2/main
