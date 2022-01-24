#include <stdio.h>
#include <math.h>

int next_power (int a,int b);

int main (){

	int n,p;
	
	scanf ("%d %d",&n,&p);
	
	printf ("%d -> %d^%d = %.0lf",n,next_power(n,p),p,pow(next_power(n,p),p));
	
	return 0;
}

int next_power (int a,int b){
	int i=1;
	
	for (i=1;fabs(pow(i,b)-a)>fabs(pow(i+1,b)-a);i++){
		if (b==0) break;
	}
	return i;
}

