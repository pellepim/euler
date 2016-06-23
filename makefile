all:
	gcc euler1.c -o euler1.o
	gcc euler2.c -o euler2.o
	gcc euler3.c vector.c euler.c -o euler3.o -lm
	gcc euler4.c vector.c euler.c -o euler4.o -lm
