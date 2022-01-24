#include <stdio.h>

int main (){
	
	double v,a,b,l;
	int n;
	
	scanf ("%lf %lf %lf",&v,&a,&b);
	
	if (a>=b){
		print ("INTERVALO INVALIDO");
		return 0;
	}
	
	
	while (a<=b){
	
		l = a*n-200-(0.05*n);
		if (l<0) l=0;
		
		printf ("V: %.2lf, N: %d, L: %.2lf",a,n,l);
		a++;
	}
	
	printf ("Melhor valor final: %.2lf",);
	printf ("Lucro %.2lf",);
	printf ("Numero de ingressos: %d",);
	
	return 0;
}


