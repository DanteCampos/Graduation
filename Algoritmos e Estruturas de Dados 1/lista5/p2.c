#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 1
#define FALHA -1

typedef struct{
	int chave;
	struct Celula* prox;
}Celula;

typedef Celula* Ponteiro;

int crianovalista (Ponteiro* primario);
int inserenoinicio (Ponteiro* primario,int chave);
int inserenofinal (Ponteiro* primario,int chave);
int printachavesdalista (Ponteiro* primario);
int excluilista (Ponteiro* primario);
int excluicelulapelachave (Ponteiro* primario, int senha);

int main (){
	int n,i,senha,s;
	Ponteiro primario;
	
	scanf ("%d",&n);
	
	crianovalista (&primario);
	
	for (i=0;i<n;i++){
		scanf ("%d",&senha);
		inserenofinal (&primario,senha);
	}
	
	scanf ("%d",&s);
	for (i=0;i<s;i++){
		scanf ("%d",&senha);
		excluicelulapelachave (&primario, senha);
	}
	
	printachavesdalista (&primario);
	excluilista (&primario);
	
	return 0;
}

int crianovalista (Ponteiro* primario){
	(*primario) = (Ponteiro) NULL;
	return (SUCESSO);
}

int inserenoinicio (Ponteiro* primario,int chave){
	Ponteiro q;
	
	q = (Ponteiro) malloc (sizeof (Celula));
	if (q == NULL) return (FALHA);
	
	q->chave = chave;
	
	q->prox = (Ponteiro) (*primario);
	(*primario) = q;
	
	return (SUCESSO);
}

int inserenofinal (Ponteiro* primario,int chave){
	Ponteiro q, rastreador;
	
	if ((*primario) == NULL) return (inserenoinicio (primario, chave));
	
	q = (Ponteiro) malloc (sizeof (Celula));
	if (q == NULL) return (FALHA);
	
	q->chave = chave;
	q->prox = (Ponteiro) NULL;
	
	for (rastreador = (*primario); rastreador->prox != NULL; rastreador = rastreador->prox);
	rastreador->prox = q;
	
	return (SUCESSO);
}

int excluicelulapelachave (Ponteiro* primario,int senha){
	Ponteiro rastreador, sombra;
	
	sombra = (Ponteiro) NULL;
	for (rastreador = (*primario); (rastreador != NULL) && (senha != rastreador->chave) ; rastreador = rastreador->prox) sombra = rastreador;
	
	if (rastreador->chave != senha) return (FALHA);
	
	if(sombra == NULL) (*primario) = rastreador->prox;
	else sombra->prox = rastreador->prox;
	
	free (rastreador);
	
	return (SUCESSO);
}

int excluilista (Ponteiro* primario){
	Ponteiro auxiliar;
	
	while ((*primario) != NULL){
		auxiliar = (*primario);
		(*primario) = (Ponteiro) (*primario)->prox;
		free (auxiliar);
	}
	
	return (SUCESSO);
}

int printachavesdalista (Ponteiro* primario){
	Ponteiro rastreador;
	for (rastreador = (*primario); rastreador != NULL; rastreador = rastreador->prox) printf ("%d ", rastreador->chave);
	printf ("\n");
	
	return (SUCESSO);
}

