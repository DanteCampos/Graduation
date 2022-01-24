#include <stdio.h>
#include <math.h>
int main (){

	float a,b,c,A;
	
	scanf ("%f",&a);
	scanf ("%f",&b);
	scanf ("%f",&c);

	A = sqrt (((a+b+c)/2)*(((a+b+c)/2)-a)*(((a+b+c)/2)-b)*(((a+b+c)/2)-c));
	
	printf ("A AREA DO TRIANGULO E = %.2f",A);
	printf ("\n");
	
	return 0;
}
