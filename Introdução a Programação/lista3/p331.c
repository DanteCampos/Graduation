#include <stdio.h>
#include <math.h>

unsigned int fat(int n);

int main (){
	
	int N,n;
	double cos,X,x;
	
	scanf ("%lf %d",&X,&N);
	
	x = X;
	
	for (n=cos=1;n<=N;n++){
		cos += pow(-1,n)*pow(x,2*n)/fat(2*n);
	}
	
	printf ("cos(%.2lf) = %.6lf",X,cos);
	
	return 0;
}




unsigned int fat(int n){

	unsigned int f = 1;
	
	for (n; n > 1; --n){
		f *= n;
	}
	
	return f;
}
