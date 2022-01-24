#include <stdio.h>
#include <math.h>

int main (){
	
	double n;
	
	unsigned long int num,denom,a,i;
	
	scanf ("%lf",&n);
	
	
	num=n*1000000;
	denom=1000000;
	
	for (i=1;i<=denom;i++){
	
		if ((denom%i==0)&&(num%i==0)){
			denom/=i;
			num/=i;
			i=1;
		}
	}

	printf ("%lu/%lu",num,denom);
	
	return 0;
}




	
	
	
