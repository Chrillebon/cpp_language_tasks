CC=gcc
CPPFLAGS=
CFLAGS=-Wall -std=c99 -O2
LDFLAGS=
LDLIBS=-lm

.PHONY: clean test

test_basic: test_basic.o matrix_io.o
matrix_io.o: matrix_io.h

clean:
	-$(RM) *.o test_basic

test: test_basic
	./$<
