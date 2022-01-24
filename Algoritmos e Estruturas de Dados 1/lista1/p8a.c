#include <stdlib.h>
#include <stdio.h>
int main (){
	
	int nn,ns,d,a,n;
	
	scanf ("%d",&n);
	nn=ns=n;
	
	if (n==0 || n==1){
		printf ("N\n");
		nn--;
	}
	
	d=2;
	while (d<n){
		if (n%d==0) break;
		else d++;
	}
	
	if (d==n){
		printf ("S\n");
		ns--;
	}else{
		printf ("N\n");
		nn--;
	}
	
	while (ns>0 || nn>0){
		scanf ("%d",&a);
		if (a<0) a=-a;
		
		if (a==0 || a==1){
			nn--;
			printf ("N\n");
			continue;
		}
		
		d=2;
		while (d<a){
			if (a%d==0) break;
			else d++;
		}
		
		if (d==a){
			printf ("S\n");
			ns--;
		}else{
			printf ("N\n");
			nn--;
		}
	}
	
	return 0;
}
