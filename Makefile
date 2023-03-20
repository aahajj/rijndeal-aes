CC=gcc
CFLAGS=-I. -Wall -g
DEPS = rijndael.h

all: decrypt encrypt

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

decrypt: decrypt.o rijndael.o
	$(CC) -o $@ decrypt.o rijndael.o $(CFLAGS)


encrypt: encrypt.o rijndael.o
	$(CC) -o $@ encrypt.o rijndael.o $(CFLAGS)

test: rijndael.c timecop_test.c
	$(CC) rijndael.c timecop_test.c -o timecop_test $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o encrypt decrypt timecop_test
