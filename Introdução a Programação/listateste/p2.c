#include <stdio.h>
int main (){

	float x,a1,a2,a,b1,b2,b,c1,c2,c;
	scanf ("%f",&x);

	a = (int) (x*10);
	a1 = x*10 - a;

	if (a1 >= 0.5){
		a2 = (a+1)/10;
	}
	
	if (a1 < 0.5){
		a2 = a/10;
	}
	


	b = (int) (x*100);
	b1 = x*100 - b;

	if (b1 >= 0.5){
		b2 = (b+1)/100;
	}
	
	if (b1 < 0.5){
		b2 = b/100;
	}



	c = (int) (x*1000);
	c1 = x*1000 - c;

	if (c1 >= 0.5){
		c2 = (c+1)/1000;
	}
	
	if (c1 < 0.5){
		c2 = c/1000;
	}



	printf ("%f\n",a2);
	printf ("%f\n",b2);
	printf ("%f\n",c2);

	return 0;
}
