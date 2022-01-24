#include <stdio.h>

int main(){

	float x;
	
	scanf ("%f",&x);
	
	if (x<=300){
		x *= 1.5;
	}else{
		x *= 1.3;
	}

	printf("SALARIO COM REAJUSTE = %.2f\n",x);

	return 0;
}


