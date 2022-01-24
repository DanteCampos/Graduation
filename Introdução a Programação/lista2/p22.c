#include <stdio.h>

int main(){

	int a,b,c;
	
	scanf ("%d",&a);
	scanf ("%d",&b);
	scanf ("%d",&c);

	if (a > 9 || b > 9 ||c > 9){
		printf("DIGITO INVALIDO");
	}else{

	a = a*100 + b*10 + c;
	b = a*a;

	printf ("%d, %d", a,b);

	}


	return 0;
}


