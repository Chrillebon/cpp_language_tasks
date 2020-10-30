CFLAGS=-Wall -std=c99 -fopenmp -funroll-loops -O3
LDLIBS= -lm

hello_world_v2:

testing_parallel: omp_dgemv_v1.o datatools.o my_dgemv_v1.o

.PHONY: clean
clean:
	-$(RM) hello_world_v2 testing_parallel *.o
