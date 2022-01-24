#include <stdio.h>
int main (){

	int n,b1,b2,b3,b4,b5,b6,b7,b8;
	
	scanf ("%i",&n);

	if (n>=0 && n<=255){
	
	b1 = n%2;
	b2 = (n/2)%2;
	b3 = (n/4)%2;
	b4 = (n/8)%2;
	b5 = (n/16)%2;
	b6 = (n/32)%2;
	b7 = (n/64)%2;
	b8 = (n/128)%2;
	
	printf ("%i%i%i%i%i%i%i%i\n",b8,b7,b6,b5,b4,b3,b2,b1);

	}else{
		printf ("Numero invalido!\n");
	}
	
	return 0;
}
