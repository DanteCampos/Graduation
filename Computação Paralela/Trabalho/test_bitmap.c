#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char* bitmap_create (unsigned long long elements){
    return (char*) calloc (elements/8+(elements%8 != 0), sizeof(char));
}

void bitmap_write_element(char* bitmap, unsigned long long element){
    char mask = 0b10000000 >> element % 8;
    bitmap[element/8] = (mask | bitmap[element/8]);
    return;
}

char bitmap_check_element(char* bitmap, unsigned long long element){
    char mask = 0b10000000 >> element % 8;
    return (mask & bitmap[element/8]) != 0;
}

int main(){
    int elements = 9;
    char P[] = {0,0,1,0,1,0,1,0,0};
    char *bitmap;
    
    bitmap = bitmap_create(elements);

    // Accessing an element
    int i;
    for (i=0; i<elements; i++){
        if (P[i])
            bitmap_write_element(bitmap, i);
        printf ("%d = %d\n", P[i], bitmap_check_element(bitmap, i));
    }

    return 0;
}