#include <stdio.h>
#include <stdlib.h>

void printavetor (int *v,int inicio, int final);
void bubblesort (int *v, int tam);
void selectionsort (int *v, int tam);
void insertionsort (int *v, int tam);
void mergejunta (int *v,int inicio,int meio, int final);
void mergesort(int *v, int inicio, int final);

int main(){
	int n, *v,i,metodo;

	printf ("Tamanho do vetor: ");
	scanf ("%d",&n);
	printf ("\nElementos do vetor: ");
	
	v = (int*) malloc (n * sizeof (int));
	
	for (i=0;i<n;i++) scanf ("%d",&v[i]);
	
	printf ("\n");
	printf ("Método de ordenação:\n\n");
	printf ("1 Bubble sort\n");
	printf ("2 Selection sort\n");
	printf ("3 Insertion sort\n");
	printf ("4 Merge sort\n");
	printf ("\n");
	
	while (1){
	
			scanf ("%d",&metodo);
			if (metodo>4 || metodo<1) continue;
			
			switch (metodo){
				case 1:
					printf ("Bubble sort:\n\n");
					bubblesort (v,n);
					break;
			
				case 2:
					printf ("Selection sort:\n\n");
					selectionsort (v,n);
					break;
					
				case 3:
					printf ("Insertion sort:\n\n");
					insertionsort (v,n);
					break;
					
				case 4:
					printf ("Merge sort:\n\n"); 
					mergesort (v,0,n-1);
					break;
					
				default:
					break;
			}
			
			break;		
	}
		
	free (v);
	
	return 0;
}

void bubblesort (int *v, int tam){
	int i,j,aux;
	
	for (i=0;i<tam;i++){
	
		printavetor (v,0, tam);
	
		for (j=0;j<tam-i-1;j++){
			if (v[j] > v[j+1]){
			
				aux=v[j];
				v[j]=v[j+1];
				v[j+1]=aux;
			}
		}
	}
	
	return;
}

void selectionsort (int *v, int tam){
	int i,j,aux,menor,imenor;
	
	for (i=0;i<tam;i++){
		
		printavetor (v,0, tam);
		
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

void insertionsort (int *v, int tam){
	int i,j,aux;
	
	printavetor (v,0, tam);
	
	for (i=1;i<tam;i++){
		aux=v[i];
		for (j=i-1;(j>=0) && (aux<v[j]);j--){
			v[j+1]=v[j];
			printavetor (v, 0,tam);
		}
		v[j+1]=aux;
		printavetor (v, 0,tam);
	}
	
	return;
}

void printavetor (int *v,int inicio ,int final){
	int j;
	
	printf ("Vetor: ");
	for (j=inicio;j<final;j++) printf ("%d ",v[j]);
	printf ("\n");
	
	return;
}


void mergesort(int *v, int inicio, int fim){
	int meio;
	
	printavetor(v, inicio, fim+1);
	
	if (inicio < fim ){
		
		meio = ((fim+inicio)/2);
		mergesort (v,inicio,meio);
		mergesort (v,meio+1,fim);
		mergejunta (v,inicio, meio, fim);
	}
	
	return;
}

void mergejunta (int *v,int inicio,int meio, int fim){
	int aux[fim-inicio+1],p1=inicio,p2=meio+1,i,j,tam=fim-inicio+1;
	
	for (i=0;i<tam;i++){
		if (!(p1>meio) && !(p2>fim)){
			if(v[p1]<v[p2]) aux[i]=v[p1++];
			else aux[i]=v[p2++];
		}else if (!(p1>meio)) aux[i]=v[p1++];
		else aux[i]=v[p2++];
	}
	
	for (i=0;i<tam;i++) v[i+inicio]=aux[i];
	
	printavetor (v,inicio, fim+1);
	return;
}
