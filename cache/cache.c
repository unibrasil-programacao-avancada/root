#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

// 163.840 long (4 bytes) em L1 (640 KB = 655.360 B)
const int N_COLS = 40960; // 4 blocos de tamanho N_COLS long cabem em L1
const int N_ROWS = 512; // 1 miss L1 a cada 4 blocos (linhas) de tamanho 40960 cada
const int MAX_NUM = 100;;

void init_matrix(long** mat);
void free_matrix(long** mat);
void print_matrix(long** mat);
long sum_matrix_by_rows(long** mat);
long sum_matrix_by_cols(long** mat);
void print_time(char* function_name, struct timeval start_time, struct timeval end_time, long sum);

int main()
{
    struct timeval start_time, end_time;
    long** matrix;
    long sum;

    matrix = (long**) malloc(N_ROWS * sizeof(long*));
    for (int i = 0; i < N_ROWS; i++)
    {
        matrix[i] = (long*) malloc(N_COLS * sizeof(long));
    }

    init_matrix(matrix);

    gettimeofday(&start_time, NULL);
    sum = sum_matrix_by_rows(matrix);
    gettimeofday(&end_time, NULL);
    print_time("sum_by_rows", start_time, end_time, sum);

    gettimeofday(&start_time, NULL);
    sum = sum_matrix_by_cols(matrix);
    gettimeofday(&end_time, NULL);
    print_time("sum_by_cols", start_time, end_time, sum);

    free_matrix(matrix);

    return 0;
}

void init_matrix(long** mat)
{
    for (int i = 0; i < N_ROWS; i++)
    {
        for (int j = 0; j < N_COLS; j++)
        {
            mat[i][j] = rand() % MAX_NUM;
        }
    }
}

void free_matrix(long** mat)
{
    /* Implemente a liberacao da memoria alocada para a matriz */
}

void print_matrix(long** mat)
{
    /* Implemente a impressao da matriz */
}

long sum_matrix_by_rows(long** mat)
{
    long sum = 0;

    /* Implementa a soma */

    return sum;
}


long sum_matrix_by_cols(long** mat)
{
    long sum = 0;

    /* Implementa a soma */

    return sum;
}

void print_time(char* function_name, struct timeval start_time, struct timeval end_time, long sum)
{
    printf ("Total time (%s) = %f seconds. Sum = %ld\n", function_name,
         (double) (end_time.tv_usec - start_time.tv_usec) / 1000000 +
         (double) (end_time.tv_sec - start_time.tv_sec), sum);
}


