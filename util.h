#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define DEBUG 0
#define VECTOR_SIZE (1 << 27)
//#define VECTOR_SIZE 16
#define MATRIX_SIZE 3
#define LIM_INF 0
#define LIM_SUP 1000

typedef struct
{
    int value;
    int *vec;
    int vecsize;
} pvector;

void init_vector(int **vector, int size, int value);
void init_random_vector(int **vector, int size, int min, int max);
void *parallel_init_vector(void *pvector_ptr);
void *parallel_free_vector(void *int_ptr);
void print_matrix(int mat[MATRIX_SIZE][MATRIX_SIZE], int tam);
int get_random_int(int min, int max);

#endif // UTIL_H_INCLUDED
