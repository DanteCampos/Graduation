#include <stdio.h>

int absoluto (int n);

int main (){
	
	int t,n,i,j,distrel,dist;
	
	scanf ("%d",&t);
	
	for (t;t>0;t--){
		
		scanf ("%d",&n);
		
		int v[n];
		
		for (i=0;i<n;i++) scanf ("%d",&v[i]);
		
		dist = absoluto(v[0]-v[1]);
		
		for (i=0;i<n-1;i++){
			for (j=i+1;j<n;j++){
				distrel=absoluto(v[i]-v[j]);
				if (distrel<dist) dist=distrel;
			}
		}
		
		printf ("%d %d\n",dist,n*n);
		
	}
	
	return 0;
}

int absoluto (int n){
	
	if (n<0) n=-n;
	return n;
}
