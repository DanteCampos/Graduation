#include <stdio.h>
int main (){
	
	int r,a1,a10,a50,a100;

	scanf ("%i",&r);

	a1 = 0;
	a10 = 0;
	a50 = 0;
	a100 = 0;
	

	while (r%10 != 0){
		r = r-1;
		a1 = a1+1;
	}


	while (r%50 != 0){
		r = r-10;
		a10 = a10+1;
	}
	
	
	while (r%100 != 0){
		r = r-50;
		a50 = a50+1;
	}

	
	a100 = r/100;

	printf ("NOTAS DE 100 = %i\n",a100);
	printf ("NOTAS DE 50 = %i\n",a50);
	printf ("NOTAS DE 10 = %i\n",a10);
	printf ("NOTAS DE 1 = %i\n",a1);
	printf ("\n");

	return 0;
}
