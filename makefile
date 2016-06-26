all:
	gcc euler1.c -o euler1.o
	gcc euler2.c -o euler2.o
	gcc euler3.c vector.c euler.c -o euler3.o -lm
	gcc euler4.c vector.c euler.c -o euler4.o -lm
	gcc euler5.c vector.c euler.c -o euler5.o -lm
	gcc euler6.c vector.c euler.c -o euler6.o -lm
	gcc euler7.c vector.c euler.c -o euler7.o -lm
	gcc euler8.c vector.c euler.c -o euler8.o -lm
