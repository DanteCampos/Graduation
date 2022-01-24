#include <stdio.h>
#include <stdlib.h>
#include "arvorebin.h"

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

Ponteiro buscaNo (Ponteiro *p, int chave){
	if ((*p)==NULL) return NULL;
	else if ((*p)->chave == chave) return (*p);
	else return buscaNo(&(*p)->filho[chave > (*p)->chave], chave);
}

Ponteiro busca (Arvore *a, int chave){
	return buscaNo(&a->raiz, chave);
}

Ponteiro removerSucessor (Ponteiro pai, Ponteiro p){
	if (p->filho[esq] == NULL){
		pai->filho[p->chave > pai->chave] = p->filho[dir];
		return p;
	}else return removerSucessor(p, p->filho[esq] );
}

int removeNo (Ponteiro pai, Ponteiro p, int chave){
	Ponteiro sucessor;
	if (p->chave != chave){
		if (p->filho[chave > p->chave] == NULL) return ERRO;
		else return removeNo(p, p->filho[chave > p->chave], chave);
	}else{
		if (p->filho[esq]==NULL && p->filho[p->filho[dir]==NULL]) pai->filho[chave > pai->chave] = NULL;
		else if(p->filho[esq]==NULL) pai->filho[chave > pai->chave] = p->filho[dir];
		else if (p->filho[dir]==NULL) pai->filho[chave > pai->chave] = p->filho[esq];
		else{
			sucessor = removerSucessor (p, p->filho[dir]);
			sucessor->filho[esq] = p->filho[esq];
			sucessor->filho[dir] = p->filho[dir];
			pai->filho[chave > pai->chave] = sucessor; 
		}
		free(p);
		return SUCESSO;
	}
}

int remover (Arvore *a, int chave){
	Ponteiro auxiliar = a->raiz, sucessor;
	
	if (auxiliar == NULL) return ERRO;
	if (auxiliar->chave != chave) return removeNo (auxiliar, auxiliar->filho[chave > auxiliar->chave], chave);
	
	
	//Só chega aqui se tiver que remover a raiz
	else{
		if ((auxiliar->filho[esq] == NULL) && (auxiliar->filho[dir] == NULL)) return criaArvore(a);
		else if (auxiliar->filho[esq] == NULL) a->raiz = auxiliar->filho[dir];
		else if (auxiliar->filho[dir] == NULL) a->raiz = auxiliar->filho[esq];
		else{
			sucessor = removerSucessor(auxiliar, auxiliar->filho[dir]);
			sucessor->filho[esq] = auxiliar->filho[esq];
			sucessor->filho[dir] = auxiliar->filho[dir];
			a->raiz = sucessor;
		}
	}
	
	free (auxiliar);
	return SUCESSO;
}

Ponteiro menorNo (Ponteiro p){
	if (p->filho[esq] == NULL) return p;
	else return menorNo (p->filho[esq]);
}

Ponteiro menor (Arvore *a){
	if (a->raiz == NULL) return NULL;
	return menorNo (a->raiz);
}

Ponteiro maiorNo (Ponteiro p){
	if (p->filho[dir] == NULL) return p;
	else return maiorNo (p->filho[dir]);
}

Ponteiro maior (Arvore *a){
	if (a->raiz == NULL) return NULL;
	return maiorNo (a->raiz);
}

void printaPreOrdemNo (Ponteiro p){
	if (p == NULL) return;
	printf ("%d ",p->chave);
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
	printf ("%d ",p->chave);
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
	printf ("%d ",p->chave);
	return;
}

void printaPosOrdem (Arvore *a){
	if (a->raiz == NULL) printf ("Árvore vazia!\n\n");
	else printaPosOrdemNo(a->raiz);
    return;
}

int quantidadeDeNosNo (Ponteiro p){
	if (p == NULL) return 0;
	else return 1+quantidadeDeNosNo(p->filho[esq])+quantidadeDeNosNo(p->filho[dir]);
}

int quantidadeDeNos (Arvore *a){
	return quantidadeDeNosNo (a->raiz);
}

int alturaNo (Ponteiro p){
	int alturaesq, alturadir;

	if (p == NULL) return 0;

	alturaesq = alturaNo(p->filho[esq]);
	alturadir = alturaNo(p->filho[dir]);

	if (alturaesq > alturadir) return 1 + alturaesq;
	else return 1 + alturadir;
}

int altura (Arvore *a){
	if (a->raiz == NULL) return 0;
	return alturaNo(a->raiz);
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
