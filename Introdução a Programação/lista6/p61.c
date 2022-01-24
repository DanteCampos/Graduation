#include <stdio.h>

int main (){
	
	int i,j;
	double v[2][2],determinante;
	
	for (i=0;i<2;i++){
		for (j=0;j<2;j++){
			scanf ("%lf",&v[i][j]);
		}	
	}
	determinante=(v[0][0]*v[1][1])-(v[1][0]*v[0][1]);
	printf ("%.2lf",determinante);
	
	return 0;
}
