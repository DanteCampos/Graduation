#include <stdio.h>
int main (){

	float k,s,c,d,kw;
	scanf("%f",&s);
	scanf("%f",&k);

	kw=s*0.007;
	c = 0.007*s*k;
	d= c*0.9;
	
	printf ("Custo por kW: R$ %.2f\n",kw);
	printf ("Custo do consumo: R$ %.2f\n",c);
	printf ("Custo com desconto: R$ %.2f\n",d);

	return 0;
}
