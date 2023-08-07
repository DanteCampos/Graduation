#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/time.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct{
  unsigned long long v1;
  unsigned long long v2;
} Edge;

// Gets the position in an upper triangle adjacency matrix of the edge i-j
unsigned long long upper_triangle_position (unsigned long long i, unsigned long long j, unsigned long long vertices){
    // A beautiful example of branchless programming
    // If i>=j, switch j and i (false = 0, true = 1);
    return (i < j)*(i*vertices - (i*(i+1))/2 + j - i -1)
         + (i >=j)*(j*vertices - (j*(j+1))/2 + i - j -1);
}

// Returns the number of integers needed for the bitmap
unsigned long long bitmap_size_int (unsigned long long vertices){
    unsigned long long size = (vertices*(vertices-1))/2;
    return size/32+(size%32 != 0);
}

// Returns the number of bytes needed for the bitmap
unsigned long long bitmap_size_byte (unsigned long long vertices){
    return bitmap_size_int(vertices)*4;
}

// Inserts an edge i-j in a bitmap upper triangle adjacency matrix
void bitmap_write(unsigned int* bitmap, unsigned long long i, unsigned long long j, unsigned long long vertices){
    unsigned long long position = upper_triangle_position(i, j, vertices);
    unsigned int mask = 0x80000000 >> (position % 32);
    bitmap[position/32] = (mask | bitmap[position/32]);
    return;
}

// Gets the edge i-j in an upper triangle adjacency matrix
char bitmap_get(unsigned int bitmap[], unsigned long long i, unsigned long long j, unsigned long long vertices){
    unsigned long long position = upper_triangle_position(i, j, vertices);
    unsigned long long location = position/32;
    unsigned int mask = 0x80000000 >> (position % 32);
    char result = (mask & bitmap[location]) != 0;
    return result;
}

// Generates the file name for saving the time
// TYPE: 0 = host-to-device, 1 = processing, 2 = device-to-host
void generate_time_file_name(char time_file_name[], int type, int dirIndex,
  char* vertices_string_G, char* edges_string_G, char* vertices_string_H, char* edges_string_H){
  
  switch (type){
    case 0:
      strcpy(time_file_name, "./CUDAtime/host_to_device-");
      break;
    case 1:
      strcpy(time_file_name, "./CUDAtime/processing-");
      break;
    case 2:
      strcpy(time_file_name, "./CUDAtime/device_to_host-");
      break;
    default:
      printf("Time file name error\n");
      return;
  }

  switch (dirIndex){
    case 0:
      strcat(time_file_name, "0.25x0.5-");
      break;
    case 1:
      strcat(time_file_name, "0.5x0.75-");
      break;
    case 2:
      strcat(time_file_name, "0.75x0.25-");
      break;
    default:
      printf("Time file name error\n");
      return;
  }

  strcat(time_file_name, vertices_string_G);
  strcat(time_file_name, ".");
  strcat(time_file_name, edges_string_G);
  strcat(time_file_name, "x");
  strcat(time_file_name, vertices_string_H);
  strcat(time_file_name, ".");
  strcat(time_file_name, edges_string_H);
  strcat(time_file_name, ".time");
}

void generate_result_file_name(char result_file_name[], int dirIndex,
  char* vertices_string_G, char* edges_string_G, char* vertices_string_H, char* edges_string_H){
  
  strcpy(result_file_name, "./CUDAresult/");
  switch (dirIndex){
    case 0:
      strcat(result_file_name, "0.25x0.5-");
      break;
    case 1:
      strcat(result_file_name, "0.5x0.75-");
      break;
    case 2:
      strcat(result_file_name, "0.75x0.25-");
      break;
    default:
      printf("Result file name error\n");
      return;
  }

  strcat(result_file_name, vertices_string_G);
  strcat(result_file_name, ".");
  strcat(result_file_name, edges_string_G);
  strcat(result_file_name, "x");
  strcat(result_file_name, vertices_string_H);
  strcat(result_file_name, ".");
  strcat(result_file_name, edges_string_H);
  strcat(result_file_name, ".result");
}

void write_time_file (char time_file_name[], double time){
  FILE *time_file;
  time_file = fopen(time_file_name, "w");
  fprintf(time_file, "%lf\n",time);
  fclose(time_file);
}

void write_result_file (char result_file_name[], unsigned int P[], unsigned long long vertices_P){
  FILE *result_file;
  unsigned long long i, j;
  result_file = fopen(result_file_name, "w");
  for (i = 0; i < vertices_P; i++){
		for (j = i+1; j < vertices_P; j++)
			if (bitmap_get(P, i, j, vertices_P))
        fprintf (result_file, "%llu-%llu\n", i,j);
	}
  fclose(result_file);
}

