CFLAGS=-Wall -std=c99 -fopenmp -funroll-loops -O3
LDLIBS= -lm

hello_world_v2:

testing_parallel: omp_dgemv_v1.o omp_dgemv_v2.o datatools.o

.PHONY: clean
clean:
	-$(RM) hello_world_v2 testing_parallel *.o
