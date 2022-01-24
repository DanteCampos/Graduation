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

Ponteiro maiorNo (Ponteiro p){
	if (p->filho[dir] == NULL) return p;
	else return maiorNo (p->filho[dir]);
}

Ponteiro maior (Arvore *a){
	if (a->raiz == NULL) return NULL;
	return maiorNo (a->raiz);
}

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

void printaPreOrdemNo (Ponteiro p, Ponteiro a){
	if (p == NULL) return;
	if (p!=a) printf (" ");
	printf ("%c",p->dado.dado);
	printaPreOrdemNo (p->filho[esq],a);
	printaPreOrdemNo (p->filho[dir],a);
	return;
}

void printaPreOrdem (Arvore *a){
	if (a->raiz == NULL) printf ("Árvore vazia!\n\n");
	else printaPreOrdemNo(a->raiz, a->raiz);
    return;
}

void printaEmOrdemNo (Ponteiro p, Ponteiro a){
	if (p == NULL) return;
	printaEmOrdemNo (p->filho[esq],a);
	printf ("%c",p->dado.dado);
	if (p!=a) printf (" ");
	printaEmOrdemNo (p->filho[dir], a);
	return;
}

void printaEmOrdem (Arvore *a){
	if (a->raiz == NULL) printf ("Árvore vazia!\n\n");
	else printaEmOrdemNo(a->raiz, maior(a));
    return;
}

void printaPosOrdemNo (Ponteiro p, Ponteiro a){
	if (p == NULL) return;
	printaPosOrdemNo (p->filho[esq], a);
	printaPosOrdemNo (p->filho[dir], a);
	printf ("%c",p->dado.dado);
	if (p!=a) printf (" ");
	return;
}

void printaPosOrdem (Arvore *a){
	if (a->raiz == NULL) printf ("Árvore vazia!\n\n");
	else printaPosOrdemNo(a->raiz, a->raiz);
    return;
}

Ponteiro buscaNo (Ponteiro *p, int chave){
	if ((*p)==NULL) return NULL;
	else if ((*p)->chave == chave) return (*p);
	else return buscaNo(&(*p)->filho[chave > (*p)->chave], chave);
}

Ponteiro busca (Arvore *a, int chave){
	return buscaNo(&a->raiz, chave);
}

int main (){
	int i, j, n, tam;
	char comando[8];
	Arvore a;
	Dado d;
	Ponteiro p;
	
		
	criaArvore (&a);
	while (scanf("%s",comando) != EOF){
		if (comando[0]=='I'){
			if (comando[1]=='N'){
				printaEmOrdem(&a);
				printf ("\n");
			}else{
				scanf (" %c",&d.dado);
				insere(&a, (int)d.dado, d);
			}
		}else{
			if (comando[1]=='R'){
				printaPreOrdem(&a);
				printf ("\n");
			}else if (comando[1]=='O'){
				printaPosOrdem(&a);
				printf ("\n");
			}else{
				scanf (" %c",&d.dado);
				if (busca(&a, (int)d.dado) == NULL)printf ("%c nao existe\n",d.dado);
				else printf ("%c existe\n",d.dado);
			}
		}
	}
	
	exclui(&a);
	return 0;
}
