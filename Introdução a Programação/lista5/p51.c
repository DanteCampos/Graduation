#include <stdio.h>

int main (){
	
	int a,n,i,m;
	
	scanf ("%d",&n);
	
	int v[n];
	
	for (i=0;i<n;i++) scanf ("%d",&v[i]);
	
	scanf ("%d",&m);
	
	while (m>0){
		scanf ("%d",&a);
		for (i=0;i<n;i++){
			if (v[i]==a){
				printf ("ACHEI\n");
				break;
			}
		}
		if (i==n) printf ("NAO ACHEI\n");
		m--;
	}
	return 0;
}
