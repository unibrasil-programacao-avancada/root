#include "practices.h"

void serial_sum_vectors()
{
    vectorssum_t vectorsum;
    int i;

    vectorsum.nthreads = 1;

    init_vector(&vectorsum.vec1, VECTOR_SIZE, 1);
    init_vector(&vectorsum.vec2, VECTOR_SIZE, 1);
    init_vector(&vectorsum.vecsum, VECTOR_SIZE, 1);

    for (i = 0; i < VECTOR_SIZE; i++)
    {
        vectorsum.vecsum[i] = vectorsum.vec1[i] + vectorsum.vec2[i];
    }

    free(vectorsum.vec1);
    free(vectorsum.vec2);
    free(vectorsum.vecsum);
}

void *soma_parcial_vetores(void *region_ptr);

void parallel_sum_vectors(int num_threads)
{
    vectorssum_t vectorsum;
    vectorsum.nthreads = num_threads;

    pthread_t threads[num_threads];
    pthread_t threads_preparacao[3];
    pvector vec1, vec2, vec_sum;
    void *thread_result = NULL;
    int i;

    vec1.vecsize = vec2.vecsize = vec_sum.vecsize = VECTOR_SIZE;
    vec1.value = 1; vec2.value = 2; vec_sum.value = 0;

    pthread_create(&threads_preparacao[0], NULL, parallel_init_vector, (void *) &vec1);
    pthread_create(&threads_preparacao[1], NULL, parallel_init_vector, (void *) &vec2);
    pthread_create(&threads_preparacao[2], NULL, parallel_init_vector, (void *) &vec_sum);

    for (i = 0; i < 3; i++)
    {
        pthread_join(threads_preparacao[i], NULL);
    }

    vectorsum.vec1 = vec1.vec;
    vectorsum.vec2 = vec2.vec;
    vectorsum.vecsum = vec_sum.vec;

    // ------- Soma dos vetores -------
    vectorsum.vecsize = VECTOR_SIZE;
    for (i = 0; i < num_threads; i++)
    {
        pthread_create(&threads[i], NULL, soma_parcial_vetores, (void *)&vectorsum);
    }

    for (i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], &thread_result);
    }
    // --------- Fim da soma dos vetores -------


    pthread_create(&threads_preparacao[0], NULL, parallel_free_vector, (void *) &vectorsum.vec1);
    pthread_create(&threads_preparacao[1], NULL, parallel_free_vector, (void *) &vectorsum.vec2);
    pthread_create(&threads_preparacao[2], NULL, parallel_free_vector, (void *) &vectorsum.vecsum);

    for (i = 0; i < 3; i++)
    {
        pthread_join(threads_preparacao[i], NULL);
    }
}

void *soma_parcial_vetores(void *region_ptr)
{

    vectorssum_t *partials = (vectorssum_t *) region_ptr;
    int i, tid, stride, start, end;

    tid = pthread_self() % partials->nthreads;
    stride = partials->vecsize / partials->nthreads;
    start = tid * stride;
    end = (tid == partials->nthreads - 1) ? partials->vecsize : (tid + 1) * stride;

    if (DEBUG) printf("Thread %d running partial\n", tid);

    for (i = start; i < end; ++i)
    {
        partials->vecsum[i] = partials->vec1[i] + partials->vec2[i];
    }

    if (DEBUG) printf("Thread %d finished partial sum: %ld\n", tid);

    return NULL;

}

