#include <stdlib.h>
#include <stdio.h>
int main (){
	
	int n,m,i,p,d,*v,j;
	
	scanf ("%d %d",&n,&m);
	
	v = (int*) malloc (n*sizeof(int));
	
	for (i=0;i<n;i++) v[i]=0;
	
	for (i=0;i<m;i++){
		scanf ("%d %d",&p, &d);
		for (j=0;j<n;j++){
			if (((j+1-p)%d)==0) v[j]=1;
		}
	}
	
	for (i=0;i<n;i++) printf ("%d\n",v[i]);
	
	free (v);
	
	return 0;
}
