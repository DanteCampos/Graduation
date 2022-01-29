#include <stdlib.h>

#include <stdio.h>



void sum(short *a1, int p1, long *a2, int p2) {

  p1 = (int)a1[p1] + 1;

  p2 = (int)a2[p2] + 1;

  printf("%d\n", p1 + p2);

}
