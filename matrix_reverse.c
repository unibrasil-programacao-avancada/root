#include "practices.h"

void serial_matrix_reverse()
{
    int i, aux;

    int mat[MATRIX_SIZE][MATRIX_SIZE] =
    {
        { 1, 2, 3 }, // 3, 2, 1
        { 4, 5, 6 }, // 6, 5, 4
        { 7, 8, 9 }  // 9, 8, 7
    };

    if (DEBUG)
    {
        printf("Matriz original:\n");
        print_matrix(mat, MATRIX_SIZE);
    }

    for (i = 0; i < MATRIX_SIZE; i++)
    {
        // Swap
        aux = mat[i][0];
        mat[i][0] = mat[i][2];
        mat[i][2] = aux;
    }

    if (DEBUG)
    {
        printf("Matriz reversa:\n");
        print_matrix(mat, MATRIX_SIZE);
    }
}

void* reverse_row(void* arg)
{
    int **mat = (int **) arg;
    int aux, row;

    // thread1 -> pthread_self() = 1
    // thread2 -> pthread_self() = 2
    // thread3 -> pthread_self() = 3

    row = pthread_self() - 1;

    // Swap
    aux = mat[row][0];
    mat[row][0] = mat[row][2];
    mat[row][2] = aux;

    return NULL;
}

void parallel_matrix_reverse()
{
    int i, j, val, **mat;
    pthread_t threads[MATRIX_SIZE];

    // Alocacao da matriz
    mat = malloc(MATRIX_SIZE * sizeof(int*));
    for (i = 0; i < MATRIX_SIZE; i++)
    {
        mat[i] = malloc(MATRIX_SIZE * sizeof(int));
    }

    val = 1;
    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            mat[i][j] = val++;
        }
    }

    if (DEBUG)
    {
        printf("Matriz original paralela:\n");
        for (i = 0; i < MATRIX_SIZE; i++)
        {
            for (j = 0; j < MATRIX_SIZE; j++)
            {
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
    }
    // Fim: Alocacao da matriz

    for (i = 0; i < MATRIX_SIZE; i++)
    {
        pthread_create(&threads[i], NULL, reverse_row, (void *) mat);
    }

    for (i = 0; i < MATRIX_SIZE; i++)
    {
        pthread_join(threads[i], NULL);
    }

    if (DEBUG)
    {
        printf("Matriz reversa paralela:\n");
        for (i = 0; i < MATRIX_SIZE; i++)
        {
            for (j = 0; j < MATRIX_SIZE; j++)
            {
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
    }


    for (i = 0; i < MATRIX_SIZE; i++)
    {
        free(mat[i]);
    }

    free(mat);
}
