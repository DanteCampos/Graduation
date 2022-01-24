#include <stdio.h>
#include <stdlib.h>


typedef struct noGrafo{
	int id;
	struct noGrafo* prox;
}noGrafo;

typedef struct PilhaGrafo{
	noGrafo* raiz;
}PilhaGrafo;

PilhaGrafo* criaPilha(){
	PilhaGrafo* p = (PilhaGrafo*)malloc(sizeof(PilhaGrafo));
	p->raiz = null;
	return p;
}

void empilha(PilhaGrafo p, int n){
	p
}

noGrafo* criaGrafo (int n){
	int i;
	noGrafo* lista = (noGrafo*) malloc (n*sizeof(noGrafo));
	if (lista == null) return null;
	
	for (i=0; i< n; i++){
		lista[i].id = 0;
		lista[i].prox = null;
	}
	
	return lista;
}

void adicionaAdjacencia (noGrafo* lista, int size, int a, int b){
	int i;
	noGrafo *aux, *novoNo;
	for (i=0;i<size;i++){
		if (lista[i].id == a){
			novoNo = (noGrafo*) malloc (sizeof(noGrafo));
			novoNo->id = b;
			novoNo->prox = lista[i].prox;
			lista[i].prox = novoNo;
		}
	}
	return;
}

noGrafo buscaVertice (noGrafo *lista, int size, int a){
	int i;
	for (i=0;i<size;i++) if (lista[i].id == a) return lista[i];
}

noGrafo* buscaAdjacencia (noGrafo *lista, int size, int a, int b){
	noGrafo no1 = buscaVertice (lista, size, a);
	for (aux = no1.prox; aux!=null && aux->id != b; aux = aux->prox);
	return aux;
}

int buscaDFS (noGrafo *lista, int size, int a, int b){
	noGrafo no1 = buscaVertice (lista, size, a);
	PilhaGrafo *pilha = criaPilha();
	
}
