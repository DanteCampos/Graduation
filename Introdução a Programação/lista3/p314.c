#include <stdio.h>

int main (){
	
	int n,a,b,f;
	
	scanf ("%d",&n);
	
	a=0;
	f=1;
	
	if (n<2){
		printf ("Campeonato invalido!");
	}else{
		
		while (a<n){
			
			a++;
			b=a+1;
			
			while ((b>a)&&(b<=n)){
				printf ("Final %d: Time%d X Time%d\n",f,a,b);
				f++;
				b++;
			}
			
		}	
	}
	return 0;
}


