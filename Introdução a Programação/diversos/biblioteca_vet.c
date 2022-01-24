#include "vet.h"


/** le vetor real
*   de tamanho n entre 1 e 100
*/

void le_vet (double *v,int n){
	int i;
	
	if (n<1||n>N){
		printf ("VALOR DE n INVALIDO!\n")
		return;
	}
	
	for (i=0;i<n;i++) scanf ("%lf",&v[i]);
}

/** imprime vetor real
*   de tamanho n entre 1 e 100
*/

void print_vet (double *v, int n){
	int i;
	
	if (n<1||n>N){
		printf ("VALOR DE n INVALIDO!\n")
		return;
	}
	
	for (i=0;i<n;i++) printf ("%d ",v[i]);
	printf ("\n");
}

/** soma elementos de vetor
*   real de tamanho n entre
*   1 e 100
*/

double soma_elem (double *v, int n){
	int i;
	double x=0;
	
	if (n<1||n>N){
		printf ("VALOR DE n INVALIDO!\n")
		return 0;
	}
	
	for (i=0;i<n;i++) x+=v[i]
	return x;
}

/** calcula a média do vetor
*   de tamanho n entre 1 e 100
*/

double media_vet (double *v, int n){

	if (n<1||n>N){
		printf ("VALOR DE n INVALIDO!\n")
		return 0;
	}
	
	return soma_elem(v,n)/n;
}

/** calcula a variância do
*   vetor de tamanho n entre
*   1 e 100
*/

double var_vet (double *v,int n){
	double varia=0;
	
	if (n<1||n>N){
		printf ("VALOR DE n INVALIDO!\n")
		return 0;
	}
	
	media = media_vet (v,n);
	for (i=0;i<n;i++) varia+=(v[i]-media)*(v[i]-media);
	return varia/n;
}

/** calcula desvio padrão de
*   vetor de tamanho n entre
*   1 e 100
*/

double desv_pad (double *v, int n){
	
	if (n<1||n>N){
		printf ("VALOR DE n INVALIDO!\n")
		return 0;
	}
	
	return sqrt(var_vet(v,n));
}

/** soma 2 vetores de tamanho
*   n entre 1 e 100 e retorna
*   resultado em vetor por
*   referência
*/

void soma_2vet (double *a, double *b, double *r, int n){
	int i;
	
	if (n<1||n>N){
		printf ("VALOR DE n INVALIDO!\n")
		return;
	}
	
	for (i=0;i<n;i++) r[i]=a[i]+b[i];
}

/** subtrai 2 vetores de tamanho
*   igual retorna o resultado em
*   um vetor por referência
*   definido por a-b
*/

void sub_2vet (double *a, double *b, double *r){
	int i;
	
	if (n<1||n>N){
		printf ("VALOR DE n INVALIDO!\n")
		return;
	}
	
	for (i=0;i<n;i++) r[i]=a[i]-b[i];
}

/** calcula o módulo de um vetor 
*   de tamanho n entre 1 e 100
*/

double mod_vet (double *v, int n){
	double p=0;
	int i;
	
	if (n<1||n>N){
		printf ("VALOR DE n INVALIDO!\n")
		return 0;
	}
	
	for (i=0;i<n;i++) p+=v[i]*v[i];
	return sqrt(p);
}

/** calcula produto interno de
*   2 vetores A e B de tamanho
*   n entre 1 e 100
*/

double prod_int (double*a, double *b, int n){
	int i;
	double pi;
	
	if (n<1||n>N){
		printf ("VALOR DE n INVALIDO!\n")
		return 0;
	}
	
	for (i=0;i<n;i++) pi+=a[i]*b[i];
	return pi;
}

/** calcula derivada de vetor v
*   de tamanho n entre 2 e 100
*   e retorna por referência vetor
*   r de tamanho n-1
*/

void derivada (double *v, double *r, int n){
	int i;
	
	if (n<2||n>N){
		printf ("VALOR DE n INVALIDO!\n")
		return;
	}
	
	for (i=0;i<n-1;i++) r[i]=v[i+1]*(i+1);
}
