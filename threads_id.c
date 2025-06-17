#include "practices.h"

void *print_tid();

void print_threads_id(int num_threads)
{
    pthread_t threads[num_threads];
    int i;

    for (i = 0; i < num_threads; i++)
    {
        pthread_create(&threads[i], NULL, print_tid, NULL);
    }

    for (i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

}

void *print_tid()
{
    printf("Thread id %lu\n", pthread_self());
    return NULL;
}
