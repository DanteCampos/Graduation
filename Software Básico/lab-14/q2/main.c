#include <stdio.h>

#define LEN 4
#define LIM 10

int filtro(unsigned char x, short lim);
int i = 0;
unsigned char vet[LEN] = {12,3,20,8};

int main() {

  for ( ; i < LEN; i++) {
    printf("%d\n", filtro(vet[i], LIM));
  }

  return 0;
}
