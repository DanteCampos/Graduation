#include <stdio.h>
#include <stdlib.h>

void selectionsort (int *v, int tam);

int main(){
	int n, tam, v[10000], i;
	
	scanf ("%d",&n);
	
	for (n;n>0;n--){
		
		scanf ("%d",&tam);
		for (i=0;i<tam;i++) scanf ("%d",&v[i]);
		selectionsort (v,tam);
		for (i=0;i<tam;i++) printf ("%d ",v[i]);
		printf ("\n");
		
	}
	
	return 0;
}

void selectionsort (int *v, int tam){
	int i,j,aux,menor,imenor;
	
	for (i=0;i<tam;i++){
		aux=menor=v[i];
		imenor=i;
		
		for (j=i;j<tam;j++){
			if (menor>v[j]){
				menor=v[j];
				imenor=j;
			}
		}
		
		v[i]=menor;
		v[imenor]=aux;
	}
	return;
}
