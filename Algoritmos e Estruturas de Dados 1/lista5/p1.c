#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 1
#define FALHA -1

typedef struct{
	int hora;
	int minuto;
	int critica;
	int chave;
	struct pessoa* prox;
}pessoa;

typedef pessoa* ponteiro;

int crianovalista (ponteiro* p);
int inserenoinicio (ponteiro* p, int hora, int minuto, int critica, int chave);
int inserenofinal (ponteiro* p, int hora, int minuto, int critica, int chave);
int excluilista (ponteiro* p);
void printalista (ponteiro p);
int verifica (int* horaatual, int* minutoatual, int hora, int minuto, int critica);

int main (){
	
	int n, i, hora, minuto, critica, contador=0, horaatual, minutoatual;
	ponteiro primario = (ponteiro) NULL, varredor = (ponteiro) NULL;
	
	crianovalista (&primario);
	
	scanf ("%d",&n);
	
	for (i=0;i<n;i++){
		scanf ("%d %d %d", &hora, &minuto, &critica);
		inserenofinal (&primario, hora, minuto, critica, i);
	}
	
	horaatual = primario->hora;
	minutoatual = primario->minuto;
	
	for (varredor = primario; varredor !=NULL; varredor = varredor->prox) contador += verifica (&horaatual, &minutoatual, varredor->hora, varredor->minuto, varredor->critica);
	
	printf ("%d\n",contador);
	excluilista (&primario);
	
	return 0;
}

int crianovalista (ponteiro* p){
	(*p) = (ponteiro) NULL;
	return (SUCESSO);
}

int inserenoinicio (ponteiro* p, int hora, int minuto, int critica, int chave){
	ponteiro q;
	
	q = (ponteiro) malloc (sizeof (pessoa));
	if (q == NULL) return (FALHA);
	
	q->prox = (ponteiro) (*p);
	(*p) = q;
	
	q->chave = chave;
	q->minuto = minuto;
	q->hora = hora;
	q->critica = critica;
	
	return (SUCESSO);
}

int inserenofinal (ponteiro* p, int hora, int minuto, int critica, int chave){
	ponteiro q, rastreador;
	
	if ((*p) == NULL) return inserenoinicio (p, hora, minuto, critica, chave);
	
	q = (ponteiro) malloc (sizeof (pessoa));
	if (q == NULL) return (FALHA);
	
	q->prox = (ponteiro) NULL;
	q->chave = chave;
	q->minuto = minuto;
	q->hora = hora;
	q->critica = critica;
	
	rastreador = (*p);
	while (rastreador->prox != NULL) rastreador = (ponteiro) rastreador->prox;
	rastreador->prox = (ponteiro) q;
	
	return (SUCESSO);
}

int excluilista (ponteiro* p){
	ponteiro auxiliar;
	while ((*p) != NULL){
		auxiliar = (*p);
		(*p) = (ponteiro) (*p)->prox;
		free (auxiliar);
	}
	return (SUCESSO);
}

void printalista (ponteiro p){
	ponteiro auxiliar;
	
	for (auxiliar = p; auxiliar != NULL; auxiliar = (ponteiro) auxiliar->prox) printf ("Chave %d, %d:%d, critica: %d\n",auxiliar->chave,auxiliar->hora,auxiliar->minuto,auxiliar->critica);
	
	printf ("\n");
	return;
}

int verifica (int* horaatual, int* minutoatual, int hora, int minuto, int critica){
	int tempoatual, tempo;
	
	tempoatual = (*horaatual)*60 + (*minutoatual);
	tempo = hora*60 + minuto;
	
	(*minutoatual) += 30;
	if ((*minutoatual) > 59){
		(*minutoatual) -= 60;
		(*horaatual)+=1;
	}
	
	if ((tempo+critica) >= tempoatual) return 0;
	else return 1;
}
