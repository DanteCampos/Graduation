#include <stdio.h>
#include <math.h>

int main(){

	float a,b,c,x1,x2,raizdedelta;
	
	scanf ("%f %f %f",&a,&b,&c);

	if (b*b-4*a*c < 0){

		printf ("RAIZES IMAGINARIAS");

	}else if (b*b-4*a*c == 0){

		printf ("RAIZ UNICA");

		x1 = -b/(2*a);

		printf ("\nX1 = %.2f",x1);

	}else{

		printf ("RAIZES DISTINTAS");

		raizdedelta = sqrt (b*b-4*a*c);
		
		x1 = (-b+raizdedelta)/(2*a);

		x2 = (-b-raizdedelta)/(2*a);
		
		if (x1<=x2){

			printf ("\nX1 = %.2f\nX2 = %.2f",x1,x2);

		}else{
		
			printf ("\nX1 = %.2f\nX2 = %.2f",x2,x1);

		}
	}

	return 0;
}
