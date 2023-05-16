CC=gcc
CFLAGS=-Werror -Wpedantic -Wextra
DEPS=gestionale.h array.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
build: main.o gestionale.o array.o
	$(CC) -o esercizio7.out main.o gestionale.o array.o $(CFLAGS)

clean:
	rm *.o