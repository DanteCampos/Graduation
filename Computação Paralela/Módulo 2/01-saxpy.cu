#include <stdio.h>

#define N 2048 * 2048 // Number of elements in each vector

/*
 * Optimize this already-accelerated codebase. Work iteratively,
 * and use nsys to support your work.
 *
 * Aim to profile `saxpy` (without modifying `N`) running under
 * 20us.
 *
 * Some bugs have been placed in this codebase for your edification.
 */

__global__
void initMem(float *a, int x){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;

    if ( tid < N )
        a[tid] = x;
}

__global__ void saxpy(float * a, float * b, float * c)
{
    int tid = blockIdx.x * blockDim.x + threadIdx.x;

    if ( tid < N )
        c[tid] = 2 * a[tid] + b[tid];
}

int main()
{
    float *a, *b, *c;

    int size = N * sizeof (float); // The total number of bytes per vector
    
    int deviceId;
    cudaGetDevice(&deviceId);
    
    int threads_per_block = 256;
    int number_of_blocks = N / threads_per_block;
    
    cudaMallocManaged(&a, size);
    cudaMallocManaged(&b, size);
    cudaMallocManaged(&c, size);
    
    cudaMemPrefetchAsync(a, size, deviceId);
    cudaMemPrefetchAsync(b, size, deviceId);
    cudaMemPrefetchAsync(c, size, deviceId);
    
    // Initialize memory
    initMem<<< number_of_blocks, threads_per_block >>> (a, 2);
    initMem<<< number_of_blocks, threads_per_block >>> (b, 1);
    initMem<<< number_of_blocks, threads_per_block >>> (c, 0);
    
    cudaDeviceSynchronize();
    
    saxpy <<< number_of_blocks, threads_per_block >>> ( a, b, c ); 
    cudaDeviceSynchronize();
    
    cudaMemPrefetchAsync(c, size, deviceId);
    
    // Print out the first and last 5 values of c for a quality check
    for( int i = 0; i < 5; ++i )
        printf("c[%d] = %f, ", i, c[i]);
    printf ("\n");
    for( int i = N-5; i < N; ++i )
        printf("c[%d] = %f, ", i, c[i]);
    printf ("\n");

    cudaFree( a ); cudaFree( b ); cudaFree( c );
}
