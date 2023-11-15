CC = gcc
CFLAGS = -Wall -g

all: cpx

cpx: cpx.c
	$(CC) $(CFLAGS) -o $@ $^

install: cpx
	sudo cp cpx /usr/local/bin/

clean:
	rm -f cpx

.PHONY: all install clean
