all: main.o
	g++ -Wall main.o -o pig

main.o: main.cc card.h
	g++ -Wall -c main.cc -o main.o

test: all
	./pig

clean: 
	rm *.o pig
