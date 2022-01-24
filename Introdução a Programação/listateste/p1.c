#include <stdio.h>

int main(){
	int a,b,c,s;
	scanf ("%d %d %d",&a,&b,&c);

	if (a>9){
		printf("DIGITO INVALIDO");
	}

	else if (b>9){
		printf("DIGITO INVALIDO");
	}

	else if (c>9){
		printf("DIGITO INVALIDO");
	}

	else{
		s=100*a+10*b+c;
		printf("%d, %d",s,s*s);
	}

	return 0;
}


