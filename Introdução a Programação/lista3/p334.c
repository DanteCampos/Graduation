#include <stdio.h>

int main (){
	
	int a,d;
	
	while (1){
	
		scanf ("%d",&a);
		
		if (a==1) printf ("1");
		
		if (a<=0){
		
			printf ("Fatoracao nao e possivel para o numero %d!\n",a);
		
		}else{
		
			printf ("%d = ",a);
			
			
			
			d=2;
			
			while (a>1){
				
				if (a%d==0){
					a/=d;
					printf ("%d",d);
					if (a>1) printf (" x ");
				}else d++;
			}
			
			return 0;
		}
	}
	return 0;
}




	
	
	
