#include <stdio.h>
#define N 10
int main (){
	
	int i,j,a,n,k;
	double m[N][N],r[N][N],multi[N][N];
	
	scanf ("%d %d",&n,&k);
	
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			scanf ("%lf",&m[i][j]);
			r[i][j]=m[i][j];
		}
	}
	
	for (k--;k>0;k--){
	
		for (i=0;i<n;i++){
			for (j=0;j<n;j++) multi[i][j]=0;
		}
	
		for (i=0;i<n;i++){
			for (j=0;j<n;j++){
				for (a=0;a<n;a++){
					multi[i][j]+=r[a][j]*m[i][a];
				}
			}
		}
		
		for (i=0;i<n;i++){
			for (j=0;j<n;j++) r[i][j]=multi[i][j];
		}	
	}
	
	for (i=0;i<n;i++){
		for (j=0;j<n;j++) printf ("%.3lf ",r[i][j]);
		printf ("\n");
	}
	
	return 0;
}
