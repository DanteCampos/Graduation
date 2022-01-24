#include <stdio.h>
#define N 101
int main (){

	int n,i,j,m[N][N];
	
	scanf ("%d",&n);
	
	for (i=0;i<n+1;i++){
		for (j=0;j<n+1;j++) scanf ("%d", &m[i][j]);
	}
	
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			if (m[i][j]+m[i+1][j]+m[i][j+1]+m[i+1][j+1]>1) printf ("S");
			else printf ("U");
		}
		printf ("\n");
	}
	
	return 0;
}
