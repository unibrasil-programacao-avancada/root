#include "practices.h"

int main()
{
    int nthreads;
    clock_t start, end;
    double cpu_time;

    nthreads = 1;
    start = clock();
    serial_matrix_reverse();
    end = clock();
    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("CPU time used for %d threads: %.6f seconds\n", nthreads, cpu_time);

    nthreads = NTHREADS;
    start = clock();
    parallel_matrix_reverse(nthreads);
    end = clock();
    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("CPU time used for %d threads: %.6f seconds\n", nthreads, cpu_time);

    return 0;
}
