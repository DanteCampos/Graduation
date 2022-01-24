#include <stdio.h>

int main (){

	int n,d,a=1;
	
	scanf ("%d",&n);
	
	printf ("%d = 1",n);
	
	for (d=2;d<n;d++){
	
		if (n%d==0){
			a+=d;
			printf (" + %d",d);
		}
	
	}
	
	if (n==a) printf (" = %d (NUMERO PERFEITO)",a);
	else printf (" = %d (NUMERO NAO E PERFEITO)",a);
	
	return 0;
}
