#include <stdio.h>

// Indica que as variáveis existem e são definidas em outro lugar

extern char c;
extern int i;
extern unsigned int ui;
extern long l;
extern unsigned long ul;
extern int v[5];
extern unsigned short us;

void aux();

int main(){
  aux();
  
  printf("c  = %d\n", c);
  printf("us = %u\n", us);
  printf("i  = %d\n", i);
  printf("ui = %u\n", ui);
  printf("l  = %ld\n", l);
  printf("lu = %lu\n", ul);
  printf("v  = {%d, %d, %d, %d, %d}\n", v[0], v[1], v[2], v[3], v[4]);

  return 0;
}
