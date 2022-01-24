#include <stdio.h>

int ind (int n);

int main (){

	int n=1,a;
	
	while (1){
	
		scanf ("%d",&a);
	
		if (a<=0) return 0;
		
		printf ("Teste %d\n%d\n\n",n,ind (a));
		
		n++;
	}
	
	
	return 0;
}

int ind (int n){

	int a,x,N=1;
	
	for (N;N<=n;N++){
	
		scanf ("%d",&a);
		
		if (a==N) x=a;
	}
	
	return x;
}
