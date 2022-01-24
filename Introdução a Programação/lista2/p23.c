#include <stdio.h>

int main(){

	int c;
	float m,valor;
	char t;
	
	scanf("%i %f %c",&c, &m, &t);

	if (t=='C'){ //comercial

		if (m <= 80){
			valor = 500;
		}else{
			valor = 500 + (m-80)*0.25;

		}

	}else if (t=='I'){ //industrial

		if (m <= 100){
			valor = 800;
		}else{
			valor = 800 + (m-100)*0.04;
		}

	}else{ //residencial

		valor = 5 + 0.05*m;
	}


	printf("CONTA = %i\n",c);
	printf("VALOR DA CONTA = %.2f\n", valor);
	
	return 0;
}


