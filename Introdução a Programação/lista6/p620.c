#include <stdio.h>
#define N 1000
int main (){
	
	int i,j,l,c,m[N][N],aux,maior,menor,imenor=0,imaior=0,jmenor=0,jmaior=0;
	
	scanf ("%d %d",&l,&c);
	
	for (i=0;i<l;i++){
		for (j=0;j<c;j++) scanf ("%d",&m[i][j]);
	}
	
	maior=menor=m[0][0];
	
	for (i=0;i<l;i++){
		for (j=0;j<c;j++){
			if (maior<m[i][j]){
				maior=m[i][j];
				imaior=i;
				jmaior=j;
			}
			
			if (menor>m[i][j]){
				menor=m[i][j];
				imenor=i;
				jmenor=j;
			}
		}
	}
	
	aux=m[imenor][jmenor];
	m[imenor][jmenor]=m[imaior][jmaior];
	m[imaior][jmaior]=aux;
	
	for (i=0;i<l;i++){
		for (j=0;j<c;j++) printf ("%d ",m[i][j]);
		printf ("\n");
	}
	return 0;
}
