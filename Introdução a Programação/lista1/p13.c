#include <stdio.h>
int main (){

	float r,h,a;
	scanf("%f",&r);
	scanf("%f",&h);
	
	a=2*(3.14159*r*r)+(2*3.14159*r*h);

	printf ("O VALOR DO CUSTO E = %.2f\n",a*100);
	printf ("\n");

	return 0;
}
