all: main
	./main
clean:
	rm -rf main *.o
main.o: main.cpp
	g++ -c -o main.o main.cpp
Bubble.o: Bubble.cpp
	g++ -c -o Bubble.o Bubble.cpp
Insertion.o: Insertion.cpp
	g++ -c -o Insertion.o Insertion.cpp
Selection.o: Selection.cpp
	g++ -c -o Selection.o Selection.cpp
GetRand.o: GetRand.cpp
	g++ -c -o GetRand.o GetRand.cpp
main: main.o Bubble.o Insertion.o Selection.o GetRand.o
	g++ -o main main.o Bubble.o Insertion.o Selection.o GetRand.o
install:
	install ./main /home/user/unix/task6_make/make_sort
uninstall:
	rm -rf /home/user/unix/task6_make/make_sort/main
