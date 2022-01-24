#include <stdio.h>
#include <stdlib.h>

#define esq 0
#define dir 1

#define ERRO (1==2)
#define SUCESSO (!(ERRO))

typedef struct dado{
	char dado;
}Dado;

typedef struct no{
	int chave;
	Dado dado;
	struct no* filho[2];
}No;

typedef No* Ponteiro;

typedef struct arvore{
	Ponteiro raiz;
}Arvore;

int criaArvore (Arvore *a){
	a->raiz = NULL;
	return SUCESSO;
}

Ponteiro criaNo (int chave, Dado dado){
	Ponteiro novoNo;
	
	novoNo = (Ponteiro) malloc (sizeof(No));
	if (novoNo == NULL) return NULL;

	novoNo->chave = chave;
	novoNo->dado = dado;
	novoNo->filho[esq]=NULL;
	novoNo->filho[dir]=NULL;
	return novoNo;
}

int insereNo (Ponteiro *p, int chave, Dado dado){
	if ((*p) == NULL) (*p) = criaNo(chave, dado);
	else if ((*p)->chave == chave ) return ERRO;
	else return insereNo (&((*p)->filho[chave > (*p)->chave]), chave, dado);	
	return SUCESSO;
}

int insere (Arvore *a, int chave, Dado dado){
	return insereNo (&a->raiz, chave, dado);
}

void excluiNo (Ponteiro p){
	if (p==NULL) return;
	excluiNo(p->filho[esq]);
	excluiNo(p->filho[dir]);
	free (p);
	return;
}

int exclui (Arvore*a){
	excluiNo(a->raiz);
	return criaArvore(a);
}

void printaPreOrdemNo (Ponteiro p){
	if (p == NULL) return;
	printf (" %d",p->chave);
	printaPreOrdemNo (p->filho[esq]);
	printaPreOrdemNo (p->filho[dir]);
	return;
}

void printaPreOrdem (Arvore *a){
	if (a->raiz == NULL) printf ("Árvore vazia!\n\n");
	else printaPreOrdemNo(a->raiz);
    return;
}

void printaEmOrdemNo (Ponteiro p){
	if (p == NULL) return;
	printaEmOrdemNo (p->filho[esq]);
	printf (" %d",p->chave);
	printaEmOrdemNo (p->filho[dir]);
	return;
}

void printaEmOrdem (Arvore *a){
	if (a->raiz == NULL) printf ("Árvore vazia!\n\n");
	else printaEmOrdemNo(a->raiz);
    return;
}

void printaPosOrdemNo (Ponteiro p){
	if (p == NULL) return;
	printaPosOrdemNo (p->filho[esq]);
	printaPosOrdemNo (p->filho[dir]);
	printf (" %d",p->chave);
	return;
}

void printaPosOrdem (Arvore *a){
	if (a->raiz == NULL) printf ("Árvore vazia!\n\n");
	else printaPosOrdemNo(a->raiz);
    return;
}

int main (){
	int i, j, chave, n, tam;
	char *pre, *em;
	Arvore a;
	Dado d;
	
		
	criaArvore (&a);
	scanf ("%d ", &n);
	for (j=0;j<n;j++){
		scanf ("%d",&tam);
		
		for (i=0; i<tam ;i++){
			scanf ("%d", &chave);
			insere(&a, chave, d);
		}
		
		printf ("Case %d:\nPre.:",j+1);
		printaPreOrdem (&a);
		printf ("\nIn..:");
		printaEmOrdem (&a);
		printf ("\nPost:");
		printaPosOrdem (&a);
		printf ("\n\n");
		
		exclui(&a);
	}
	
	return 0;
}
