all: hello
hello: main.o sig.o 
	g++ main.o sig.o
main.o: main.cpp
	g++ -c main.cpp
sig.o: sig.cpp
	g++ -c sig.cpp
clean:
	rm -rf *o hello
