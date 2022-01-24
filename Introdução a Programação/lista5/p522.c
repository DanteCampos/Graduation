#include <stdio.h>

int main (){
	
	int n,i,j,x=0,y=0;
	
	scanf ("%d",&n);
	
	int v[n];
	
	for (i=0;i<n;i++) scanf ("%d",&v[i]);
	
	for (i=0;i<n;i++){
	
		x=0;
		
		for (j=0;j<n;j++){
			if (v[i]!=v[j]) x++;	
		}
		
		if (x==n-1) y++;
	}
	

	printf ("%d\n",y);
	
	return 0;
}
