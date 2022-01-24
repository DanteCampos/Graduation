#include <stdio.h>

int main(){

	float a,b,c;

	scanf ("%f %f %f", &a, &b, &c);

	 

	if ((a<=b) && (a<=c)){

		printf ("%.2f, ",a);

		if (b<=c){
			printf ("%.2f, ",b);
			printf ("%.2f",c);
		}else{
			printf ("%.2f, ",c);
			printf ("%.2f",b);
		}
	}else if ((b<=a) && (b<=c)){

		printf ("%.2f, ",b);
		
		if (a>c){
			printf ("%.2f, ",a);
			printf ("%.2f",c);
		}else{
			printf ("%.2f, ",c);
			printf ("%.2f",a);
		}

	}else if ((c<=a) && (c<=b)){

		printf ("%.2f, ",c);
		
		if (b<=a){
			printf ("%.2f, ",b);
			printf ("%.2f",a);
		}else{
			printf ("%.2f, ",a);
			printf ("%.2f",b);
		}
	}

	return 0;
}
