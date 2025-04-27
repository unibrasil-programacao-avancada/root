#include "practices.h"

int main()
{
    int nthreads;
    clock_t start, end;
    double cpu_time;

//    nthreads = 1;
//    start = clock();
//    serial_sum_vector_entries();
//    end = clock();
//    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;
//    printf("CPU time used for %d threads: %.6f seconds\n", nthreads, cpu_time);

    nthreads = NTHREADS;
    start = clock();
    print_threads_id(nthreads);
    end = clock();
    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("CPU time used for %d threads: %.6f seconds\n", nthreads, cpu_time);

    return 0;
}
