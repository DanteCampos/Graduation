#include <stdio.h>
#define N 1000
int main (){
	
	int i,j,n,m[N][N],trans[N][N],tr=0;
	
	scanf ("%d",&n);
	
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			scanf ("%d",&m[i][j]);
			trans[j][i]=m[i][j];
			if (i==j) tr+=m[i][j];
		}
	}
	
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			m[i][j]*=tr;
			m[i][j]+=trans[i][j];
			printf ("%d ",m[i][j]);
		}
		printf ("\n");
	}
	
	return 0;
}
