#include <stdio.h>
#include <math.h>
int main (){

	float f,d,i,v;
	
	scanf ("%f",&f);
	scanf ("%f",&d);
	scanf ("%f",&i);

	v = (f+(f*d/100)+(f*i/100))*100;
	if (v-(int)v >=0.5){
	ceil (v);
	} else {
	floor(v);
	}

	printf ("O VALOR DO CARRO E = %.2f",v/100);
	printf ("\n");
	
	return 0;
}
