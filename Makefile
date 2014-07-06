all: main.o
	g++ -Wall -O2 main.o -o pig

main.o: main.cc card.hpp head.hpp
	g++ -Wall -O2 -c main.cc -o main.o

test: all
	./pig

clean: 
	rm *.o pig
