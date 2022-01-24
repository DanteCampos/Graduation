#include <stdio.h>
int main (){

	float a,b,c,d,e,f,x,y;

	scanf ("%f",&a);
	scanf ("%f",&b);
	scanf ("%f",&c);
	scanf ("%f",&d);
	scanf ("%f",&e);
	scanf ("%f",&f);

	x = ((c*e)-(b*f))/((a*e)-(b*d));
	y = (f-(d*x))/e;
	
	printf ("O VALOR DE X E = %.2f\n",x);
	printf ("O VALOR DE Y E = %.2f\n",y);
	printf ("\n");
	
	return 0;
}