// Creating edge list from a edge list file
Edge* edge_array_from_file(char file_name[], unsigned int edges){
  unsigned long long i, v1, v2;
  FILE *file;
  Edge* edge_list;

  // Opening graph file
  file = fopen(file_name, "r");
  if (!file){
    printf("Couldn't open file %s\n", file_name);
    return 0;
  }

  // Constructing H edge list
  edge_list = (Edge*) malloc(edges*sizeof(Edge));
  if (!edge_list)
    return NULL;
  
  for (i = 0; fscanf(file,"%llu %llu", &v1, &v2) != EOF; i++){
    edge_list[i].v1 = v1;
    edge_list[i].v2 = v2;
  }
  fclose(file);

  return edge_list;
}

// Print the edge array passing the number of edges
void printEdgeArray (Edge* edge_list, unsigned long long edges){
	int i;
	for (i = 0; i < edges; i++)
		printf("%llu-%llu\n", edge_list[i].v1, edge_list[i].v2);
	return;
}

// Print the Bitmap of an Upper Triangle as an edge list
void print_bitmap_upper (unsigned int P[], unsigned long long vertices_P){
	unsigned long long i, j;
	for (i = 0; i < vertices_P; i++){
		for (j = i+1; j < vertices_P; j++)
			if (bitmap_get(P, i, j, vertices_P))
        printf ("%llu-%llu\n", i,j);
	}
	return;
}

// Calculates part of the cartesian product P = G x H iterating only edges of G
// P is a bitmap of the adjancy matrix upper triangle
__global__
void cartProdBitmapG (Edge* G, unsigned int* P, unsigned long long edges_G, unsigned long long vertices_H, unsigned long long vertices_P){
  unsigned long long m, position;
  unsigned long long v1P, v2P;
  unsigned int mask;

  unsigned long long idx = (unsigned long long)blockIdx.x * (unsigned long long)blockDim.x + (unsigned long long)threadIdx.x;
  unsigned long long stride = (unsigned long long)gridDim.x * (unsigned long long)blockDim.x;
  for (; idx < edges_G; idx += stride){
    //printf("G: %llu-%llu\n", G[idx].v1, G[idx].v2);
    for (m = 0; m < vertices_H; m++){
      v1P = G[idx].v1*vertices_H + m;
      v2P = G[idx].v2*vertices_H + m;
      
      position = (v1P < v2P)*(v1P*vertices_P - (v1P*(v1P+1))/2 + v2P - v1P -1)
        + (v1P >= v2P)*(v2P*vertices_P - (v2P*(v2P+1))/2 + v1P - v2P -1);
      mask = 0x80000000 >> (position % 32);
      
      // To evict running condition, use atomic OR
      atomicOr(&P[position/32], mask);
		}
  }
	return;
}

// Calculates part of the cartesian product P = G x H iterating only edges of H
// P is a bitmap of the adjancy matrix upper triangle
__global__
void cartProdBitmapH (Edge* H, unsigned int* P, unsigned long long edges_H, unsigned long long vertices_G, unsigned long long vertices_H, unsigned long long vertices_P){
  unsigned long long m, position;
  unsigned long long v1P, v2P;
  unsigned int mask;

  unsigned long long idx = (unsigned long long)blockIdx.x * (unsigned long long)blockDim.x + (unsigned long long)threadIdx.x;
  unsigned long long stride = (unsigned long long)gridDim.x * (unsigned long long)blockDim.x;
  
  for (; idx < edges_H; idx += stride){
  //printf("H: %llu-%llu\n", H[idx].v1, H[idx].v2);
    for (m = 0; m < vertices_G; m++){
      v1P = m*vertices_H + H[idx].v1;
      v2P = m*vertices_H + H[idx].v2; 

      position = (v1P < v2P)*(v1P*vertices_P - (v1P*(v1P+1))/2 + v2P - v1P -1)
        + (v1P >= v2P)*(v2P*vertices_P - (v2P*(v2P+1))/2 + v1P - v2P -1);
      mask = 0x80000000 >> (position % 32);
      
      // To evict running condition, use atomic OR
      atomicOr(&P[position/32], mask);
		}
  }
	return;
}

