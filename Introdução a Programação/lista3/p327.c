#include <stdio.h>

int main (){

	int n,p;
	float a,b;

	while (1){
	
		scanf ("%d",&n);
		if (n<1) return 0;
		
		if (n==1) n--;
		
		p=0;
	
		scanf ("%f",&a);
		
		for (n--;n>0;n--){
			
			scanf ("%f",&b);
			
			if ((b>a)&&(p==0)) p=0;
			else{
				p=1;
			}
			a=b;
		}
		
		if (p==0) printf ("ORDENADA\n");
		else printf ("DESORDENADA\n");
	}


	return 0;
}
