#include <stdio.h>

int main (){

	int n,a,k,b,l;
	
	scanf ("%d",&n);
	
	b=0;
	k=0;
	l=0;
	
	while (n>0){
	
		scanf ("%d",&a);
		
		if (a>b){
			k++;
			if (k>l) l=k;
		}else{
			if (k>l) l=k;
			
			k=1;
		}
		
		b=a;
		
		n--;
	
	}

	printf ("O comprimento do segmento crescente maximo e: %d",l);

	return 0;
}


