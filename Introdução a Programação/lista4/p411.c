#include <stdio.h>

double raiz (double n);
double absoluto (double n);

int main (){
	
	double n,e,r,*pr;
	
	scanf ("%lf %lf",&n,&e);
	r=1;
	*pr=r;
	
	while (absoluto(n-r*r)>e){
	
	raiz (n)
	
	}
	
	
	return 0;
}

double raiz (double n){
	double r;
	
	r=*pr;
	r= (r+n/r)/2;
	*pr=r;

}

double absoluto (double n){
	if (n<0) n=-n;
	return n;
}
