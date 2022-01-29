#include <stdio.h>



// 1Mb

#define SIZE 1048576



const int size = SIZE;

char vetor[SIZE] = { [0] = 1, [512] = 2, [1024] = 3 };



int main()

{

   printf("%ld\n", sizeof(vetor));

   return 0;

}
