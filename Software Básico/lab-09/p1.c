#include <stdio.h>

struct S {

  long  a;

  char  b;  

  int   c;

  short d;

};

void offsets(struct S *ptr) {	
	printf ("Offset de a = %ld\n", ((long int) &(ptr->a) - (long int)ptr));
	printf ("Offset de b = %ld\n", ((long int)&(ptr->b) - (long int)ptr));
	printf ("Offset de c = %ld\n", ((long int)&(ptr->c) - (long int)ptr));
	printf ("Offset de d = %ld\n", ((long int)&(ptr->d) - (long int)ptr));
	
	return;
}

struct S varS;

int main() {

  offsets(&varS);

  return 0;
}
