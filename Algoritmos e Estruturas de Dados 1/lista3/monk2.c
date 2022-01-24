#include <stdio.h>

int main (){
	int a,b,c,k,n,x;
	scanf ("%d",&n);
	while (n>0){
		scanf ("%d %d %d %d",&a,&b,&c,&k);
		
		//a,b e c sempre serão positivos, logo, a*x*x + b*x >= k-c
		
		x=k-c;
		if (x<0) x=0;
		
		printf ("%d",x);
		
		n--;
	}
	
	return 0;
}
