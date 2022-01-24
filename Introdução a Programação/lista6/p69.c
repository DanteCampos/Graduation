#include <stdio.h>
#define N 100
int main (){
	
	int l,c,i,j,contador=0;
	
	scanf ("%d %d",&l,&c);
	
	for (i=0;i<l;i++){
		for (j=0;j<c;j++){
			if (i%2==0){
				if (j%2==0) printf ("0 ");
				
				else{
					contador++;
					printf ("%d ",contador);
				}
			}else{
				if (j%2==0){
					contador++;
					printf ("%d ",contador);
					
				}else printf ("0 ");
			}
		}
		printf ("\n");
	}
	return 0;
}
