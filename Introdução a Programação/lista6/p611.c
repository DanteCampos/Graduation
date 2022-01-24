#include <stdio.h>
#define N 1000
int main (){
	
	int l,c,m[100][100],p=0,i,j;
	
	scanf ("%d %d",&l,&c);
	
	for (i=0;i<l;i++){
		for (j=0;j<c;j++) scanf ("%d",&m[i][j]);
	}
	
	for (i=0;i<l;i++){
		for (j=0;j<c;j++){
			
			if (m[i][j]!=1111) continue;
			
			if (j==0){ //na coluna da extrema esquerda
				if (m[i][c-1]!=0) continue; //da esquerda
				
				if (m[i][j+1]!=0) continue; //da direita
				
			}else if (j==c-1){ //na coluna da extrema direita
				if (m[i][j-1]!=0) continue; //da esquerda
				if (m[i][0]!=0) continue; //da direita
								
			}else{ //colunas dos meios
				if (m[i][j-1]!=0) continue; //da esquerda
				if (m[i][j+1]!=0) continue; //da direita
				
			}
			
			
			if (i==0){ //na primeira linha
				if (m[l-1][j]!=4) continue; //de cima
				if (m[i+1][j]!=8) continue; //de baixo
				
			}else if (i==l-1){ //na última linha
				if (m[i-1][j]!=4) continue; //de cima
				if (m[0][j]!=8) continue; //de baixo
				
			}else{ //nas linhas dos meios
				if (m[i-1][j]!=4) continue; //de cima
				if (m[i+1][j]!=8) continue; //de baixo
			}
			
			//se chegou aqui, todos os campos estão corretos
			
			printf ("%d %d\n",i,j);
			p=1; //controlador para saber se wally foi achado ao menos uma vez
		}
	}
	
	if (p==0) printf ("WALLY NAO ESTA NA MATRIZ\n");
	
	
	return 0;
}
