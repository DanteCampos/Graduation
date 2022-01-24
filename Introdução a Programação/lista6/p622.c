#include <stdio.h>
#define N 9
#define T 3
int main (){
	
	int i,j,a,b,soma,n,m[N][N];
	
	for (i=0;i<N;i++){
		for (j=0;j<N;j++) scanf ("%d",&m[i][j]);
	}
	
	for (i=0;i<N;i++){ //verificar se linhas e colunas têm números repetidos
		soma=0;
		
		for (j=0;j<N;j++){
			soma+=m[i][j];
			soma+=m[j][i];	
		}
		
		if (soma!=90){
			printf ("invalido\n");
			return 0;
		}
	}
	
	for (i=0;i<n-T+1;i++){ //verificar se regiões 3x3 têm números repetidos
		for (j=0;j<n-T+1;j++){
			soma=0;
			
			for (a=0;a<T;a++){
				for (b=0;b<T;b++) soma+=m[i+a][j+b];
			}
			
			if (soma!=45){
				printf ("invalido\n");
				return 0;
			}
		}
	}
	
	printf ("valido\n");
	return 0;
}
