all: build

.PHONY: all

build: app
	rm -rf *.o
	./app

app: main.o
	gcc main.o -o app

main.o: main.c
	gcc -c main.c -o main.o