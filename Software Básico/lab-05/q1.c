#include <stdio.h>

unsigned char rotate_left(unsigned char x, int n){
	n %= 8;
	
	while (n--)
		x = (x << 1) | (0x80 & x) >> 7;

	return x;
}


int main (){
	char teste = 0x61;
	
	printf ("ROTACIONANDO 0x%X EM 1 bit: 0x%X\n", teste, rotate_left(teste, 1));
	printf ("ROTACIONANDO 0x%X EM 2 bit: 0x%X\n", teste, rotate_left(teste, 2));
	printf ("ROTACIONANDO 0x%X EM 7 bit: 0x%X\n", teste, rotate_left(teste, 7));
	
	return 0;
}
