#include "practices.h"

void serial_max_min()
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

void* thread_max_min(void *arg)
{
    maxmin_t *maxmin = (maxmin_t *) arg;
    int i, tid, stride, start, end;

    // Política de particionamento do trabalho (vetor) entre threads
    tid = pthread_self() % NTHREADS;
    stride = maxmin->vecsize / NTHREADS;
    start = tid * stride;
    end = start + stride;

    maxmin->max[tid] = INT_MIN;
    maxmin->min[tid] = INT_MAX;

    for (i = start; i < end; i++)
    {
        if (maxmin->vec[i] > maxmin->max[tid])
        {
            maxmin->max[tid] = maxmin->vec[i];
        }

        if (maxmin->vec[i] < maxmin->min[tid])
        {
            maxmin->min[tid] = maxmin->vec[i];
        }
    }

    return NULL;
}

void parallel_max_min(int num_threads)
{
    int i, max, min;
    pthread_t threads[num_threads];
    maxmin_t maxmin;

    max = INT_MIN;
    min = INT_MAX;

    maxmin.vecsize = VECTOR_SIZE;
    init_random_vector(&maxmin.vec, VECTOR_SIZE, LIM_INF, LIM_SUP);

    // Criar threads
    for (i = 0; i < num_threads; i++)
    {
        pthread_create(&threads[i], NULL, thread_max_min, (void *) &maxmin);
    }

    // Aguardar threads
    for (i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < NTHREADS; i++)
    {
        if (maxmin.max[i] > max)
        {
            max = maxmin.max[i];
        }

        if (maxmin.min[i] < min)
        {
            min = maxmin.min[i];
        }
    }

    if (DEBUG)
    {
        for (i = 0; i < VECTOR_SIZE; i++)
        {
            printf("%d ", maxmin.vec[i]);
        }
        printf("\n");

        printf("Min value: %d\n", min);
        printf("Max value: %d\n", max);
    }

    free(maxmin.vec);
}
