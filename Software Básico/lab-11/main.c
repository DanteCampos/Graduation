#include <stdio.h>
extern char str[];
void process();

int main() {

  process();

  printf("%s\n", str);

  return 0;
}
