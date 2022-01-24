#include <stdio.h>
#include <math.h>

int raizesEq2Grau (int a, int b, int c);

int main (){

	int a,b,c;
	
	scanf ("%d %d %d",&a,&b,&c);
	
	switch (raizesEq2Grau(a,b,c)){
	
		case 0:
			printf ("RAIZES IMAGINARIAS");
			break;
		case 1:
			printf ("RAIZ UNICA\n");
			printf ("X1 = %.2lf",((double)-b/(2*a)));
			break;
		case 2:
			printf ("RAIZES DISTINTAS\n");
			double delta = b*b-4*a*c;
			printf ("X1 = %.2lf\n",((double)-b+sqrt(delta))/(2*a));
			printf ("X2 = %.2lf",((double)-b-sqrt(delta))/(2*a));
			break;
	}
	return 0;
}

int raizesEq2Grau (int a, int b, int c){
	
	if ((b*b-4*a*c)==0) return 1;
	else if ((b*b-4*a*c)<0) return 0;
	else return 2;	
}
