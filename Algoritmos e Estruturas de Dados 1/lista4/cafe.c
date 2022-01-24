#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int hora;
	int minuto;
}pessoa;

void selectionsort (pessoa *pessoas, int n);

int main (){
	int n,testes,iguais,maisiguais,i;
	pessoa *pessoas;
	
	scanf ("%d",&testes);
	
	while (testes>0){
		testes--;
		
		scanf ("%d",&n);
		
		pessoas = (pessoa*) malloc (n* sizeof (pessoa));
		
		for (i=0;i<n;i++) scanf ("%d %d",&pessoas[i].hora,&pessoas[i].minuto);
		
		selectionsort (pessoas,n);
		
		iguais=1;
		maisiguais=1;
		for (i=1;i<n;i++){
			if (pessoas[i-1].hora==pessoas[i].hora && pessoas[i-1].minuto==pessoas[i].minuto){
				iguais++;
				if (iguais>maisiguais) maisiguais=iguais;
			}
			else iguais=1;
		}
		
		printf ("%d\n",maisiguais);
		
		free (pessoas);
	}
	
	
	
	return 0;
}

void selectionsort (pessoa *pessoas, int n){
	int i,j,imenor,menorhora,menorminuto;
	pessoa aux;
	
	for (i=0;i<n;i++){
		imenor=i;
		menorhora=pessoas[i].hora;
		menorminuto=pessoas[i].minuto;
		
		for (j=i+1;j<n;j++){
			if (pessoas[j].hora < menorhora){
				menorhora=pessoas[j].hora;
				menorminuto=pessoas[j].minuto;
				imenor=j;
			}else if (pessoas[j].hora == menorhora){
				if (pessoas[j].minuto < menorminuto){
					menorhora=pessoas[j].hora;
					menorminuto=pessoas[j].minuto;
					imenor=j;
				}
			}
		}
		
		if (i != imenor){
			aux=pessoas[i];
			pessoas[i]=pessoas[imenor];
			pessoas[imenor]=aux;
		}
	}
	return;
}
