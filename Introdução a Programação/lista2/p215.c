#include <stdio.h>

int main(){

	int c,d,r;
	
	scanf ("%d %d %d", &c,&d,&r);
	
	if ( (c<7) && (d>50) && (r>80000) ){
		printf ("ACO DE GRAU = 10");
	}else if ( (c<7) && (d>50) ){
		printf ("ACO DE GRAU = 9");
	}else if (c<7){
		printf ("ACO DE GRAU = 8");
	}else{
		printf ("ACO DE GRAU = 7");
	}

	return 0;
}
