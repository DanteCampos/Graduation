#include <stdio.h>

int main(){

	int x,x1,x2,x3,x4,x5;

	scanf ("%d",&x);
	
	if (x>99999){
		printf ("NUMERO INVALIDO");
	}else{

		x1 = x/10000;
		x2 = x/1000 - x1*10;
		x3 = x/100 - x1*100 - x2*10;
		x4 = x/10 - x1*1000 - x2*100 - x3*10;
		x5 = x - (x1*10000) - (x2*1000) - (x3*100) - (x4*10);

		if (x>9999){
	
			if (x==(x1+x2*10+x3*100+x4*1000+x5*10000)){
				printf ("PALINDROMO");
			}else{
				printf ("NAO PALINDROMO");
			}

		}else if (x>999){
	
			if (x==(x2+x3*10+x4*100+x5*1000)){
				printf ("PALINDROMO");
			}else{
				printf ("NAO PALINDROMO");
			}

		}else if (x>99){
	
			if (x==(x3+x4*10+x5*100)){
				printf ("PALINDROMO");
			}else{
				printf ("NAO PALINDROMO");
			}

		}else if (x>9){
	
			if (x==(x4+x5*10)){
				printf ("PALINDROMO");
			}else{
				printf ("NAO PALINDROMO");
			}

		}else{
			printf ("PALINDROMO");
		}

	}

	return 0;
}
