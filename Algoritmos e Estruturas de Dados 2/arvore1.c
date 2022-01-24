#include <stdio.h>
#include <stdlib.h>
#include "arvore1.h"

void iniciaarvore (Lista *a){
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

	for ( rastreador = sombra->prox; rastreador != NULL  && c > rastreador->chave; rastreador = rastreador->prox) sombra = rastreador;
	
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




void buscano (Lista *a, int c){
	NoLista *rastreador;

	for (rastreador = a->raiz; rastreador != NULL && rastreador->chave != c; rastreador = rastreador->prox);
	if (rastreador == NULL) printf ("Nó não encontrado.\n\n");
	else printf ("Nó encontrado!\n\nChave: %d\nDado: %d\n\n", c, rastreador->dado.d);
	
	return;
}

int removenonoinicio(Lista *a){
    	NoLista *auxiliar = a->raiz;

	a->raiz = auxiliar->prox;
	if (a->raiz == NULL) a->folha = NULL;
	free (auxiliar);

	return SUCESSO;
}

int removeno (Lista *a, int c){
	NoLista *rastreador, *sombra;

	for (sombra = rastreador = a->raiz; rastreador != NULL && c != rastreador->chave ; rastreador = rastreador->prox) sombra = rastreador;
	if (rastreador == NULL) return ERRO;
    	if (rastreador == a->raiz) return removenonoinicio(a);

	sombra->prox = rastreador->prox;
	free(rastreador);

    	if (sombra->prox == NULL) a->folha = sombra;

	return SUCESSO;
}

void menorno (Lista *a){
	NoLista* no = a->raiz;
	
	if (no==NULL) printf ("Árvore vazia.\n\n");
	else printf ("Menor nó:\n\nChave: %d\nDado: %d\n\n", no->chave, no->dado.d);
	return;
}

void maiorno (Lista*a){
	NoLista* no = a->folha;
	
	if (no==NULL) printf ("Árvore vazia.\n\n");
	else printf ("Maior nó:\n\nChave: %d\nDado: %d\n\n", no->chave, no->dado.d);
	return;
}

void printaarvore (Lista *a){
	NoLista *rastreador;
    	int i=0;

    	printf ("Início:\n");
	for (rastreador = a->raiz; rastreador != NULL; rastreador = rastreador->prox) printf ("Nó %d, Chave: %d, Dado: %d\n", i++, rastreador->chave,rastreador->dado.d);
	printf ("Fim.\n");

	return;
}

int excluiarvore (Lista *a){
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
