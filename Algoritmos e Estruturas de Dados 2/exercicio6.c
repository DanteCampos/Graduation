#include <stdio.h>
#include <stdlib.h>

#define esq 0
#define dir 1

#define ERRO (1==2)
#define SUCESSO (!(ERRO))

typedef struct dado{
	int dado;
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

typedef struct nolista{
	int chave;
	Dado dado;
	struct nolista *prox;
}NoLista;

typedef struct lista{
	NoLista *raiz;
	NoLista *folha;
}Lista;

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

void inicialista (Lista *a){
	a->raiz = NULL;
	a->folha = NULL;
	return;
}

int inserenonoinicio (Lista *a, int c, Dado d){
    	NoLista* n;

    	n = (NoLista*) malloc (sizeof(NoLista));
	if (n==NULL) return ERRO; //caso não dê pra alocar

	n->chave = c;
	n->dado = d;
	n->prox = a->raiz;
	a->raiz = n;

	if (n->prox == NULL) a->folha = n;

	return SUCESSO;
}

int insereno (Lista *a, int c, Dado d){
	NoLista *n, *sombra, *rastreador;
	
	sombra = a->raiz;
    	if (sombra == NULL || c < sombra->chave) return inserenonoinicio(a,c,d);

	n = (NoLista*) malloc (sizeof(NoLista));
	if (n==NULL) return ERRO; //caso não dê pra alocar

	n->chave = c;
	n->dado = d;
	n->prox = NULL;

	for ( rastreador = sombra->prox; rastreador != NULL  && c >= rastreador->chave; rastreador = rastreador->prox) sombra = rastreador;
	
	/*
	if ( rastreador != NULL && c == rastreador->chave){ //caso haja duplicação
		free (n);
		return ERRO;
	}
	*/
	
	n->prox = rastreador;
	sombra->prox = n;

	if (n->prox == NULL) a->folha = n;
	return SUCESSO;
}

int excluiLista (Lista *a){
	NoLista *auxiliar;
	
	if (a->raiz == NULL) return ERRO;
	
	while (a->raiz != NULL){
		auxiliar = a->raiz;
		a->raiz = auxiliar->prox;
		free (auxiliar);
	}
	
	a->folha = NULL;

	return SUCESSO;
}

void printaLista (Lista *a){
	NoLista *rastreador;
    	int i=0;

	for (rastreador = a->raiz; rastreador != NULL; rastreador = rastreador->prox){
		printf ("%d",rastreador->dado.dado);
		if(rastreador->prox != NULL) printf (" ");
	}

	return;
}

void fazListaPorNivel (Ponteiro p, Lista* l, int altura){
	if (p==NULL) return;
	insereno(l, altura, p->dado);
	fazListaPorNivel (p->filho[esq], l, altura+1);
	fazListaPorNivel (p->filho[dir], l, altura+1);
	return;
}

int main (){
	int i,j, n, casos;
	char string[102];
	Arvore a;
	Dado d;
	Lista l;
	
	scanf ("%d",&casos);
	
	criaArvore(&a);
	inicialista(&l);
	for (i=0;i < casos; i++){
		scanf ("%d",&n);
		for (j=0;j<n;j++){
			scanf ("%d",&d.dado);
			insere(&a, d.dado, d);
		}
		
		fazListaPorNivel (a.raiz, &l, 0);
		printf ("Case %d:\n",i+1);
		printaLista(&l);
		printf ("\n\n");
		exclui(&a);
		excluiLista(&l);
	}
	
	return 0;
}


