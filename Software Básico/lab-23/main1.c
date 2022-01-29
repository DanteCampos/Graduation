#include <stdio.h>



double sum(double limit);



void mult(int a[], double b[], int size)

{

  for (int i = 0; i < size; i++)

    b[i] = a[i] * 2.0;

}



int main()

{

  sum(10.0);

  return 0;

}
