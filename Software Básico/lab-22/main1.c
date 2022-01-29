#include <stdio.h>



double calc1(double a, float b);



double calc1_shadow(double a, float b) 

{

  return (a+b)*(a-b);

}



int main()

{

  double a = 4.5;

  float  b = 2.125;

  printf("%f == %f\n", calc1(a, b), calc1_shadow(a, b));

  return 0;

}
