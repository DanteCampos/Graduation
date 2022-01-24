#include <stdio.h>

int main(){

	float x;
	char a;
	
	scanf ("%f",&x);
	
	if (x >= 9){
	
		a = 'A';		

	}else if (x >= 7.5){

		a = 'B';

	}else if (x >= 6){

		a = 'C';

	}else{

		a = 'D';

	}

	printf("NOTA = %.1f CONCEITO = %c\n",x,a);

	return 0;
}


