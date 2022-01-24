#include <stdio.h>

int main (){

	int n,d,i,j;
	
	scanf ("%d",&n);
	
	d=i=1;

	while (i<=n){
	
		printf ("%d*%d*%d = %d",i,i,i,d);
		i++;
		for (j=2;j<i;j++){
	
			d+=2;
			printf ("+%d",d);
		}
		d+=2;
		printf ("\n");
	}	
	return 0;
}
