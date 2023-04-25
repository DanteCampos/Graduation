#include <stdio.h>

/*
 * Refactor `loop` to be a CUDA Kernel. The new kernel should
 * only do the work of 1 iteration of the original loop.
 */

__global__ void loop(int N)
{
   int i = blockDim.x * blockIdx.x + threadIdx.x;
   if (i < N)
       printf("This is iteration number %d\n", i);
}

int main()
{
  /*
   * When refactoring `loop` to launch as a kernel, be sure
   * to use the execution configuration to control how many
   * "iterations" to perform.
   *
   * For this exercise, be sure to use more than 1 block in
   * the execution configuration.
   */

  int N = 100;
  int n_threads_per_block = 16;
  int n_blocks = (N + n_threads_per_block - 1)/n_threads_per_block;
  loop<<<n_blocks, n_threads_per_block>>>(N);
  cudaDeviceSynchronize();
}
