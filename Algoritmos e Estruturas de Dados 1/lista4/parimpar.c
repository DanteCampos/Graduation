#include <stdio.h>
#include <stdlib.h>

void insertionsort (int *v, int tam);

int main(){
	int n, v[100], i;
	
	scanf ("%d",&n);
	
	for (i=0;i<n;i++) scanf ("%d",&v[i]);
	insertionsort (v,n);
	
	for (i=0;i<n;i++){
		if (v[i]%2==0) printf ("%d\n",v[i]);
	}
	
	for (i=n-1;i>=0;i--){
		if (v[i]%2!=0) printf ("%d\n",v[i]);
	}
	
	return 0;
}

void insertionsort (int *v, int tam){
	int i,j,aux;
	
	for (i=1;i<tam;i++){
		aux=v[i];
		for (j=i;j>0;j--){
			v[j]=v[j-1];
			if (aux>v[j]) break;
		}
		v[j]=aux;
	}
	
	return;
}
