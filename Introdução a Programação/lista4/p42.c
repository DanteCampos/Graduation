#include <stdio.h>

double le_numero();

int main (){

	int n,N;
	double a=0;
	
	scanf ("%d",&n);
	
	for (N=n;N>0;N--){
		a += le_numero();
	}
	
	printf ("%.2lf",a/n);
	
	return 0;
}

double le_numero(){

	double n;

	scanf ("%lf",&n);

	return n;
}
