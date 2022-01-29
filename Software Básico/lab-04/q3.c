#include <stdio.h>

/*
unsigned int convertB2L(unsigned int x) {
	unsigned int answer = 0, mask = 0xFF;
	
	answer = answer | ((x & mask) << 24);
	mask = mask << 8;
	
	answer = answer | ((x & mask) << 8);
	mask = mask << 8;
	
	answer = answer | ((x & mask) >> 8);
	mask = mask << 8;
	
	answer = answer | ((x & mask) >> 24);
	
	return answer;
}
*/

unsigned int convertB2L(unsigned int x) {
	unsigned int answer = 0, aux, mask = 0xFF, i = sizeof(unsigned int);
	while (i--){
		aux = x & (mask << (sizeof(unsigned int) - i)*8);
		answer = answer | (aux >> (sizeof(unsigned int) - i)*8) << (i - 1)*8;
	}
	return answer;
}


int main() {

  unsigned int b = 0x12AB34CD;

  unsigned int l = convertB2L(b); 

  printf("b = 0x%08X\n", b);

  printf("l = 0x%08X\n", l); //CD34AB12

  return 0;

}


