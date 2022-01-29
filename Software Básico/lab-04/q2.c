#include <stdio.h>

int odd_ones(unsigned int x) {
	unsigned char n = 0, i = 8*sizeof(unsigned int);
	
	while (i--){
		n += x & 0x1;
		x = x >> 1;
	}
	
  return n & 1;
}

int main() {
  unsigned int v;

  v = 0x01010101;

  printf("%X tem número %s de bits\n", v, odd_ones(v) ? "impar" : "par");

  v = 0x01030101;

  printf("%X tem número %s de bits\n", v, odd_ones(v) ? "impar" : "par");

  return 0;
}
