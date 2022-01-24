#include <stdio.h>

int main (){
	
	int m;
	float h,v;
	
	do{
		scanf ("%d %f %f",&m,&h,&v);
		getchar();
	
		if (m==0) return 0;
		
		printf ("%d %.2lf\n",m,((double)h*v));
		
	}while (m!=0);
		
	return 0;
}


