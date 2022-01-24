#include <stdio.h>
#include <math.h>

//Programa para converter binário em decimal

int main(){

	int x,digitos,y,contador,z;

	printf ("Digite o número em decimal para converter para binário: ");
	scanf ("%d",&x);
	printf("\n");

	if (x>999999999){
		printf("Impossível contabilizar");

	}else{
		if (x>=0){

			contador = x;

		}else{

			contador = -x;

		}


		digitos = 0;


		while (contador > 0){

			contador = contador/2;
			digitos++;

		}
	

		if (x==0){

			printf ("0\n");

		}else if (x<0){
			printf ("-");
		}else{}

			while (digitos>=1){
			
				z=x/(pow(2,digitos-1));
				y=z%2;
				digitos--;

				if (x<0){
					y*=-1;
				}else{}
					printf("%d",y);

		}
	}

	printf ("\n");
	printf ("\n");
	return 0;
}


