#include <stdio.h>

int separaDigitos (int n);

int main (){
	
	int n;
	
	scanf ("%d",&n);
	
	printf ("%d",separaDigitos(n));

	return 0;
}

int separaDigitos (int n){

	return n/100+((n%100)/10)*10+(n%10)*100;
}
