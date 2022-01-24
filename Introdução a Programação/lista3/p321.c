#include <stdio.h>

int main (){
	
	int n,a,b;
	
	scanf ("%d",&n);
	
	for (n;n>0;n--){
	
		scanf ("%d %d",&a,&b);
		
		a = (a%10)*100 + (a%100-a%10) + (a/100);
		b = (b%10)*100 + (b%100-b%10) + (b/100);
		
		if (a>b) printf ("%d",a);
		else printf ("%d",b);
		
		if (n-1>0) printf ("\n");
	
	}
	
	
	return 0;
}


