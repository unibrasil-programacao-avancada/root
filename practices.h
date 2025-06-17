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
    int *vec;
    int vecsize;
    long sum;
    pthread_mutex_t mutex;
} mutex_vector_t;

typedef struct
{
    int nthreads; // número de threads
    int vecsize; // tamanho dos vetores
    int *vec1; // vetor A
    int *vec2; // vetor B
    int *vecsum; // vetor soma dos vetores vec1 + vec2
} vectorssum_t;

typedef struct
{
    int nthreads;
    int *vec;
    int vecsize;
    int value;
    int exists;
} seqsearch_t;

typedef struct
{
    int *vec;
    int vecsize;
    int max[NTHREADS];
    int min[NTHREADS];
} maxmin_t;

typedef struct
{
    int nthreads;
    int *vec;
    int vecsize;
    pthread_mutex_t mutex;
    int max;
    int min;
} mutex_maxmin_t;

void print_threads_id(int num_threads);
void serial_sum_vector_entries();
void parallel_sum_vector_entries(int num_threads);
void serial_sum_vectors();
void parallel_sum_vectors(int num_threads);
void serial_matrix_reverse();
void parallel_matrix_reverse();
void serial_sequential_search();
void parallel_sequential_search(int num_threads);
void serial_max_min();
void parallel_max_min(int num_threads);
void serial_mutex_sum_vector_entries();
void parallel_mutex_sum_entries(int num_threads);
void serial_mutex_min_max();
void parallel_mutex_min_max(int num_threads);

#endif // SAMPLES_H_INCLUDED
