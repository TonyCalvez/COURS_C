default: appli_fifo

all: appli_fifo test_fifo


# -c : compile only (without -c : compile AND generate executable.
fifo.o: fifo.c
	gcc -Wall -c fifo.c -o fifo.o

appli_fifo.o: appli_fifo.c fifo.h
	gcc -Wall -c appli_fifo.c -o appli_fifo.o

test_fifo: fifo.o test_fifo.o
	gcc -Wall test_fifo.o fifo.o -o test_fifo

appli_fifo: fifo.o appli_fifo.o
	gcc -Wall appli_fifo.o fifo.o -o appli_fifo

test_fifo.o : fifo.o fifo.h
	gcc -Wall -c test_fifo.c -o test_fifo.o

clean: 
	rm *.o appli_fifo test_fifo
