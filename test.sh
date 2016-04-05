#!/bin/sh
if gcc ask.c; then
	./a.out
	echo "return: $?"
fi;
