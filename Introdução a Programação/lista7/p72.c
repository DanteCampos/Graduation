#include <stdio.h>
#include <stdlib.h>
#define T 51

int strings_iguais (char *a, char *b);

typedef struct produto{
	char *nome;
	float valor;
}produto;

int main (){
	
	int m,n,i,j,c,quant;
	float soma;
	char string [T];
	produto *x;
	
	scanf ("%d",&n);
	
	while (n>0){
		
		soma=0;
		
		scanf ("%d",&m);
		x = (produto*) malloc (m*sizeof(produto));
		
		for (i=0;i<m;i++){
			x[i].nome = (char*) malloc(T*sizeof(char));
			scanf ("%s %f",x[i].nome, &x[i].valor);
		}
		
		scanf ("%d",&c);
		
		for (i=0;i<c;i++){
			scanf ("%s %d",string, &quant);
			for (j=0;j<m;j++){
				if (strings_iguais(string,x[j].nome)==0){
					soma+=quant*x[j].valor;
					break;
				}
			}
		}
		
		printf ("R$ %.2f\n",soma);
		for (i=0;i<m;i++) free (x[i].nome);
		free (x);
		n--;
	}
	return 0;
}
//retorna 0 para verdadeiro e 1 para falso
int strings_iguais (char *a, char *b){
	int i;
	
	for (i=0;a[i]!='\0'&&b[i]!='\0';i++){
		if (a[i]!=b[i]) return 1;
	}
	return 0;
}
