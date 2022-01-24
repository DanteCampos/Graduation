#include <stdio.h>

int estoura(int n);

int main (){
	int n,k;
	
	scanf ("%d %d",&n,&k);
	
	printf ("%d",estoura(n));
	
	return 0;
}

int estoura(int n){
	if (n==0) return 0;
	else return 1 + estoura(n/2);
}
