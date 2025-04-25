#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdlib.h>
#include <time.h>

#define DEBUG 0
#define VECTOR_SIZE (1 << 27)

typedef struct
{
    int value;
    int *vec;
    int vecsize;
} pvector;

void init_vector(int **vector, int size, int value);
void *parallel_init_vector(void *pvector_ptr);
void *parallel_free_vector(void *int_ptr);

#endif // UTIL_H_INCLUDED
