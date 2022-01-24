#include <stdio.h>
int main (){

	int x,x1,x2,x3,x4;
	
	scanf ("%i",&x);
	x1 = x/100;
	x2 = (x-x1*100)/10;
	x3 = x-x1*100-x2*10;
	x4 = (x1+(x2*3)+(x3*5))/7;

	printf ("O NOVO NUMERO E = %i\n",x1*1000 + x2*100 + x3*10 + x4);
	printf ("%i\n",x4);
	
	return 0;
}
