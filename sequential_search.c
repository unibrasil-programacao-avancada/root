#include "practices.h"

void serial_sequential_search()
{
    int *vec, i, valor_de_busca, valor_encontrado;
    init_vector(&vec, VECTOR_SIZE, 1);

    for (i = 0; i < VECTOR_SIZE; i++)
    {
        vec[i] = i + 1;
    }

    // busca com sucesso no vetor
    valor_de_busca = -1;
    valor_encontrado = 0;
    for (i = 0; i < VECTOR_SIZE; i++)
    {
        if (vec[i] == valor_de_busca)
        {
            valor_encontrado = 1;
            break;
        }
    }

    if (valor_encontrado)
    {
        printf("Valor %d encontrado no vetor\n", valor_de_busca);
    } else
    {
        printf("Valor nao existe no vetor!!!\n");
    }

    if (DEBUG)
    {
        for (i = 0; i < VECTOR_SIZE; i++)
        {
            printf("%d ", vec[i]);
        }

        printf("\n");
    }

    free(vec);
}

void *partial_sequential_search(void *arg)
{
    seqsearch_t *seqsearch = (seqsearch_t *) arg;

//    tid = pthread_self() % partials->nthreads;
//    stride = partials->vecsize / partials->nthreads;
//    start = tid * stride;
//    end = (tid == partials->nthreads - 1) ? partials->vecsize : (tid + 1) * stride;

    return NULL;
}

void parallel_sequential_search(int num_threads)
{
    int *vec, i;
    pthread_t threads[num_threads];
    seqsearch_t seqsearch;

    // Inicializacao do vetor
    init_vector(&vec, VECTOR_SIZE, 1);

    // TODO: Passivel de paralelizacao
    for (i = 0; i < VECTOR_SIZE; i++)
    {
        vec[i] = i + 1;
    }

    seqsearch.vec = vec;
    seqsearch.exists = 0;
    seqsearch.value = 8;
    seqsearch.vecsize = VECTOR_SIZE;
    seqsearch.nthreads = num_threads;

    // Criar threads
    for (i = 0; i < num_threads; i++)
    {
        pthread_create(&threads[i], NULL, partial_sequential_search, (void *)&seqsearch);
    }

    // Aguardar threads
    for (i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }
}
