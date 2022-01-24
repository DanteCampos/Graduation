#include <stdio.h>
int main (){

	double v,s,W,m,a,t;
	
	scanf ("%lf",&m);
	scanf ("%lf",&a);
	scanf ("%lf",&t);

	v = a*t;
	s = a*t*t/2;
	W = 1000*m*v*v/2;

	printf ("VELOCIDADE = %.2lf\n",v*3.6);
	printf ("ESPACO PERCORRIDO = %.2lf\n",s);
	printf ("TRABALHO REALIZADO = %.2lf\n",W);
	printf ("\n");
	
	return 0;
}
