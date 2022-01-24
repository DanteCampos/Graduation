#include <stdio.h>
#include <math.h>
#define pi 3.1415

long double circulo (void);
long double elipse (void);
long double triangulo (void);
long double trapezio (void);

int main(){

	int n;
	char op;
	long double res;
	
	scanf ("%d",&n);
	
	for (n;n>0;n--){
		
		scanf ("%*c%c",&op);
		
		if (op=='C') res=circulo();
		else if (op=='E') res=elipse();
		else if (op=='T') res=triangulo();
		else res=trapezio();
		
		printf ("%.4Lf\n",res);
	}
	
	return 0;
}

long double circulo (void){
	long double r;
	scanf ("%Lf",&r);
	return pi*r*r;
}

long double elipse (void){
	long double r,R;
	scanf ("%Lf %Lf",&R,&r);
	return R*r*pi;
}

long double triangulo (void){
	long double a,b,c,p;
	scanf ("%Lf %Lf %Lf",&a,&b,&c);
	p = (a+b+c)/2;
	return (sqrt(p*(p-a)*(p-b)*(p-c)));
}

long double trapezio (void){
	long double B,b,h;
	scanf ("%Lf %Lf %Lf",&B,&b,&h);
	return ((b+B)*h)/2;
}
