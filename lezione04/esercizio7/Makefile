CC=gcc
CFLAGS=-Werror -Wpedantic -Wextra
DEPS=gestionale.h array.h

# questo target cattura tutti quelli sotto commentati
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# main.o: main.c $(DEPS)
# 	$(CC) -c -o main.o $< $(CFLAGS)

# gestionale.o: gestionale.c $(DEPS)
# 	$(CC) -c -o gestionale.o $< $(CFLAGS)

# array.o: array.c $(DEPS)
# 	$(CC) -c -o array.o $< $(CFLAGS)

build: main.o gestionale.o array.o
	$(CC) -o gestionale.out main.o gestionale.o array.o $(CFLAGS) 

install: 
	cp gestionale.out /usr/local/bin/gestionale

clean:
	rm *.o