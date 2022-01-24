#include <stdio.h>
#include <math.h>
int main (){

	float ax,ay,bx,by,d;
	
	scanf ("%f",&ax);
	scanf ("%f",&ay);
	scanf ("%f",&bx);
	scanf ("%f",&by);

	d = sqrt (pow(ax-bx,2)+pow(ay-by,2))*100;
	
	if (d-(int)d >=0.5){
	ceil (d);
	} else {
	floor(d);
	}

	printf ("A DISTANCIA ENTRE A e B = %.2f\n",d/100);
	printf ("\n");
	
	return 0;
}
