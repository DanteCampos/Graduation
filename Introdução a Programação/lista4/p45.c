#include <stdio.h>

int fibonacci (int t1,int t2, int n);

int main (){

	int t1,t2,n;
	
	scanf ("%d %d %d",&t1,&t2,&n);
	
	printf ("%d",fibonacci(t1,t2,n));

	return 0;
}

int fibonacci (int t1,int t2, int n){
	
	for (n;n>1;n--){
		t2=t2+t1;
		t1=t2-t1;
	}
	return t1;
}
