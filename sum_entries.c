#include "practices.h"

void *partial_sum(void *region_ptr);

void serial_sum_vector_entries()
{
    int* vec;
    int i;
    long sum;

    init_vector(&vec, VECTOR_SIZE, 1);

    sum = 0;
    for (i = 0; i < VECTOR_SIZE; i++)
    {
        sum += vec[i];
    }

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

    init_vector(&hvector.vec, VECTOR_SIZE, 1);
    hvector.vecsize = VECTOR_SIZE;
    hvector.nthreads = num_threads;

    for (i = 0; i < num_threads; ++i)
    {
       pthread_create(&threads[i], NULL, partial_sum, (void *) &hvector);
    }

    sum = 0;
    thread_result = NULL;
    for (i = 0; i < num_threads; ++i)
    {
        pthread_join(threads[i], &thread_result);
        th_sum = (long) (intptr_t) thread_result;
        sum += th_sum;
    }

    if (DEBUG) printf("Sum vector entries: %ld\n", sum);
    free(hvector.vec);
}

void *partial_sum(void *region_ptr)
{
    heapvector_t *partials = (heapvector_t *) region_ptr;

    int i;
    long psum;
    int tid = pthread_self() % partials->nthreads;
    int stride = partials->vecsize / partials->nthreads;

    int start = tid * stride;
    int end = start + stride;

    if (DEBUG) printf("Thread %d running partial [%d-%d]\n", tid, start, end);

    psum = 0;
    for (i = start; i < end; i++)
    {
        psum += partials->vec[i];
    }

    if (DEBUG) printf("Thread %d finished partial sum: %ld\n", tid, psum);

    return (void *) (intptr_t) psum;
}
