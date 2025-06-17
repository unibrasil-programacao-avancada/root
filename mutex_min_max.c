#include "practices.h"

void serial_mutex_min_max()
{
    int *vec, i, max, min;
    init_random_vector(&vec, VECTOR_SIZE, LIM_INF, LIM_SUP);

    max = INT_MIN;
    min = INT_MAX;

    for (i = 0; i < VECTOR_SIZE; i++)
    {
        vec[i] = get_random_int(LIM_INF, LIM_SUP);

        if (vec[i] > max)
        {
            max = vec[i];
        }

        if (vec[i] < min)
        {
            min = vec[i];
        }
    }

    if (DEBUG)
    {
        for (i = 0; i < VECTOR_SIZE; i++)
        {
            printf("%d ", vec[i]);
        }
        printf("\n");

        printf("Min value: %d\n", min);
        printf("Max value: %d\n", max);
    }

    free(vec);
}

void* tmutex_max_min(void *arg)
{
    mutex_maxmin_t *maxmin = (mutex_maxmin_t *) arg;
    int max, min, i;

    int tid = pthread_self() % maxmin->nthreads;
    int stride = maxmin->vecsize / maxmin->nthreads;
    int liminf = tid * stride;
    int limsup = liminf + stride;

    max = INT_MIN;
    min = INT_MAX;
    for (i = liminf; i < limsup; i++)
    {
        if (maxmin->vec[i] > max)
        {
            max = maxmin->vec[i];
        }

        if (maxmin->vec[i] < min)
        {
            min = maxmin->vec[i];
        }
    }

    pthread_mutex_lock(&maxmin->mutex);

    if (max > maxmin->max)
    {
        maxmin->max = max;
    }

    if (min < maxmin->min)
    {
        maxmin->min = min;
    }

    pthread_mutex_unlock(&maxmin->mutex);

    return NULL;
}

void parallel_mutex_min_max(int num_threads)
{
    pthread_t threads[num_threads];
    mutex_maxmin_t maxmin;
    int i;

    maxmin.mutex = PTHREAD_MUTEX_INITIALIZER;
    maxmin.vecsize = VECTOR_SIZE;
    maxmin.nthreads = num_threads;
    maxmin.min = INT_MAX;
    maxmin.max = INT_MIN;

    init_random_vector(&maxmin.vec, VECTOR_SIZE, LIM_INF, LIM_SUP);

    // Criacao de threads
    for (i = 0; i < num_threads; ++i)
    {
       pthread_create(&threads[i], NULL, tmutex_max_min, (void *) &maxmin);
    }

    // Aguardo termino das threads (Sincronizacao)
    for (i = 0; i < num_threads; ++i)
    {
        pthread_join(threads[i], NULL);
    }

    if (DEBUG)
    {
        for (i = 0; i < VECTOR_SIZE; i++)
        {
            printf("%d ", maxmin.vec[i]);
        }
        printf("\n");

        printf("Min value: %d\n", maxmin.min);
        printf("Max value: %d\n", maxmin.max);
    }

    free(maxmin.vec);
}
