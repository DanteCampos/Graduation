#include <stdio.h>

void show(const char *str, int value, int *r);
int ret = 0;
int main(){

   show("Hello", 123, &ret);
   printf("Retorno: %d\n", ret);

   return 0;
}
