#include <stdio.h>
int main (){
	
	int n,a,contador,x,i,num,b;
	
	scanf ("%d",&n);
	
	for (i=0;i<n;i++){
		scanf ("%d",&a);
		
		x=1;
		contador=1;
		b=a;
		num=0;
		
		while (b>0){
			contador *= 10;
			b /=4;
		}
		
		while (x<=contador){
			num += x*(a%4);
			a /=4;
			x *= 10;
		}
		
		printf ("%d\n",num);
	}
	
	return 0;
}
