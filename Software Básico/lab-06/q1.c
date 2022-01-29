#include <stdio.h>

char trocar_sinal(char x) {
  return (~x)+1;
}

int main(void) {

  printf("%d\n", trocar_sinal(1));
  printf("%d\n", trocar_sinal(42));
  printf("%d\n", trocar_sinal(127));

  return 0;

}
