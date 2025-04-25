#include "util.h"

void init_vector(int **vector, int size, int value)
{
    *vector = malloc(size * sizeof(int));
    for (long i = 0; i < size; (*vector)[i++] = value);
}

void *parallel_init_vector(void *pvector_ptr)
{
    pvector *pvec = (pvector *) pvector_ptr;
    pvec->vec = malloc(pvec->vecsize * sizeof(int));
    for (long i = 0; i < pvec->vecsize; pvec->vec[i++] = pvec->value);

    return NULL;
}

void *parallel_free_vector(void *int_ptr)
{
    int **pvec = (int **) int_ptr;
    free(*pvec);

    return NULL;
}
