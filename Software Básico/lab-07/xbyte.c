#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int string2num(char *s, int base) {
  int a = 0;
  for ( ; *s; s++){
  
  	if(*s>='a' && *s<='z')
  		a = a*base + (*s-'a'+10);
  	else if (*s>='A' && *s<='Z')
  		a = a*base + (*s-'A'+10);
  	else
  		a = a*base + (*s-'0');
  }
  
  return a;
}

int xbyte(unsigned int word, int bytenum) {
	int result;
	void *pAuxWord = &word, *pAuxResult = &result;
	unsigned char *pWord = pAuxWord, *pResult = pAuxResult;
	unsigned char mask = *(pWord+bytenum);
	
	printf ("MASK = 0x%X\n", mask);
	
	if ((mask/128)%2 == 1){
		if ((mask/64)%2 == 0){ 
			//Caso 2
			printf ("Caso 2\n");
			result = 0; //Enche de 0
			*(pResult + 1) = mask; // byte na posição 1 recebe o número extraído
		}else{ 
			//Caso 3
			printf ("Caso 3\n");
			result = 0xFFFFFFFF; //Enche de 1
			*(pResult + 2) = mask; // byte na posição 2 recebe o número extraído
		}
	}else{
		//CASO 1
		printf ("Caso 1\n");
		result = 0xFFFFFFFF; //Enche de 1
		*(pResult + 0) = mask; // byte na posição 0 recebe o número extraído
	}
	
	return result;
}

int main(int argc, char **argv) {
  int x;

  if (argc != 3) {
    printf ("Uso: %s <hexadecimal> <bytenum>\n", argv[0]);
    exit(1);
  }

  x = xbyte(string2num(argv[1], 16), atoi(argv[2]));
  printf ("0x%08X\n", x);

  return 0;

}
