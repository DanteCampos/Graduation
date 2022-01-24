#include <stdio.h>

int main(){

	int i;
	float a,b,c;

	scanf ("%d %f %f %f", &i,&a,&b,&c);

	if (i == 1){

		if ((a<=b) && (a<=c)){
			printf ("%.2f",a);

			if (b<=c){
				printf (" %.2f",b);
				printf (" %.2f",c);
			}else{
				printf (" %.2f",c);
				printf (" %.2f",b);
			}
		}else if ((b<=a) && (b<=c)){
			printf ("%.2f",b);

			if (a<=c){
				printf (" %.2f",a);
				printf (" %.2f",c);
			}else{
				printf (" %.2f",c);
				printf (" %.2f",a);
			}

		}else{
			printf ("%.2f",c);

			if (b<=a){
				printf (" %.2f",b);
				printf (" %.2f",a);
			}else{
				printf (" %.2f",a);
				printf (" %.2f",b);
			}

		}

	}else if (i == 2){
		
		if ((a>=b) && (a>=c)){
			printf ("%.2f",a);

			if (b>=c){
				printf (" %.2f",b);
				printf (" %.2f",c);
			}else{
				printf (" %.2f",c);
				printf (" %.2f",b);
			}
		}else if ((b>=a) && (b>=c)){
			printf ("%.2f",b);

			if (a>=c){
				printf (" %.2f",a);
				printf (" %.2f",c);
			}else{
				printf (" %.2f",c);
				printf (" %.2f",a);
			}

		}else{
			printf ("%.2f",c);

			if (b>=a){
				printf (" %.2f",b);
				printf (" %.2f",a);
			}else{
				printf (" %.2f",a);
				printf (" %.2f",b);
			}

		}
	}else{
		if (((a<=b) && (a>=c)) || ((a>=b) && (a<=c))){
			printf ("%.2f",a);

			if (b>=c){
				printf (" %.2f",b);
				printf (" %.2f",c);
			}else{
				printf (" %.2f",c);
				printf (" %.2f",b);
			}
		}else if (((b<=a) && (b>=c)) || ((b>=a) && (b<=c))){
			printf ("%.2f",b);

			if (a>=c){
				printf (" %.2f",a);
				printf (" %.2f",c);
			}else{
				printf (" %.2f",c);
				printf (" %.2f",a);
			}

		}else{
			printf ("%.2f",c);

			if (b>=a){
				printf (" %.2f",b);
				printf (" %.2f",a);
			}else{
				printf (" %.2f",a);
				printf (" %.2f",b);
			}

		}
	}

	return 0;
}
