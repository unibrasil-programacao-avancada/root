#include "util.h"

void init_vector(int **vector, int size, int value)
{
    *vector = malloc(size * sizeof(int));
    for (long i = 0; i < size; (*vector)[i++] = value);
}

void init_random_vector(int **vector, int size, int min, int max)
{
    *vector = malloc(size * sizeof(int));
    for (long i = 0; i < size; (*vector)[i++] = get_random_int(min, max));
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

void print_matrix(int mat[MATRIX_SIZE][MATRIX_SIZE], int tam)
{
    int i, j;

    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            printf("%d ", mat[i][j]);
        }

        printf("\n");
    }
}

int get_random_int(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
