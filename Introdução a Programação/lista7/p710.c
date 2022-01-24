#include <stdio.h>
#include <stdlib.h>

typedef struct termo{
	float coeficiente;
	unsigned int expoente;
}termo;

int main(){
	
	int n=0,n1=0,n2=0,i=0,j=0,a=0,b=0,q=0;
	unsigned int aux=0;
	char sinal=0;
	termo *poli1=NULL, *poli2=NULL, *polires=NULL;
	
	scanf ("%d%*c",&n);
	
	for (i=0;i<n;i++){
		scanf ("%c%*c",&sinal);
		
		scanf ("%d",&n1);
		poli1 = (termo*) malloc (n1*sizeof(termo));
		for (j=0;j<n1;j++) scanf ("%f %u",&poli1[j].coeficiente, &poli1[j].expoente);
		
		scanf ("%d",&n2);
		poli2 = (termo*) malloc (n2*sizeof(termo));
		for (j=0;j<n2;j++){
			scanf ("%f %u",&poli2[j].coeficiente, &poli2[j].expoente);
			if (sinal=='-') poli2[j].coeficiente*=(-1); //se for subtração de polinômios, os coeficientes do polinômio 2 já têm os sinais invertidos
		}
		
		polires = (termo*) malloc ((n1+n2)*sizeof(termo));
		
		b=0;
		q=0;
		
		for (j=0;j<n1;j++){ //coloca no polinômio resultado os expoentes do polinômio 1 sem repetir, enquanto zera os coeficientes do polinômio resultado
			polires[j].coeficiente=0;
			for (a=0;a<j;a++){
				if (polires[a].expoente == poli1[b].expoente) break;
			}
			if (a==j){
				polires[j].expoente = poli1[b].expoente;
				q++;
			}
			b++;
		}
		
		b=0;
		
		for (j=q;j<n1+n2;j++){//coloca no polinômio resultado os expoentes do polinômio 2 sem repetir, enquanto zera os coeficientes do polinômio resultado
			polires[j].coeficiente=0;
			for (a=0;a<j;a++){
				if (polires[a].expoente == poli2[b].expoente) break;
			}
			if (a==j){
				polires[j].expoente = poli2[b].expoente;
				q++;
			}
			b++;
		}
		
		q++; //q tinha começado com 0, então deve somar +1 pra representar a quantidade de termos do polinômio resultado
		
		for (j=0;j<q;j++){ //ordena os expoentes do polinônimo resultado em ordem decrescente
			for (a=0;a<q-1-j;a++){
				if (polires[a].expoente<polires[a+1].expoente){
					aux=polires[a].expoente;
					polires[a].expoente = polires[a+1].expoente;
					polires[a+1].expoente = aux;
				}
			}
		}
		
		for (j=0;j<n1;j++){ //procura expoentes do polinômio resultado iguais aos do polinômio 1 e adiciona seus respectivos coeficientes
			for (a=0;a<q;a++){
				if (poli1[j].expoente==polires[a].expoente){
					polires[a].coeficiente+=poli1[j].coeficiente;
					break;
				}
			}
		}
		
		for (j=0;j<n2;j++){//procura expoentes do polinômio resultado iguais aos do polinômio 2 e adiciona seus respectivos coeficientes
			for (a=0;a<q;a++){
				if (poli2[j].expoente==polires[a].expoente){
					polires[a].coeficiente+=poli2[j].coeficiente;
					break;
				}
			}
		}
		
		for (j=0;j<q;j++){ //printa o coeficiente vezes X elevado ao expoente, se o expoente for 0, só mostra o coeficiente
			if (polires[j].coeficiente == 0) continue;
			else if (polires[j].coeficiente<0){
				polires[j].coeficiente*=(-1);
				printf ("-%.2f",polires[j].coeficiente);
				if (polires[j].expoente!=0) printf("X^%d",polires[j].expoente);
			}
			else{
				printf ("+%.2f",polires[j].coeficiente);
				if (polires[j].expoente!=0) printf("X^%d",polires[j].expoente);
			}
		}
		printf ("\n");
		
		free (poli1);
		free (poli2);
		free (polires);
	}
	return 0;
}
