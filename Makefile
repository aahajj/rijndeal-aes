CC=gcc
CFLAGS=-I.
DEPS = rijndael.h

all: decrypt encrypt

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

decrypt: decrypt.o rijndael.o
	$(CC) -o $@ decrypt.o rijndael.o $(CFLAGS)


encrypt: encrypt.o rijndael.o
	$(CC) -o $@ encrypt.o rijndael.o $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o encrypt decrypt
