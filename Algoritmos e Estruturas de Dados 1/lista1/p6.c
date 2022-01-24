#include <stdlib.h>
#include <stdio.h>
int main (){
	
	int n=0, i=0, tipo=0, t=0, *v=NULL, menor=0;
	
	scanf ("%d %d", &n, &t);
	
	v = (int*) malloc (t*sizeof(int));
	menor = n;
	
	for (i=0;i<t;i++) v[i]=0;
	
	for (i=0;i<n;i++){
		scanf ("%d",&tipo);
		v[tipo-1]++;
	}
	
	for (i=0;i<t;i++){
		if (menor>v[i]) menor=v[i];
	}
	
	printf ("%d",menor);
	
	free (v);
	
	return 0;
}
