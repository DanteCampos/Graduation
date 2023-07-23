#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

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

int main(){
    int vertices=3, size, i, j;
    char P[] = {0,1,1,1,0,1,1,1,0};
    char *upperTriangleBitmap;

    size = (vertices*(vertices-1))/2;
    printf ("size = %d\n", size);
    upperTriangleBitmap = bitmap_create(size);
    

    int position=0;
    for (i = 0; i < vertices; i++){
        for (j=i+1; j < vertices; j++){
            if (P[i*vertices + j])
                bitmap_write(upperTriangleBitmap, i, j, vertices);
        }
    }

    for (i = 0; i < vertices; i++){
        for (j=0; j < vertices; j++){
            if (j == i)
                continue;
            position = upper_triangle_position(i, j, vertices);
            printf ("i = %d, j = %d, P = %d, triangle = %d\n",i, j,  P[i*vertices + j], bitmap_get(upperTriangleBitmap, i, j, vertices));
        }
    }

    free(upperTriangleBitmap);
    return 0;
}