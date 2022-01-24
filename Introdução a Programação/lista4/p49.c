#include <stdio.h>

int somaDivisores (int n);

int main (){
	
	int n,d;
	
	scanf ("%d",&n);
	
	printf ("%d = 1",n);
	
	for (d=2;d<n;d++){
		if (n%d==0) printf (" + %d",d); 
	}

	printf (" = %d",somaDivisores(n));
	if (somaDivisores(n)==n) printf (" (NUMERO PERFEITO)");
	else printf (" (NUMERO NAO E PERFEITO)");

	return 0;
}

int somaDivisores (int n){
	
	int d,x=1;

	for (d=2;d<n;d++){
		if (n%d==0) x+=d;
	}
	return x;
}
