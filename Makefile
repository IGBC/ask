CC=gcc
CFLAGS=-Wall
SOURCES=ask.c
EXECUTEABLE=ask

all: ask.c
	gcc $(CFLAGS) $(SOURCES) -o $(EXECUTEABLE)

clean:
	rm $(EXECUTEABLE)