int main(int argc, char** argv){
  unsigned long long vertices_G, vertices_H, vertices_P, edges_G, edges_H;
  int dirIndex;
  char file_name_G[100], file_name_H[100], time_file_name[100], result_file_name[100];
  char *vertices_string_G, *edges_string_G, *vertices_string_H, *edges_string_H;
  const char *directories_G[3] = {"./0.25/\0","./0.5/\0","./0.75/\0"};
  const char *directories_H[3] = {"./0.5/\0","./0.75/\0","./0.25/\0"};
  Edge *edge_array_G_RAM, *edge_array_H_RAM, *edge_array_G_VRAM, *edge_array_H_VRAM;
  unsigned int *bitmap_P_VRAM;
  unsigned int *bitmap_P_RAM;
  DIR *d_G, *d_H;
  struct timeval start_time, end_time;
  double host_to_device_time, device_to_host_time, processing_time;
  struct stat st = {0};
  struct dirent *dir_G;
  struct dirent *dir_H;
  size_t len_P_bytes;
  size_t len_P_ints;
  size_t threadsPerBlock;
  size_t numberOfBlocks;
  int deviceId;
  int numberOfSMs;
  int arg_n_threads;
  int arg_n_blocks;
  cudaError_t error;

  // Dealing with arguments
  if (argc != 3){
    printf("Must receive 2 arguments: <n_threads_per_block> <n_blocks_per_SM>");
    return 0;
  }
  arg_n_threads = atoi(argv[1]);
  arg_n_blocks = atoi(argv[2]);

  // Getting device info
  cudaGetDevice(&deviceId);
  cudaDeviceGetAttribute(&numberOfSMs, cudaDevAttrMultiProcessorCount, deviceId);

  // Setting CUDA kernel execution parameters
  threadsPerBlock = arg_n_threads;
  numberOfBlocks = arg_n_blocks * numberOfSMs;

  // Create directory CUDAtime/ if it doesn't exist 
  if (stat("CUDAtime", &st) == -1) {
      mkdir("CUDAtime", 0700);
  }

  // Create directory CUDAresult/ if it doesn't exist 
  if (stat("CUDAresult", &st) == -1) {
      mkdir("CUDAresult", 0700);
  }

  // For each of the three combination of graph densities
  for (dirIndex=0; dirIndex < 3; dirIndex++){ 

    // Opening directory
    d_G = opendir(directories_G[dirIndex]);
    d_H = opendir(directories_H[dirIndex]);
    if (!d_G || !d_H){
      printf ("Couldn't open directory\n");
      return 0;
    }

    printf ("Starting %s x %s batch\n\n", directories_G[dirIndex], directories_H[dirIndex]);

    // Reading files of the directory
    while (1) {
      
      dir_G = readdir(d_G);
      dir_H = readdir(d_H);
      
      while (dir_G && dir_G->d_name[0] == '.') // Skipping . and ..
        dir_G = readdir(d_G);
      while (dir_H && dir_H->d_name[0] == '.')
        dir_H = readdir(d_H);
      
      if (!dir_G || !dir_H) // If one of the directories reached the end
        break;

      // Mounting the filename
      strcpy(file_name_G, directories_G[dirIndex]);
      strcat(file_name_G, dir_G->d_name);

      strcpy(file_name_H, directories_H[dirIndex]);
      strcat(file_name_H, dir_H->d_name);
      //printf ("Filenames: %s x %s\n", file_name_G, file_name_H);

      // Getting the number of vertices and edges in the filename
      vertices_string_G = strtok(dir_G->d_name, ".");
      edges_string_G = strtok(NULL, ".");
      vertices_G = atoi(vertices_string_G);
      edges_G = atoi(edges_string_G);

      vertices_string_H = strtok(dir_H->d_name, ".");
      edges_string_H = strtok(NULL, ".");
      vertices_H = atoi(vertices_string_H);
      edges_H = atoi(edges_string_H);

      edge_array_G_RAM = edge_array_from_file(file_name_G, edges_G);
      edge_array_H_RAM = edge_array_from_file(file_name_H, edges_H);
      
      // Initializing host structure
      vertices_P = vertices_G*vertices_H;
      len_P_bytes = bitmap_size_byte(vertices_P);
      len_P_ints = bitmap_size_int(vertices_P);
      bitmap_P_RAM = (unsigned int *) calloc (len_P_ints, sizeof(unsigned int));

      // Setting up the result bitmap
      error = cudaMalloc(&bitmap_P_VRAM, len_P_bytes);
      if(error != cudaSuccess)
        printf("CUDA MALLOC BITMAP IN DEVICE error: %s\n", cudaGetErrorString(error));
      error = cudaMemset(bitmap_P_VRAM, 0, len_P_bytes);
      if(error != cudaSuccess)
        printf("CUDA MEM SET BITMAP IN DEVICE error: %s\n", cudaGetErrorString(error));

      // Starting host-to-device memory transfer timer
      gettimeofday(&start_time, NULL);
      
      // Setting up G
      error = cudaMalloc(&edge_array_G_VRAM, edges_G*sizeof(Edge));
      if(error != cudaSuccess)
        printf("CUDA MALLOC EDGES G IN DEVICE error: %s\n", cudaGetErrorString(error));
      error = cudaMemcpy(edge_array_G_VRAM, edge_array_G_RAM, edges_G*sizeof(Edge), cudaMemcpyHostToDevice); // Synchronous
      if(error != cudaSuccess)
        printf("CUDA MEM CPY G TO DEVICE error: %s\n", cudaGetErrorString(error));

      // Setting up H
      error = cudaMalloc(&edge_array_H_VRAM, edges_H*sizeof(Edge));
      if(error != cudaSuccess)
        printf("CUDA MALLOC EDGES H IN DEVICE error: %s\n", cudaGetErrorString(error));
      error = cudaMemcpy(edge_array_H_VRAM, edge_array_H_RAM, edges_H*sizeof(Edge), cudaMemcpyHostToDevice); // Synchronous
      if(error != cudaSuccess)
        printf("CUDA MEM CPY H TO DEVICE error: %s\n", cudaGetErrorString(error));
      
      // Saving host-to-device memory transfer timer
      gettimeofday(&end_time, NULL);
      host_to_device_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec)/1000.0;

      // Starting to calculate the cartesian product
      printf("Calculating %s.%s x %s.%s... ",vertices_string_G, edges_string_G, vertices_string_H, edges_string_H);
      fflush(stdout);
      
      // ------------------------------------------------------------------ 
      // Starting processing timer
      gettimeofday(&start_time, NULL);

      // Calculating the cartesian product
      cartProdBitmapG <<<numberOfBlocks, threadsPerBlock>>> (edge_array_G_VRAM, bitmap_P_VRAM, edges_G, vertices_H, vertices_P);
      cartProdBitmapH <<<numberOfBlocks, threadsPerBlock>>> (edge_array_H_VRAM, bitmap_P_VRAM, edges_H, vertices_G, vertices_H, vertices_P);
      cudaDeviceSynchronize();
      
      /*
      error = cudaGetLastError();
      if(error != cudaSuccess)
        printf("CUDA PROCESSING error: %s\n", cudaGetErrorString(error));
      */

      // Saving processing timer
      gettimeofday(&end_time, NULL);
      processing_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec)/1000.0;
      // ------------------------------------------------------------------
      printf("Finished!\n");
      
      // Starting device-to-host memory transfer timer
      gettimeofday(&start_time, NULL);

      // Copying the result from device to host
      error = cudaMemcpy(bitmap_P_RAM, bitmap_P_VRAM, len_P_bytes, cudaMemcpyDeviceToHost); // Synchronous
      if(error != cudaSuccess)
        printf("CUDA MEM CPY BITMAP TO HOST error: %s\n", cudaGetErrorString(error));

      // Saving device-to-host memory transfer timer
      gettimeofday(&end_time, NULL);
      device_to_host_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec)/1000.0;
      
      /*
      // Saving result as a file (consumes a LOT of time)
      generate_result_file_name(result_file_name, dirIndex,
        vertices_string_G, edges_string_G, vertices_string_H, edges_string_H);
      write_result_file(result_file_name, bitmap_P_RAM, vertices_P);
      */

      // Freeing result and edge lists
      cudaFree(bitmap_P_VRAM);
      cudaFree(edge_array_G_VRAM);
      cudaFree(edge_array_H_VRAM);
      free(bitmap_P_RAM);
      free(edge_array_G_RAM);
      free(edge_array_H_RAM);

      printf("Host to device memory transfer time (ms): %lf\n", host_to_device_time);
      printf("Processing time (ms): %lf\n", processing_time);
      printf("Device to host memory transfer time (ms): %lf\n", device_to_host_time);

      // Saving times as files
      generate_time_file_name(time_file_name, 0, dirIndex,
        vertices_string_G, edges_string_G, vertices_string_H, edges_string_H);
      write_time_file (time_file_name, host_to_device_time);
      printf("Host to device memory transfer time saved as %s\n", time_file_name);

      generate_time_file_name(time_file_name, 1, dirIndex,
        vertices_string_G, edges_string_G, vertices_string_H, edges_string_H);
      write_time_file (time_file_name, processing_time);
      printf("Processing time saved as %s\n", time_file_name);

      generate_time_file_name(time_file_name, 2, dirIndex,
        vertices_string_G, edges_string_G, vertices_string_H, edges_string_H);
      write_time_file (time_file_name, device_to_host_time);
      printf("Device to host memory transfer time saved as %s\n\n", time_file_name);

    }
    closedir(d_G);
    closedir(d_H);

    printf ("Ended %s x %s batch!\n\n", directories_G[dirIndex], directories_H[dirIndex]);
  }
	return 0;
}