#include <stdio.h>

int main (){

	int n,k,a,b,l;

	scanf ("%d %d",&n,&a);	
	
	l=1;
	k=1;
	while (n>1){
	
		scanf ("%d",&b);
		
		if (b==a){
			l++;
			k=l;
		}else{
			k=l;
			l=1;
		}
		
		a=b;
	
		n--;
	}
	
	printf ("O comprimento do segmento de numeros iguais e: %d",k);

	return 0;
}


