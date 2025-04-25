#include "practices.h"

void *partial_sum(void *region_ptr);

void serial_sum_vector_entries()
{
    int* vec;
    int i;
    long sum;

    init_vector(&vec, VECTOR_SIZE, 1);

    sum = 0;
    // Implementar a soma serial das entradas do vetor

    if (DEBUG) printf("Sum vector entries: %ld\n", sum);

    free(vec);
}

void parallel_sum_vector_entries(int num_threads)
{
    pthread_t threads[num_threads];
    long sum, th_sum;
    heapvector_t hvector;
    void *thread_result;
    int i;

    sum = 0;
    thread_result = NULL;

    init_vector(&hvector.vec, VECTOR_SIZE, 1);
    hvector.vecsize = VECTOR_SIZE;
    hvector.nthreads = num_threads;

    // Implementar a criacao de threads e join de cada uma

    if (DEBUG) printf("Sum vector entries: %ld\n", sum);

    free(hvector.vec);
}

void *partial_sum(void *region_ptr)
{
    heapvector_t *partials = (heapvector_t *) region_ptr;

    int i, tid, stride, start, end;
    long psum;

    // Implementar os limites dos subvetores para cada thread

    if (DEBUG) printf("Thread %d running partial\n", tid);

    psum = 0;

    // Implementar a soma parcial

    if (DEBUG) printf("Thread %d finished partial sum: %ld\n", tid, psum);

    return (void *) (intptr_t) psum;
}
