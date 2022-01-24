#include <stdio.h>
#define N 10
int main (){
	
	int m[N][N],i,j,l,c;
	
	while (1){ //pegar número válido de linhas
		scanf ("%d",&l);
		if (l>0&&l<11) break;
	}
	
	while (1){ // pegar número válido de colunas
		scanf ("%d",&c);
		if (c>0&&c<11) break;
	}
	
	for (i=0;i<l;i++){ //ler elementos da matriz
		for (j=0;j<c;j++){
			scanf ("%d",&m[i][j]);
		}
	}
	
	for (i=0;i<l;i++){ // imprimir elementos da matriz
		printf ("linha %d: ",i+1);
		for (j=0;j<c;j++){
			printf ("%d",m[i][j]);
			if (j+1<c) printf (","); //só imprime "," se houver próximo elemento
		}
		printf ("\n"); //pula uma linha quando terminar de imprimir elementos da linha
	}
	return 0;
}
