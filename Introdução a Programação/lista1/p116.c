#include <stdio.h>
int main (){

	int x,a,b,c,y;
	scanf("%i",&x);

	a=x/100;
	b=((x-(a*100))/10);	
	c=x-((a*100)+(b*10));

	y=(c*100)+(b*10)+a;
	printf ("%i\n",y);

	return 0;
}
