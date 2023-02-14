CFLAGS = -Wall -g -std=c99

all: main

main: main.o
	gcc $(CFLAGS) main.o -o main

main.o : main.c 
	gcc $(CFLAGS) -c main.c

clean:
	rm -rf ./*.o
	 
purge: clean
	rm -rf main