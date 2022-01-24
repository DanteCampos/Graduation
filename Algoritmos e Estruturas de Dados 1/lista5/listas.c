#include <stdio.h>
#include <stdlib.h>

#define SUCESSO (1==1)
#define FALHA (!SUCESSO);

//o Ponteiro *p é a cabeça da lista passada como parâmetro

//na hora de usar as funções, passe a cabeça usando o endereço dela (&p)

//quando for usar a cabeça dentro da função, como ela foi passada como parãmetro, é necessário entrar no "conteúdo" dela, ou seja, acesse com (*p)

typedef struct{
	int chave;
	int valor;
	Celula* prox;
}Celula;

typedef Celula* Ponteiro;

int crialista (Ponteiro *p){
	(*p) = (Ponteiro) malloc (sizeof(Celula));
	if ((*p) == NULL) return (FALHA);
	else return (SUCESSO);
}

int inserirnoinicio (Ponteiro *p, int chave, int valor){
	Ponteiro q;
	
	q = (Ponteiro) malloc (sizeof (Celula));
	
	if (q == NULL) return (FALHA);
	
	q->chave = chave;
	q->valor = valor;
	q->prox = (*p);
	
	(*p) = q;
		
	return (SUCESSO);
}

int inseriornofinal (Ponteiro *p, int chave, int valor){
	Ponteiro rastreador, q;
	
	if ((*p)->prox == NULL) return (inserirnoinicio(p, chave, valor));
	
	q = (Ponteiro) malloc (sizeof (Celula));
	if (q == NULL) return (FALHA);
	
	q->valor = valor;
	q->chave = chave;
	q->prox = NULL;
	
	rastreador = (*p);
	
	while (rastreador->prox != NULL) rastreador = rastreador->prox;
	
	rastreador->prox = q;
	
	return (SUCESSO);
}

int inserirnaordemcrescentedaschaves (Ponteiro *p, int chave, int valor){
	Ponteiro rastreador, sombra;
	
	if ((*p) == NULL) return (inserirnoinicio(p, chave, valor));
	
	q = (Ponteiro) malloc (sizeof (Celula));
	if (q == NULL) return (FALHA);
	
	q->valor = valor;
	q->chave = chave;
	
	if ((*p)->prox == NULL){ //só tem 1 célula
		if (chave < (*p)->chave){ //célula nova fica antes
		
			q->prox = (*p);
			(*p) = q;
			
		}else{ //célula nova fica depois
			
			q->prox = NULL;
			(*p)->prox = q;
			
		}
		
	}else{
		
		rastreador = (*p);
		
		
		while ( (chave < rastreador->chave) && (rastreador != NULL)){
			sombra = rastreador;
			rastreador = rastreador->prox;
		}
		
		q->prox = rastreador; //no caso de ter saído do while porque o rastreador era NULL, a célula nova vai apontar pra NULL, ou seja, é a última
		sombra->prox = q;
	}
	
	return (SUCESSO);
}
