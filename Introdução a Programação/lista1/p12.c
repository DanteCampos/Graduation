#include <stdio.h>
int main (){

	float X,Y,f,c;
	scanf("%f",&f);
	scanf("%f",&c);

	X=(5*(f-32))/9;
	Y=c*25.4;

	printf ("O VALOR EM CELSIUS = %.2f\n",X);
	printf ("A QUANTIDADE DE CHUVA E = %.2f\n",Y);
		printf ("\n");

	return 0;
}
