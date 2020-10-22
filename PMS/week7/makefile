CFLAGS=-Wall -std=c99 -funroll-loops $(OPT)
LDLIBS= -lm

execute_time: datasize1.o

row_vs_column: my_dgemv_v1.o my_dgemv_v2.o

.PHONY: clean
clean:
	-$(RM) execute_time *.o
