#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

unsigned long long upper_triangle_position (unsigned long long i, unsigned long long j, unsigned long long vertices){
    // A beautiful example of branchless programming
    // If i>=j, switch j and i (false = 0, true = 1);
    return (i < j)*(i*vertices - (i*(i+1))/2 + j - i -1)
        + (i >= j)*(j*vertices - (j*(j+1))/2 + i - j -1);
}

int main(){
    int vertices=3, size, i, j;
    char P[] = {0,1,1,1,0,1,1,1,0};
    char *upperTriangle;

    size = (vertices*(vertices-1))/2;
    upperTriangle = (char*) calloc(size, sizeof(char));
    printf ("size = %d\n", size);

    int position=0;
    for (i = 0; i < vertices; i++){
        for (j=i+1; j < vertices; j++){
            printf ("i = %d, j = %d, position = %d\n", i, j, position);
            upperTriangle[position++] = P[i*vertices + j];
        }
    }

    for (i = 0; i < vertices; i++){
        for (j=0; j < vertices; j++){
            if (j == i)
                continue;
            position = upper_triangle_position(i, j, vertices);
            printf ("i = %d, j = %d, P = %d, triangle = %d, position = %d\n",i, j,  P[i*vertices + j], upperTriangle[position], position);
        }
    }

    free(upperTriangle);
    return 0;
}