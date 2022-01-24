#include <stdio.h>
#include <stdlib.h>

void insertionsort (int *v,int tam);

int main(){
	
	int n,*v,i,k,l;
	
	scanf ("%d",&n);
	
	v = (int*) malloc (n*sizeof(int));
	
	for (i=0;i<n;i++) scanf ("%d",&v[i]);
	
	scanf ("%d %d",&l,&k);
	
	insertionsort (v,n);
	
	printf ("%d",v[l-1]+v[k-1]);
	
	free (v);
	return 0;
}

void insertionsort (int *v,int tam){
	int aux,i,j;
	
	for (i=1;i<tam;i++){
		aux=v[i];
		for (j=i-1;(j>=0) && (aux<v[j]);j--) v[j+1]=v[j];
		v[j+1]=aux;
	}
	return;
}
