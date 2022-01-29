#include <stdio.h>



void mult(int a[], double b[], int size);



double sum(double limit)

{

  int i = 3;

  double s = 0.0;

  int vi[4] = {5,6,7,8};

  double vd[4];



  mult(vi, vd, i+1);



  while (i >= 0) {

    s += vd[i--];

    if (s > limit)

      printf("Soma %f maior que o limite %f\n", s, limit);

  }

  return s;

}
