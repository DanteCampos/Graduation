#include <stdio.h>
#define N 200
int main (){

	int i,j,n,x,y,r,fundo,cor,tipo,m[N][N];
	
	
	scanf ("%d %d",&n,&fundo);
	
	for (i=0;i<n;i++){
		for (j=0;j<n;j++) m[i][j]=fundo;
	}
	
	while (1){
		
		scanf ("%d %d",&x,&y);
		if (x==-1 &&  y==-1) break;
		
		scanf ("%d %d %d",&cor,&r,&tipo);
		
		if (x+r>n-1 || y+r>n-1 || x-r<0 || y-r<0) continue;
		
		for (i=y-r;i<=y+r;i++) m[i][x-r]=m[i][x+r]=cor; //bordas horizontais
		for (j=x-r;j<=x+r;j++) m[y-r][j]=m[y+r][j]=cor; //bordas verticais
		
		if (tipo==2){ //preencher
			for (i=y-r+1;i<y+r;i++){ //só preenche as linhas que não são bordas
				for (j=x-r+1;j<x+r;j++) m[i][j]=cor; //só preenche colunas que não são bordas
			}
		}
	}
	
	printf ("P2\n%d %d\n255\n",n,n);
	
	for (i=0;i<n;i++){
		for (j=0;j<n;j++) printf ("%d ",m[i][j]);
		printf ("\n");
	}
	
	return 0;
}
