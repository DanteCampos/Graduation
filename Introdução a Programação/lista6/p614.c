#include <stdio.h>
#define N 1000
int main (){
	
	int l,c,i,j,m[N][N],maior=0,menor=1000,qmaior=0,qmenor=0;
	
	scanf ("%d %d",&l,&c);
	
	for (i=0;i<l;i++){
		for (j=0;j<c;j++) scanf ("%d",&m[i][j]);
	}
	
	maior=menor=m[0][0];
	
	for (i=0;i<l;i++){
		for (j=0;j<c;j++){
			if (menor>m[i][j]) menor = m[i][j];
			if (maior<m[i][j]) maior = m[i][j];
		}
	}
	
	for (i=0;i<l;i++){
		for (j=0;j<c;j++){
			if (m[i][j]==menor) qmenor++;
			if (m[i][j]==maior) qmaior++;
		}
	}
	
	printf ("%d %.2lf%%\n",menor,(((double)qmenor*100)/(l*c)));
	printf ("%d %.2lf%%\n",maior,(((double)qmaior*100)/(l*c)));
	
	return 0;
}
