#include <stdio.h>

double compute_pi (int i);

int main (){
	
	int a;
	
	scanf ("%d",&a);
	
	printf ("%.12lf",compute_pi (a));
	
	return 0;
}

double compute_pi (int i){

	double pi;
	int a,b;

	pi=2;
	a=0;
	b=1;

	for (i;i>0;i--){
		
		if (a<b) a=b+1;
		else b=a+1;
		
		pi*=((double)a/b);
	}
	return pi;
}
