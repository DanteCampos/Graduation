#include <stdio.h>

#include <math.h>

float calc2(float a, float b);



float calc2_shadow(float a, float b)

{

   double e = a + cos(b);

   printf("a = %f, b = %f, e = %f\n", a, b, e);

   return b;

}



int main()

{

  float a = 3.0;

  float b = 0.0;

  float r1 = calc2(a, b);

  float r2 = calc2_shadow(a, b);

  printf("%f == %f\n", r1, r2);

  return 0;

}
