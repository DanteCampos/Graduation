#include <stdio.h>
#define N 100
int main (){
	
	int i,j,c,l,valor,borda,m[N][N];
	
	scanf ("%d %d %d %d",&c,&l,&borda,&valor);
	
	for (i=0;i<borda;i++){
		for (j=0;j<c;j++){
			m[i][j]=valor;
			m[l-i-1][j]=valor;
		}
	}
	
	for (j=0;j<borda;j++){
		for (i=0;i<l;i++){
			m[i][j]=valor;
			m[i][c-j-1]=valor;
		}
	}
	
	printf ("P2\n%d %d\n255\n",c,l);
	
	for (i=0;i<l;i++){
		for (j=0;j<c;j++) printf ("%d ",m[i][j]);
		printf ("\n");
	}
	
	return 0;
}
