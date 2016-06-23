#ifndef VECTOR
#define VECTOR

#define MYHEADER

#define VECTOR_INITIAL_CAPACITY 100

// Define a vector type
typedef struct {
  int size;      // slots used so far
  int capacity;  // total available slots
  long int *data;     // array of integers we're storing
} Vector;

void vector_init(Vector *vector);

void vector_append(Vector *vector, long int value);

int vector_get(Vector *vector, long int index);

void vector_set(Vector *vector, int index, long int value);

void vector_double_capacity_if_full(Vector *vector);

void vector_free(Vector *vector);

#endif
