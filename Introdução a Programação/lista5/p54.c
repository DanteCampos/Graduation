#include <stdio.h>

int main (){
	
	int n,i;
	
	scanf ("%d",&n);
	
	int v[n];
	
	for (i=0;i<n;i++) scanf ("%d",&v[i]);
	
	for (i=n-1;i>=0;i--) printf ("%d ",v[i]);
	
	return 0;
}
