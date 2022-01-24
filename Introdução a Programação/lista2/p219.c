#include <stdio.h>

int main(){

	float a,b,c,d;

	scanf ("%f %f %f %f",&a,&b,&c,&d);

	if ((a<=b) && (a<=c) && (a<=d)){
		printf ("%.2f",a);

		if ((b<=c) && (b<=d)){
			printf (", %.2f",b);

			if (c<=d){
				printf (", %.2f",c);
				printf (", %.2f",d);

			}else{
				printf (", %.2f",d);
				printf (", %.2f",c);
			}

		}else if ((c<=b) && (c<=d)){
			printf (", %.2f",c);

			if (b<=d){
				printf (", %.2f",b);
				printf (", %.2f",d);

			}else{
				printf (", %.2f",d);
				printf (", %.2f",b);
			}

		}else{
			printf (", %.2f",d);

			if (b<=c){
				printf (", %.2f",b);
				printf (", %.2f",c);

			}else{
				printf (", %.2f",c);
				printf (", %.2f",b);
			}

		}

	}else if ((b<=a) && (b<=c) && (b<=d)){
		printf ("%.2f",b);

		if ((a<=c) && (a<=d)){
			printf (", %.2f",a);

			if (c<=d){
				printf (", %.2f",c);
				printf (", %.2f",d);

			}else{
				printf (", %.2f",d);
				printf (", %.2f",c);
			}

		}else if ((c<=a) && (c<=d)){
			printf (", %.2f",c);

			if (a<=d){
				printf (", %.2f",a);
				printf (", %.2f",d);

			}else{
				printf (", %.2f",d);
				printf (", %.2f",a);
			}

		}else{
			printf (", %.2f",d);

			if (a<=c){
				printf (", %.2f",a);
				printf (", %.2f",c);

			}else{
				printf (", %.2f",c);
				printf (", %.2f",a);
			}

		}


	}else if ((c<=a) && (c<=b) && (c<=d)){
		printf ("%.2f",c);

		if ((b<=a) && (b<=d)){
			printf (", %.2f",b);

			if (a<=d){
				printf (", %.2f",a);
				printf (", %.2f",d);

			}else{
				printf (", %.2f",d);
				printf (", %.2f",a);
			}

		}else if ((a<=b) && (a<=d)){
			printf (", %.2f",a);

			if (b<=d){
				printf (", %.2f",b);
				printf (", %.2f",d);

			}else{
				printf (", %.2f",d);
				printf (", %.2f",b);
			}

		}else{
			printf (", %.2f",d);

			if (b<=a){
				printf (", %.2f",b);
				printf (", %.2f",a);

			}else{
				printf (", %.2f",a);
				printf (", %.2f",b);
			}

		}

	}else{
		printf ("%.2f",d);

		if ((b<=c) && (b<=a)){
			printf (", %.2f",b);

			if (c<=d){
				printf (", %.2f",c);
				printf (", %.2f",a);

			}else{
				printf (", %.2f",a);
				printf (", %.2f",c);
			}

		}else if ((c<=b) && (c<=a)){
			printf (", %.2f",c);

			if (b<=d){
				printf (", %.2f",b);
				printf (", %.2f",a);

			}else{
				printf (", %.2f",a);
				printf (", %.2f",b);
			}

		}else{
			printf (", %.2f",a);

			if (b<=c){
				printf (", %.2f",b);
				printf (", %.2f",c);

			}else{
				printf (", %.2f",c);
				printf (", %.2f",b);
			}

		}

	}

	return 0;
}
