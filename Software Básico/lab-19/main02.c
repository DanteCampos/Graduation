#include <stdio.h>



int calc();



void filli(int *v, int cols, int k)

{

  int i;

  (void)k;

  for (i = 0; i < cols; i++) {

    v[i] = 1;

  }

}



void fills(short *v, int cols, int k)

{

  int i;

  (void)k;

  for (i = 0; i < cols; i++) {

    v[i] = 2;

  }

}



int main()

{

  printf("%d\n", calc());

  return 0;

}
