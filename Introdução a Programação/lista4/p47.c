#include <stdio.h>

int digit_count (long int n);

int main (){
	
	long int n;
	
	scanf ("%ld",&n);
	
	printf ("Numero de digitos: %d",digit_count(n));
	
	return 0;
}

int digit_count (long int n){

	int d;
	
	for (d=1;n>9;d++){
		n/=10;
	}
	return d;
}
