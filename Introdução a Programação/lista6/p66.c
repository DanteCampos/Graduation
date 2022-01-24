#include <stdio.h>
#define N 2
int main (){
	
	int i,j,a,l,c;
	float m[N][N],q[N][N];
	
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			scanf ("%f",&m[i][j]);
			q[i][j]=0;
		}
	}
	
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			for (a=0;a<N;a++){
				q[i][j]+=m[i][a]*m[a][j];
			}
		}
	}
	
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			printf ("%.3f",q[i][j]);
			if (j+1<N) printf (" ");
			else printf ("\n");
		}
	}
	
	return 0;
}
