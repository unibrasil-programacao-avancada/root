#ifndef SAMPLES_H_INCLUDED
#define SAMPLES_H_INCLUDED

#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

#define NTHREADS 8

typedef struct
{
    int nthreads;
    int *vec;
    int vecsize;
} heapvector_t;

typedef struct
{
    int nthreads;
    int vecsize;
    int *vec1;
    int *vec2;
    int *vecsum;
} vectorssum_t;

void serial_sum_vector_entries();
void parallel_sum_vector_entries(int num_threads);
void serial_sum_vectors();
void parallel_sum_vectors(int num_threads);

#endif // SAMPLES_H_INCLUDED
