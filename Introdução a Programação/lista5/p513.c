#include <stdio.h>

int main (){
	
	int n,i,j,m;
	
	scanf ("%d",&n);
	
	int v[n];
	
	for (i=0;i<n;i++) scanf ("%d",&v[i]);
	
	for (i=0;i<n;i++){
		for (j=i;j<n;j++){
			if (v[j]<v[i]){
				m=v[j];
				v[j]=v[i];
				v[i]=m;
			}
		}
	}
	
	for (i=0;i<n;i++) printf ("%d\n",v[i]);
	
	
	
	return 0;
}
