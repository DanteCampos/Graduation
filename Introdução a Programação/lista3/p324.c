#include <stdio.h>

int main (){

	int a,b,c,x,d;
	
	scanf ("%d %d %d",&a,&b,&c);
	
	x=1;
	d=2;
	
	while (a*b*c!=1){
	
		if ((a%d==0)||(b%d==0)||(c%d==0)){
			printf ("%d %d %d :%d\n",a,b,c,d);
			if (a%d==0) a/=d;
			if (b%d==0) b/=d;
			if (c%d==0) c/=d;
			x*=d;
		}else d++;
	}
	printf ("MMC: %d",x);
	return 0;
}
