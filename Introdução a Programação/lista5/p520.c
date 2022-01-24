#include <stdio.h>

int main (){
	
	int n,min,i,k,a=0,v[1000];
	
	scanf ("%d %d",&n,&k);
	
	for (i=0;i<n;i++){
		scanf ("%d",&v[i]);
		
		if (v[i]>0) a++;
	}
	
	if ((n-a)<k) printf ("SIM\n");
	else{
		printf ("NAO\n");
		for (i=n-1;i>=0;i--){
			if (v[i]<=0) printf ("%d\n",i+1);
		}
	}
	
	return 0;
}
