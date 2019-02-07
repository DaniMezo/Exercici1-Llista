all: test

main.o: main.c lista.h
	gcc -c main.c
lista.o: lista.c lista.h
	gcc -c lista.c
test: main.o lista.o
	gcc main.o lista.o -o test
clean:
	rm *.o
	rm main