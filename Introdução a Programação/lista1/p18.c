#include <stdio.h>
int main (){

	int h,m,s;
	
	scanf ("%i",&h);
	scanf ("%i",&m);
	scanf ("%i",&s);

	s = s+(60*m)+(3600*h);
	
	printf ("O TEMPO EM SEGUNDOS E = %i",s);
	printf ("\n");
	
	return 0;
}
