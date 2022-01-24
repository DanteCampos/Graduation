#include <stdio.h>

int selectionsort (int *v, int n);
int insertionsort (int *v, int n);

int main(){
	int i,n,v1[100],v2[100];
	
	
	scanf ("%d",&n);
	
	for (i=0;i<n;i++){
		scanf ("%d",&v1[i]);
		v2[i]=v1[i];
	}
	
	printf ("%d",insertionsort(v2,n)-selectionsort(v1,n));
	
	
	return 0;
}

int selectionsort (int *v, int n){
	int trocas=0,i,j,aux,menor,imenor;
	
	for (i=0;i<n;i++){
		menor=v[i];
		imenor=i;
		
		for (j=i+1;j<n;j++){
			if (v[j]<menor){
				menor=v[j];
				imenor=j;
			}
		}
		
		if (i!=imenor){
			aux=v[imenor];
			v[imenor]=v[i];
			v[i]=aux;
			trocas++;
		}
	}
	
	return trocas;
}

int insertionsort (int *v, int n){
	int i,j,aux,trocas=0;
	
	for (i=1;i<n;i++){
		aux=v[i];
		for (j=i-1;(j>=0) && (aux<v[j]);j--){
			v[j+1]=v[j];
			trocas++;
		}
		v[j+1]=aux;
		trocas++;
	}
	
	return trocas;
}


