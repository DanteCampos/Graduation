#include<stdio.h>
#define TRUE (1==1)

long int fibonacci (long int n);

int main(){
	long int numero;
	
	while (scanf ("%ld", &numero) != EOF) printf ("The Fibonacci number for %ld is %ld\n", numero, fibonacci (numero));
	return 0;
}

long int fibonacci (long int n){
	if (n<3) return 1;
	else return fibonacci (n-1) + fibonacci (n-2);
}
