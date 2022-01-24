#include <stdio.h>

int main(){
	int n,m,a,tempototal,menortempo,posicao,i,j;
	
	
	scanf ("%d %d",&n, &m);
	
	posicao=0;
	for (i=0;i<n;i++){
		tempototal=0;
		for (j=0;j<m;j++){
			scanf ("%d",&a);
			tempototal+=a;
		}
		
		if (tempototal==m){
			posicao=i;
			break;
		}
		
		if (i<1) menortempo=tempototal;
		else{
			if (tempototal < menortempo){
				menortempo=tempototal;
				posicao=i;
			}
		}
	}
	
	printf ("%d\n",posicao+1);
	
	return 0;
}
