#include <stdio.h>

int main (){
	
	int m,n,a,b;
	
	scanf ("%d %d",&m,&n);
	
	if (m+n<4) return 0;
	
	a=2;
	b=1;


	while (a<=m){
		
		while ((b<a)&&(b<=n)){
		
			printf ("(%d,%d)",a,b);
		
			b++;
			if ((b<a)&&(b<=n)) printf ("-");
		}
	
		a++;
		b=1;
		
		if (a<=m) printf ("\n");
	}
	
	return 0;
}


