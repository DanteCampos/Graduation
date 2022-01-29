#include <ctype.h>
#include <stdio.h>

int string2num(char *s, unsigned char base) {
  int a = 0;
  for ( ; *s; s++){
  
  	if(*s>='a' && *s<='z')
  		a = a*base + (*s-'a'+10);
  	else if (*s>='A' && *s<='Z')
  		a = a*base + (*s-'A'+10);
  	else
  		a = a*base + (*s-'0');

  	printf("*s = %d, a = %d\n",*s,a);
  	
  }
  return a;
}

int main () {
  printf("==> %d\n", string2num("1234",10));
  printf("==> %d\n", string2num("1234",10) + 1);
  printf("==> %d\n", string2num("1234",10) + string2num("1",10));
  
  printf("%d\n", string2num("777", 8));
  printf("%d\n", string2num("777", 10));
  
  printf("%d\n", string2num("1a", 16));
  printf("%d\n", string2num("a09b", 16));
  printf("%d\n", string2num("k09b", 36));

  return 0;
}

