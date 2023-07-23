#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct{
  unsigned int v1;
  unsigned int v2;
} Edge;

void generate_time_file_name(char time_file_name[], int dirIndex,
  char* vertices_string_G, char* edges_string_G, char* vertices_string_H, char* edges_string_H){
  
  strcpy(time_file_name, "./time/");
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
      break;
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

void write_time_file (char time_file_name[], clock_t delta_time){
  FILE *time_file;
  time_file = fopen(time_file_name, "w");
  fprintf(time_file, "%ld\n",delta_time);
  fclose(time_file);
}

// Creating edge list from a edge list file
Edge* edge_list_from_file(char file_name[], unsigned int edges){
  unsigned int i, v1, v2;
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
  
  for (i = 0; fscanf(file,"%u %u", &v1, &v2) != EOF; i++){
    edge_list[i].v1 = v1;
    edge_list[i].v2 = v2;
  }
  fclose(file);

  return edge_list;
}

// Gets the position in an upper triangle adjacency matrix of the edge i-j
unsigned long long upper_triangle_position (unsigned long long i, unsigned long long j, unsigned long long vertices){
    // A beautiful example of branchless programming
    // If i>=j, switch j and i (false = 0, true = 1);
    return (i < j)*(i*vertices - (i*(i+1))/2 + j - i -1)
        + (i >= j)*(j*vertices - (j*(j+1))/2 + i - j -1);
}

// Creates a bitmap of an upper triangle adjacency matrix
char* bitmap_create (unsigned long long vertices){
    unsigned long long size = (vertices*(vertices-1))/2;
    return (char*) calloc (size/8+(size%8 != 0), sizeof(char));
}

// Inserts an edge i-j in a bitmap upper triangle adjacency matrix
void bitmap_write(char* bitmap, unsigned long long i, unsigned long long j, unsigned long long vertices){
    unsigned long long position = upper_triangle_position(i, j, vertices);
    char mask = 0b10000000 >> (position % 8);
    bitmap[position/8] = (mask | bitmap[position/8]);
    return;
}

// Gets the edge i-j in an upper triangle adjacency matrix
char bitmap_get(char* bitmap, unsigned long long i, unsigned long long j, unsigned long long vertices){
    unsigned long long position = upper_triangle_position(i, j, vertices);
    char mask = 0b10000000 >> (position % 8);
    return (mask & bitmap[position/8]) != 0;
}

// Print the edge list with E edges
void printEdgeList (Edge* edge_list, unsigned int E){
	int i;
	for (i = 0; i < E; i++)
		printf("%u-%u\n", edge_list[i].v1, edge_list[i].v2);
	return;
}

// Print the adjacency matrix M with V vertices
void printAdjMat (char * M, unsigned long long V){
	unsigned long long i, j;
	for (i = 0; i < V; i++){
		for (j = 0; j < V; j++)
			printf ("%u ", M[i*V + j]);
		printf("\n");
	}
	printf("\n");
	return;
}

// Calculates part of the cartesian product P = G x H iterating only edges of G
// To generate P it is necessary to call this function for G and H
void cartProdPart (Edge* G, char* P, unsigned int edges_G, unsigned int vertices_H, unsigned long long vertices_P){
  unsigned int i, m;
  unsigned long long v1P, v2P;

	// P is a VP x VP adj. matrix with aij = (vi, uj) as its vertexes, a pair of vi in G and uj in H
	// Each element elc in P is a (a l/VH l%VH, a c/VG c%VG) edge

  for (i = 0; i < edges_G; i++){
    //printf("Edge: %d-%d\n", G[i].v1, G[i].v2);
    for (m = 0; m < vertices_H; m++){
      v1P = G[i].v1*vertices_H + m; //aim
      v2P = G[i].v2*vertices_H + m; //ajm
      /*
      if (G[i].v1 == 8 && G[i].v2 == 9){
        printf("m = %d, line = %d, column = %d\n", m, line, column);
        printf("Access: %d\n", line*vertices_P + column);
      }
      if (line*vertices_P + column >= vertices_P*vertices_P){
        printf ("vertices_P = %Ld\n", vertices_P);
        printf ("P length = %Ld, access = %Ld\n", vertices_P*vertices_P, line*vertices_P + column);
        printf("Line = %Ld, column = %Ld, m = %Ld\n", line, column, m);
        printf ("Edge: %Ld - %Ld\n", G[i].v1, G[i].v2);
      }
      */
      bitmap_write(P, v1P, v2P, vertices_P);
      // P[line*vertices_P + column] = 1; // TÁ ACESSANDO O QUE NUM PODE
		}
  }
	return;
}

int main(){
  unsigned int vertices_G, vertices_H, edges_G, edges_H;
  unsigned long long vertices_P;
  int dirIndex;
  char file_name_G[100], file_name_H[100], time_file_name[100];
  char *vertices_string_G, *edges_string_G, *vertices_string_H, *edges_string_H;
  char *directories_G[] = {"./0.25/\0","./0.5/\0","./0.75/\0"};
  char *directories_H[] = {"./0.5/\0","./0.75/\0","./0.25/\0"};
  Edge *edge_list_G, *edge_list_H;
  char *result;
  DIR *d_G, *d_H;
  clock_t delta_time;
  struct stat st = {0};
  struct dirent *dir_G;
  struct dirent *dir_H;

  // Create directory time/ if it doesn't exist 
  if (stat("time", &st) == -1) {
      mkdir("time", 0700);
  }

  // For each of the three combination of graph densities
  for (dirIndex=0; dirIndex < 3; dirIndex++){ 
    // DEBUG FOR ONLY 0.25x0.5
    //if (dirIndex != 0) continue;

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

      edge_list_G = edge_list_from_file(file_name_G, edges_G);
      edge_list_H = edge_list_from_file(file_name_H, edges_H);

      //printEdgeList(edge_list_G, edges_G);
      //printEdgeList(edge_list_H, edges_H);

      // Initializing the adjacency matrix of the cartesian product
      vertices_P = vertices_G*vertices_H;
      result = bitmap_create(vertices_P);
      
      // Starting to calculate the cartesian product
      printf("Calculating %s.%s x %s.%s... ",vertices_string_G, edges_string_G, vertices_string_H, edges_string_H);
      fflush(stdout);
      delta_time = clock();
      
      // ------------------------------------------------------------------
      cartProdPart (edge_list_G, result, edges_G, vertices_H, vertices_P);
      cartProdPart (edge_list_H, result, edges_H, vertices_G, vertices_P);
      // ------------------------------------------------------------------

      // Calculating passed time
      delta_time = clock() - delta_time;
      printf("Finished!\n");

      // Freeing result and edge lists
      free(result);
      free(edge_list_G);
      free(edge_list_H);

      // Saving the time as a file
      generate_time_file_name(time_file_name, dirIndex,
        vertices_string_G, edges_string_G, vertices_string_H, edges_string_H);
      printf("Time saved as %s\n\n", time_file_name);
      write_time_file (time_file_name, delta_time);
    }
    closedir(d_G);
    closedir(d_H);

    printf ("Ended %s x %s batch!\n\n", directories_G[dirIndex], directories_H[dirIndex]);
  }
	return 0;
}