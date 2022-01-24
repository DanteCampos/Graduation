#include <stdio.h>

int main (){
	
	int n;
	long int a,b,c,i,j,x;
	
	scanf ("%d",&n);
	
	if ((n<1)||(n>9)) return 0;
	
	a=220;
	b=c=0;
	
	for (i=1;i<a;i++){
		
		if(a%i==0) b+=i;
	}
	
	for (j=1;j<b;j++){
	
		if (b%j==0) c+=j;
	}
	
	if (c==a) printf ("(%ld,%ld)",a,b);
	
	a++;
	n--;
	x=b;
	
	while (n>0){
	
		b=c=0;
	
		for (i=1;i<a;i++){
		
			if(a%i==0) b+=i;
		}
		
		for (j=1;j<b;j++){
		
			if (b%j==0) c+=j;
		}
		
		if ((c==a)&&(c!=x)&&(a!=b)){
		
		n--;
		printf ("\n(%ld,%ld)",a,b);
		x=b;
		}
		
		a++;
		

		
	} 
	
	return 0;
}
