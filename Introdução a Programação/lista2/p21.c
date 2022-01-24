#include <stdio.h>

int main(){

	float a,b,c;
	
	scanf("%f%f%f",&a,&b,&c);
	
	a = (a+b+c)/3;



	if (a>=6){

		printf("MEDIA = %.2f",a);
		printf("\nAPROVADO");
		printf("\n");

	}else{

		printf("MEDIA = %.2f",a);
		printf("\nREPROVADO");
		printf("\n");

	}

	return 0;
}


