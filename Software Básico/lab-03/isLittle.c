#include <stdio.h>

int is_little(){
	short num = 0xABCD;
	unsigned char *p = &num;
	
	if (*p == 0xCD)
		return 1;
	else
		return 0;
}

int main () {
	if (is_little())
		printf("Little-endian\n");
	else
		printf("Big-endian\n");

  return 0;
}

