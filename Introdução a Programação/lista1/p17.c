#include <stdio.h>
#include <math.h>
int main (){

	float v,h,a;
	
	scanf ("%f %f",&h, &a);
	
	v = (h*(a*a/2)*sqrt(3));
	
	printf ("O VOLUME DA PIRAMIDE E = %.2f METROS CUBICOS",v);
	printf ("\n");
	
	return 0;
}
