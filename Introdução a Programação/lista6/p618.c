#include <stdio.h>
#define N 1000
int main (){
	
	int n,i,j,a,aux,m[N][N];
	
	scanf ("%d",&n);
	
	for (i=0;i<n;i++){
		for (j=0;j<n;j++) scanf ("%d",&m[i][j]);
	}
	
	for (j=0;j<n;j++){
		for (i=0;i<n;i++){
			for (a=0;a<n-i-1;a++){
				if (m[a][j]>m[a+1][j]){
					aux=m[a][j];
					m[a][j]=m[a+1][j];
					m[a+1][j]=aux;
				}
			}
		}
	}
	
	for (i=0;i<n;i++){
		for (j=0;j<n;j++) printf ("%d ",m[i][j]);
		printf ("\n");
	}
	return 0;
}
