#include <stdio.h>

int main (){
	
	int n,a;
	
	scanf ("%d",&n);
	a=2;
	
	if (n<0){
		printf ("Numero invalido!");
		return 0;
	}
	
	if ((n==1)||(n==0)){
		printf ("NAO PRIMO");
		return 0;
	}
	
	while (a<n){
	
		if (n%a==0){
			printf ("NAO PRIMO");
			return 0;
		}else{
			a++;
		}
	}
	
	printf ("PRIMO");
	
	return 0;
}


