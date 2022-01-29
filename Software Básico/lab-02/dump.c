#include <stdio.h>

void dump(void *addr, int n) {
  unsigned char *p = addr;
  while (n--) {
    printf("%p - %02x\n", p, *p);
    p++;
  }
}


int main() {
  short i[12] = {0xACDB,1,2,3,4,-5,-1};
  dump(&i, sizeof(i));
  return 0;
}
