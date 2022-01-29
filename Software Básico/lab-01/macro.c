#include <stdio.h>

#define inc(x, y)   x++; y++
#define dobro(x)   (x + x)
#define calc(x, y) (x + y * 2)

int main()
{
  int a = 10;
  int b = 20;
  if (a > 15)
     inc(a, b);

  printf("Linha 1: a = %d, b = %d\n", a, b);

//a=10 b=20

  a = 10;
  b = 20;
  a = dobro(++b);

  printf("Linha 2: a = %d, b = %d\n", a, b);

//a=42 b=21

  a = 10;
  b = 20;
  b = calc(a, 1 + 5);

  printf("Linha 3: a = %d, b = %d\n", a, b);

//a=10 b=22

  return 0;
}

