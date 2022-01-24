#include <stdio.h>
#include <stdlib.h>

void ordena (int *v, int n);
int buscaqmenores (int a,int *v,int n);

int main (){
	int n,i,*v,q,moedas;
	
	scanf ("%d",&n);
	v = (int*) malloc (n*sizeof(int));
	for (i=0;i<n;i++) scanf ("%d",&v[i]);
	ordena(v,n);
	
	scanf ("%d",&q);
	for (i=0;i<q;i++){
		scanf ("%d",&moedas);
		printf ("%d\n",buscaqmenores(moedas,v,n));
	}
	
	free(v);
	return 0;
}

void ordena (int *v, int n){
	int i,j,aux;
	
	for (i=0;i<n;i++){
		for (j=0;j<n-i-1;j++){
			if (v[j]>v[j+1]){
				aux=v[j];
				v[j]=v[j+1];
				v[j+1]=aux;
			}
		}
	}
	
	return;
}

int buscaqmenores (int a,int *v,int n){
	int i;
	for (i=0;i<n;i++){
		if (v[i]>a) break;
	}
	return (i);
}
