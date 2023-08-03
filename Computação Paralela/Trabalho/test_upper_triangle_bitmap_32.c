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

// Gets the position in an upper triangle adjacency matrix of the edge i-j
unsigned long long upper_triangle_position (unsigned long long i, unsigned long long j, unsigned long long vertices){
    // A beautiful example of branchless programming
    // If i>=j, switch j and i (false = 0, true = 1);
    return (i < j)*(i*vertices - (i*(i+1))/2 + j - i -1)
        + (i >= j)*(j*vertices - (j*(j+1))/2 + i - j -1);
}

// Creates a bitmap of an upper triangle adjacency matrix
unsigned int* bitmap_create (unsigned long long vertices){
    unsigned long long size = (vertices*(vertices-1))/2;
    return (unsigned int*) calloc (size/32+(size%32 != 0), sizeof(unsigned int));
}

// Inserts an edge i-j in a bitmap upper triangle adjacency matrix
void bitmap_write(unsigned int* bitmap, unsigned long long i, unsigned long long j, unsigned long long vertices){
    unsigned long long position = upper_triangle_position(i, j, vertices);
    unsigned int mask = 0x80000000 >> (position % 32);
    bitmap[position/32] = (mask | bitmap[position/32]);
    return;
}

// Gets the edge i-j in an upper triangle adjacency matrix
unsigned int bitmap_get(unsigned int* bitmap, unsigned long long i, unsigned long long j, unsigned long long vertices){
    unsigned long long position = upper_triangle_position(i, j, vertices);
    unsigned int mask = 0x80000000 >> (position % 32);
    return (mask & bitmap[position/32]) != 0;
}

int main(){
    unsigned int vertices=46, elements, size, n_edges=7, i, j;
    unsigned int *upperTriangleBitmap;
    Edge edges[] = {{0,1}, {1,2}, {2,0}, {3,4}, {4,2}, {21, 22}, {45, 22}};

    elements = (vertices*(vertices-1))/2;
    size = elements/32 + (elements%32 != 0);
    printf ("Number of elements = %u\n", elements);
    printf("Bitmap size = %u\n", size);
    upperTriangleBitmap = bitmap_create(vertices);

    // Fill
    for (i = 0; i < n_edges; i++){
        bitmap_write(upperTriangleBitmap, edges[i].v1, edges[i].v2, vertices);
    }
    
    // Print everything
    for (i = 0; i < size; i++){
        printf("%x ", upperTriangleBitmap[i]);
    }
    printf("\n");

    // Print each edge
    for (i = 0; i < vertices; i++){
        for (j=i+1; j < vertices; j++){
            if (bitmap_get(upperTriangleBitmap, i, j, vertices))
                printf ("%u-%u\n", i, j);
        }
    }

    printf("%p %p %p", &upperTriangleBitmap[0], &upperTriangleBitmap[1], &upperTriangleBitmap[2]);

    free(upperTriangleBitmap);
    return 0;
}