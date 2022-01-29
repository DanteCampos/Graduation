#include <stdio.h>



char constante();

void init(long *vl, int *vi, char factor);



int main() {

  char c;  // usar registrador

  int i;

  long l;



  c = constante();

  init(&l, &i, c);



  printf("Soma: %ld\n", l+i+c);



  return 0;

}
