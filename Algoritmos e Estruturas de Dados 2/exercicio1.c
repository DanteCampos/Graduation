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

void printaPosOrdemNo (Ponteiro p){
	if (p == NULL) return;
	printaPosOrdemNo (p->filho[esq]);
	printaPosOrdemNo (p->filho[dir]);
	printf ("%c",p->dado.dado);
	return;
}

void printaPosOrdem (Arvore *a){
	if (a->raiz == NULL) printf ("Árvore vazia!\n\n");
	else printaPosOrdemNo(a->raiz);
    return;
}

int main (){
	int i, j;
	char pre[26], em[26];
	Arvore a;
	Dado d;
	
		
	criaArvore (&a);
	
	while (scanf ("%s %s",pre, em) != EOF){
		for (i=0;pre[i] != '\0';i++){
			for (j=0;em[j] != '\0';j++) if (em[j]==pre[i])break;
			d.dado = pre[i];
			insere (&a, j, d);
		}
		printaPosOrdem (&a);
		printf ("\n");
		exclui(&a);
	}
	
	return 0;
}
