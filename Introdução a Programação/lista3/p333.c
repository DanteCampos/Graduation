#include <stdio.h>
#include <math.h>

unsigned long long int fat(int n);

int main (){
	
	int N,n;
	double seno,X,x;
	
	scanf ("%lf %d",&X,&N);
	
	x = X;
	seno=x;
	for (n=1;n<=N;n++){
	
		seno += pow(-1,n)*pow(x,((2*n)+1))/fat((2*n)+1);
	}
	
	printf ("seno(%.2lf) = %.6lf\n",X,seno);
	
	return 0;
}




unsigned long long int fat(int n){

	unsigned long long int f = 1;
	
	for (n; n > 1; --n){
		f *= n;
	}
	
	return f;
}
