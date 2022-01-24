#include <stdio.h>

int main (){
	
	unsigned long int n,pot;
	int bit,p;
	
	while(scanf ("%lu",&n)!=EOF){
		
		if (n==0) printf ("0");
		else{
			p=0;
			pot=4294967296;
					
			for (pot;pot>0;pot/=2){
				
				bit = n/pot;
				
				if (bit==1) p=1;
				
				if (p==1) printf ("%d",bit);
				
				n=n%pot;
			}
		}
		printf ("\n");
	}
	return 0;
}
