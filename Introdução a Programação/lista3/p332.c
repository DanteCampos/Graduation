#include <stdio.h>
#include <math.h>

unsigned int fat(int n);

int main (){
	
	int N,n;
	double e,X,x;
	
	scanf ("%lf %d",&X,&N);
	
	x = X;
	
	for (n=e=1;n<=N;n++){
		e += pow(x,n)/fat(n);
	}
	
	printf ("e^%.2lf = %.6lf",X,e);
	
	return 0;
}




unsigned int fat(int n){

	unsigned int f = 1;
	
	for (n; n > 1; --n){
		f *= n;
	}
	
	return f;
}
