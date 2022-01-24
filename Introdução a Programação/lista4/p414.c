#include <stdio.h>

int inverte (int n);

int main (){
	
	int n,a,b;
	
	scanf ("%d",&n);
	
	for (n;n>0;n--){
		
		scanf ("%d %d",&a,&b);
		
		if (inverte(a)>inverte(b)) printf ("%d",inverte(a));
		else printf ("%d",inverte(b));
		printf ("\n");
	}
	
	return 0;
}

int inverte (int n){
	return n/100+((n%100)/10)*10+(n%10)*100;
}
