#include <stdio.h>

void show(const char *str, int value, int *r){
   *r = printf("%s: %d\n", str, value);
}
