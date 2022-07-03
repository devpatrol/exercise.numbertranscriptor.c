all: build

.PHONY: all

build: app
	rm -rf *.o
	clear
	./app

app: main.o
	gcc main.o -o app

main.o: main.c
	rm -rf *.o
	gcc -c main.c -o main.o