#include <stdio.h>
#define N 1000
int main (){
	
	int m[N][N],n,i,j;
	
	scanf ("%d",&n);
	
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			scanf ("%d",&m[i][j]);
			if (i==j) printf ("%d\n",m[i][j]);
		}
	}
	return 0;
}
