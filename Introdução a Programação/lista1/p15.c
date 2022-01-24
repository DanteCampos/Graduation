#include <stdio.h>
int main (){

	float a,b,c,d,x;
	
	scanf ("%f",&a);
	scanf ("%f",&b);
	scanf ("%f",&c);
	scanf ("%f",&d);
	
	x = (a*d)-(b*c);
	
	printf ("O VALOR DO DETERMINANTE E = %.2f\n",x);
	printf ("\n");
	
	return 0;
}
