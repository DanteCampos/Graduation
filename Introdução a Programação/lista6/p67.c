#include <stdio.h>
#define N 6
int main (){
	
	int i,j,m[N][N],soma,maior=-100;
	
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			scanf ("%d",&m[i][j]);
		}
	}
	
	for (i=0;i<N-2;i++){
		for (j=0;j<N-2;j++){
			soma=m[i][j]+m[i][j+1]+m[i][j+2]+m[i+1][j+1]+m[i+2][j]+m[i+2][j+1]+m[i+2][j+2];
			if (soma>maior) maior=soma;
		}
	}
	
	printf ("%d",maior);
	
	return 0;
}
