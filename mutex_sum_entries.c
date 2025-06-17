#include "practices.h"

void serial_mutex_sum_vector_entries()
{
    int* vec;
    int i;
    long sum;

    init_random_vector(&vec, VECTOR_SIZE, LIM_INF, LIM_SUP);

    sum = 0;
    for (i = 0; i < VECTOR_SIZE; i++)
    {
        sum += vec[i];
    }

    if (DEBUG) printf("Sum vector entries: %ld\n", sum);

    free(vec);
}

/** Funcao executada por cada thread **/
void *partial_mutex_sum(void *arg)
{
    mutex_vector_t *pvector = (mutex_vector_t *) arg;
    int psum;
    register i;

    int tid = pthread_self() % pvector->nthreads;
    int stride = pvector->vecsize / pvector->nthreads;
    int start = tid * stride;
    int end = start + stride;

    psum = 0;
    for (i = start; i < end; i++)
    {
        psum += pvector->vec[i];
    }

    if (DEBUG) printf("Thread %d [from %d to %d] finished partial sum: %ld\n",
                      tid, start, end, psum);

    pthread_mutex_lock(&pvector->mutex);

    if (DEBUG) printf("Thread %d lock mutex\n", tid);

    pvector->sum += psum;

    if (DEBUG) printf("Thread %d unlock mutex\n", tid);

    pthread_mutex_unlock(&pvector->mutex);

    return NULL;
}

void parallel_mutex_sum_entries(int num_threads)
{
    pthread_t threads[num_threads];
    mutex_vector_t mvector;
    register i;

    mvector.nthreads = num_threads;
    mvector.sum = 0;
    mvector.vecsize = VECTOR_SIZE;
    mvector.mutex = PTHREAD_MUTEX_INITIALIZER;

    init_random_vector(&mvector.vec, VECTOR_SIZE, LIM_INF, LIM_SUP);

    // Criacao de threads
    for (i = 0; i < num_threads; ++i)
    {
       pthread_create(&threads[i], NULL, partial_mutex_sum, (void *) &mvector);
    }

    // Aguardo termino das threads (Sincronizacao)
    for (i = 0; i < num_threads; ++i)
    {
        pthread_join(threads[i], NULL);
    }

    free(mvector.vec);

    if (DEBUG) printf("Sum vector entries: %ld\n", mvector.sum);
}

