#include <stdio.h>
#include <stdlib.h>
int main (){
	int n,m,a,b,f=1,i,j,**p;
	scanf ("%d %d",&n,&m);
	//n pessoas m pares
	
	p=malloc (n*sizeof(int*));
	for (i=0;i<n;i++) p[i]=malloc (n*sizeof(int));
	for (i=0;i<n;i++){
		for (j=0;j<n;j++) p[i][j]=0;
	}
	
	for (i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		p[a-1][b-1]=1;
		p[b-1][a-1]=1;
	}
	
	for (i=0;i<n-1;i++){
		if (p[i][i+1]==0) f++;
	}

	printf ("%d",f);
	for (i=0;i<n;i++) free (p[i]);
	free (p);
	return 0;
}


