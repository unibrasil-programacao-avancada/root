#include "practices.h"

void serial_sum_vectors()
{
    vectorssum_t vectorsum;
    int i;

    init_vector(&vectorsum.vec1, VECTOR_SIZE, 1);
    init_vector(&vectorsum.vec2, VECTOR_SIZE, 2);
    init_vector(&vectorsum.vecsum, VECTOR_SIZE, 0);
    vectorsum.vecsize = VECTOR_SIZE;

    for (i = 0; i < VECTOR_SIZE; i++)
    {
        vectorsum.vecsum[i] = vectorsum.vec1[i] + vectorsum.vec2[i];
    }

    if (DEBUG)
    {
        printf("Vector sum: ");
        for (i = 0; i < vectorsum.vecsize; ++i)
            printf("%d ", vectorsum.vecsum[i]);
        printf("\n");
    }

    free(vectorsum.vec1);
    free(vectorsum.vec2);
    free(vectorsum.vecsum);
}

void parallel_sum_vectors(int num_threads)
{

}

