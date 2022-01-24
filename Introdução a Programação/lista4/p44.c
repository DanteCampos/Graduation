#include <stdio.h>

unsigned long int fat (unsigned int n);

int main (){

	int n;
	
	scanf ("%u",&n);

	printf ("%d! = %lu",n,fat (n));

	return 0;
}

unsigned long int fat (unsigned int n){

	unsigned long int f;

	for (f=1;n>1;n--){
		f*=n;
	}
	
	return f;
}
