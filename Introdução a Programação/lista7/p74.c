#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point{
	double a;
	double b;
	double c;
	double d;
	double norma;
}point;

point leponto ();
void veponto (point ponto);

int main(){
	int i=0,j=0,n=0;
	point *ponto=0,aux;
	
	scanf ("%d",&n);
	
	ponto = (point*) malloc (n*sizeof(point));
	
	for (i=0;i<n;i++) ponto[i]=leponto ();
	
	for (i=0;i<n-1;i++){
		for (j=0;j<n-i-1;j++){
			if (ponto[j].norma > ponto[j+1].norma){
				aux=ponto[j];
				ponto[j]=ponto[j+1];
				ponto[j+1]=aux;
			}
		}
	}
	
	for (i=0;i<n;i++) veponto (ponto[i]);
	
	free (ponto);
	
	return 0;
}

point leponto (){
	
	point ponto;
	
	scanf ("%lf",&ponto.a);
	scanf ("%lf",&ponto.b);
	scanf ("%lf",&ponto.c);
	scanf ("%lf",&ponto.d);
	ponto.norma=0;
	ponto.norma+=ponto.a*ponto.a;
	ponto.norma+=ponto.b*ponto.b;
	ponto.norma+=ponto.c*ponto.c;
	ponto.norma+=ponto.d*ponto.d;
	ponto.norma=sqrt(ponto.norma);
	
	return ponto;
}

void veponto (point ponto){
	printf ("Vetor: ");
	printf ("(%.2lf, %.2lf, %.2lf, %.2lf) ",ponto.a,ponto.b,ponto.c,ponto.d);
	printf ("Norma: %.2lf\n",ponto.norma);
}
