#include <stdio.h>
#include <stdlib.h>

int bubblesort (int *v, int tam);

int main(){
	int n, tam, v[1000], i;
	
	scanf ("%d",&n);
	
	for (n;n>0;n--){
		
		scanf ("%d",&tam);
		for (i=0;i<tam;i++) scanf ("%d",&v[i]);
		printf ("%d\n",bubblesort(v,tam));
		
	}
	
	return 0;
}

int bubblesort (int *v, int tam){
	int i,j,aux,contador=0;
	
	for (i=0;i<tam;i++){
	
		for (j=0;j<tam-i-1;j++){
			if (v[j] > v[j+1]){
			
				aux=v[j];
				v[j]=v[j+1];
				v[j+1]=aux;
				contador++;
			}
		}
	}
	
	return contador;
}
