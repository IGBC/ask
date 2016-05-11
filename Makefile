ifndef CC
	CC=gcc
endif
CFLAGS=-Wall
SOURCES=ask.c
EXECUTEABLE=ask

all: ask.c
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTEABLE)

clean:
	rm $(EXECUTEABLE)
