#include <stdio.h>

int main(){

	int h;
	float x;
	
	scanf ("%d",&h);
	
	x = (h/3)*10 + (h%3)*5;

	printf("O VALOR A PAGAR E = %.2f\n",x);

	return 0;
}


