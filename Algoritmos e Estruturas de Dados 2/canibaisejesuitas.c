#include <stdio.h>
#include <stdlib.h>

//CONSTANTES

#define DIR (1==1)
#define ESQ (!DIR)

#define FALHA -1
#define VALIDA 0
#define SUCESSO 1

#define DOISJESUITAS 0
#define DOISCANIBAIS 1
#define UMDECADA 2
#define UMCANIBAL 3
#define UMJESUITA 4

//ESTRUTURAS

typedef struct no{
	struct no *prox;
	int *situacao;
	int alteracao;
}No;

typedef struct lista{
	No *raiz;
	int tamanho;
}Lista;

Lista* criaLista ();
int comparaNo(No a, No b);
No* criaNo(int* situacao, int alteracao);
void destroiNo (No* n);
void adicionaNaLista(Lista *l, No* n);
void removeDaLista (Lista *l, int* situacao);
No* buscaNaLista (Lista *l, int* situacao);
void destroiLista (Lista *l);
void printaCaminho(Lista *caminho);
int* criaSituacao1();
void destroiSituacao(int* vetor);
int verificaSituacao(int* vetor);
void alteraSituacao(int*vetor, int opcao);
void printaSituacao (int*vetor);
int* copiaSituacao(int* vetor);
int** proximasSituacoes(int* vetor);
void destroiPossibilidades(int**possibilidades);
int comparaSituacao (int* s1, int* s2);
int achaCaminhoDoSucesso(Lista *visitados, Lista *caminho, int* situacao);

//FUNÇÕES DE LISTA E NÓ

Lista* criaLista (){
	Lista* l = (Lista*) malloc (sizeof(Lista));
	l->raiz = NULL;
	l->tamanho=0;
	return l;
}

int comparaNo(No a, No b){

	if (comparaSituacao(a.situacao, b.situacao)) return (1==1);
	else return (1==2);
}

No* criaNo(int* situacao, int alteracao){
	No* n = (No*) malloc (sizeof(No));
	n->prox = NULL;
	n->situacao = copiaSituacao(situacao);
	n->alteracao = alteracao;
	return n;
}

void destroiNo (No* n){
	destroiSituacao(n->situacao);
	free (n);
	return;
}

void adicionaNaLista(Lista *l, No* n){
	n->prox = l->raiz;
	l->raiz = n;
	l->tamanho++;
	return;
}

void removeDaLista (Lista *l, int* situacao){
	No *sombra, *busca;
	sombra=busca=(*l).raiz;
	
	while (busca != NULL){
		if (comparaSituacao(busca->situacao, situacao)){
			sombra->prox = busca->prox;
			destroiNo(busca);
			(*l).tamanho--;
			break;
		}
		sombra = busca;
		busca = busca->prox;
	}
	
	return;
}

No* buscaNaLista (Lista *l, int* situacao){
	No *busca;
	busca=(*l).raiz;
	
	while (busca != NULL){
		if (comparaSituacao(busca->situacao, situacao)) break;
		busca = busca->prox;
	}
	
	return busca;
}

void destroiLista (Lista *l){
	No* sombra, *busca;
	
	if (l == NULL) return;
	else if (l->raiz == NULL) return;
	
	sombra = busca = l->raiz;
	while (busca!=NULL){
		//printf ("Sombra = %p, busca = %p, busca->prox = %p\n", sombra, busca, busca->prox);
		sombra = busca;
		busca = busca->prox;
		destroiNo(sombra);
	}
	//printf ("Saiu, busca = %p, sombra vai deletar %p\n\n", busca, sombra);
	destroiNo(sombra);
	
	free(l);
	return;
}

void printaCaminho(Lista *caminho){
	No* busca = NULL;
	int opcao, *situacao;
	
	if (caminho == NULL) return;
	busca = caminho->raiz;
	
	while (busca != NULL){
		opcao = busca->alteracao;
		situacao = busca->situacao;
		printf("Movimento: ");
		switch (opcao){
			case (DOISJESUITAS):
				if (situacao[4] == ESQ) printf ("Vai para a esquerda com 2 jesuítas");
				else printf ("Vai para a direita com 2 jesuítas");
				break;
			case (DOISCANIBAIS):
				if (situacao[4] == ESQ) printf ("Vai para a esquerda com 2 canibais");
				else printf ("Vai para a direita com 2 canibais");
				break;
			case (UMDECADA):
				if (situacao[4] == ESQ) printf ("Vai para a esquerda com 1 canibal e 1 jesuíta");
				else printf ("Vai para a direita com 1 canibal e 1 jesuíta");
				break;
			case (UMCANIBAL):
				if (situacao[4] == ESQ) printf ("Vai para a esquerda com 1 canibal");
				else printf ("Vai para a direita com 1 canibal");
				break;
			case (UMJESUITA):
				if (situacao[4] == ESQ) printf ("Vai para a esquerda com 1 jesuíta");
				else printf ("Vai para a direita com 1 jesuíta");
				break;
			default:
				break;
		}
		
		printaSituacao(situacao);
		printf ("\n");
		
		//printf ("\n%p", busca);
		busca = busca->prox;
		/*
		printf (" virou %p\n",busca);
		if (busca == NULL) printf ("Deu NULL\n");
		*/
	}
	
	printf ("VENCEU!\n");
	return;
}

//FUNÇÕES PARA SITUAÇÕES

//cada situação do problema é representada por 1 vetor de 5 posições
//vetor[0] = Quantidade de jesuítas na esquerda do rio
//vetor[1] = Quantidade de jesuítas na direita do rio
//veteor[2] = Quantidade de canibais na esquerda do rio
//vetor[3] = Quantidade de canibais da direita do rio
//vetor [4] = Lado em que a barca esta, ESQ para esquerda, DIR para direita


//Cria situação do começo do problema
int* criaSituacao1(){
	int* vetor;
	vetor = (int*) malloc (5*sizeof(int));
	vetor[0]=3;
	vetor[1]=0;
	vetor[2]=3;
	vetor[3]=0;
	vetor[4]=ESQ;
	return vetor;
}

//Destrói uma situação
void destroiSituacao(int* vetor){
	free(vetor);
	return;
}

//Verifica o estado da situação
//Retorna -1 para FALHA
//Retorna 0 para VALIDA
//Retorna 1 para SUCESSO
int verificaSituacao(int* vetor){
	int i;
	if (vetor[1] == 3 && vetor[3]==3 && vetor[4] == DIR) return SUCESSO;
	else{
		if ((vetor[0] > 0 && vetor[0] < vetor[2]) || (vetor[1] > 0 && vetor[1] < vetor[3])) return FALHA;
		for (i=0; i < 4; i++) if (vetor[i] < 0 || vetor[i] > 3) return FALHA;
	}
	
	return VALIDA;
}

//Altera a situação enviada de acordo com a opção escolhida
//Opções:
// DOISJESUITAS para trafegar com 2 jesuítas no barco
// DOISCANIBAIS para trafegar com 2 canibais no barco
// UMDECADA para trafegar com 1 de cada no barco
// UMCANIVAL para trafegar com 1 canibal no barco
// UMJESUITA para trafegar com 1 jesuíta no barco
void alteraSituacao(int*vetor, int opcao){
	switch(opcao){
		case (DOISJESUITAS): //2 jesuítas no barco
			if (vetor[4] == ESQ){ //barco tá na esquerda e vai pra direita
				vetor[0] -=2;
				vetor[1] +=2;
				vetor[4] = DIR;
			}else{ //barco tá na direita e vai pra esquerda
				vetor[0]+=2;
				vetor[1]-=2;
				vetor[4]=ESQ;
			}
			break;
			
		case (DOISCANIBAIS): //2 canibais no barco
			if (vetor[4] == ESQ){ //barco tá na esquerda e vai pra direita
				vetor[2] -=2;
				vetor[3] +=2;
				vetor[4] = DIR;
			}else{ //barco tá na direita e vai pra esquerda
				vetor[2]+=2;
				vetor[3]-=2;
				vetor[4]=ESQ;
			}
			break;
			
		case (UMDECADA): //1 de cada no barco
			if (vetor[4]== ESQ){ //barco tá na esquerda e vai pra direita
				vetor[0]-=1;
				vetor[1]+=1;
				vetor[2]-=1;
				vetor[3]+=1;
				vetor[4]=DIR;
			}else{ //barco tá na direita e vai pra esquerda
				vetor[0]+=1;
				vetor[1]-=1;
				vetor[2]+=1;
				vetor[3]-=1;
				vetor[4]=ESQ;
			}
			break;
			
		case (UMCANIBAL): //1 canibal no barco
			if (vetor[4] == ESQ){ //barco tá na esquerda e vai pra direita
				vetor[2] -=1;
				vetor[3] +=1;
				vetor[4] = DIR;
			}else{ //barco tá na direita e vai pra esquerda
				vetor[2]+=1;
				vetor[3]-=1;
				vetor[4]=ESQ;
			}
			break;
			
		case (UMJESUITA): //1 jesuíta no barco
			if (vetor[4] == ESQ){ //barco tá na esquerda e vai pra direita
				vetor[0] -=1;
				vetor[1] +=1;
				vetor[4] = DIR;
			}else{ //barco tá na direita e vai pra esquerda
				vetor[0]+=1;
				vetor[1]-=1;
				vetor[4]=ESQ;
			}
			break;
	}
	return;
}

int* copiaSituacao(int* vetor){
	int i, *copia;
	copia = (int*) malloc (sizeof(int)*5);
	for (i=0;i<5;i++) copia[i]=vetor[i];
	return copia;
}

void printaSituacao (int*vetor){
	printf ("\n\nESQUERDA		DIREITA\n");
	
	if (vetor[0]==1) printf("%d Jesuíta ",vetor[0]);
	else if (vetor[0]>1) printf("%d Jesuítas",vetor[0]);
	else printf("           ");
	printf ("		");//meio
	if (vetor[1]==1) printf("%d Jesuíta ",vetor[1]);
	else if (vetor[1]>1) printf("%d Jesuítas",vetor[1]);
	printf ("\n");
	
	if (vetor[2]==1) printf("%d Canibal ",vetor[2]);
	else if (vetor[2]>1) printf("%d Canibais",vetor[2]);
	else printf("           ");
	printf("		");//meio
	if (vetor[3]==1) printf("%d Canibal ",vetor[3]);
	else if (vetor[3]>1) printf("%d Canibais",vetor[3]);
	printf ("\n");
	
	if (vetor[4]==DIR)printf ("           		");
	printf("Barco\n");
	
	return;
}

int** proximasSituacoes(int* vetor){
	int i, **possibilidades = (int**) malloc(5*sizeof(int*));
	for(i=0;i <5; i++) possibilidades[i] = copiaSituacao(vetor);
	for(i=0;i <5; i++) alteraSituacao(possibilidades[i], i);
	
	//DOISJESUITAS = 0
	//DOISCANIBAIS = 1
	//UMDECADA = 2
	//UMCANIBAL = 3
	//UMJESUITA = 4
	
	return possibilidades;
}

void destroiPossibilidades(int**possibilidades){
	int i;
	for (i=0;i<5;i++) destroiSituacao(possibilidades[i]);
	free(possibilidades);
	return;
}

int comparaSituacao (int* s1, int* s2){
	int i;
	for (i=0;i < 5; i++) if (s1[i]!=s2[i]) return (1==2);
	return (1==1);
}


//Acha as próximas situações de uma situação válida
//Ignora as que já foram analisadas, entra recursivamente nas que não foram
int achaCaminhoDoSucesso(Lista *visitados, Lista *caminho, int* situacao){
	int **possibilidades, j, i, verificacao;
	No *no = NULL;
	possibilidades = proximasSituacoes(situacao);
	
	/*
	for (i=0;i<5;i++) printf("%d ",situacao[i]);
	printf ("\n");
	
	for (i=0;i<5;i++){
		printf("Possibilidade %d: ", i);
		for (j=0;j<5;j++) printf ("%d ", possibilidades[i][j]);
		printf("\n");
	}
	*/
	
	for (i=0;i<5;i++){
		verificacao = verificaSituacao(possibilidades[i]);
		switch(verificacao){
			case SUCESSO:
				//printf ("Sucesso na possibilidade %d\n",i);
				//if (no != NULL) destroiNo(no);
				no = criaNo(possibilidades[i], i);
				//printf ("RAIZ DA LISTA: %p\n",caminho->raiz);
				adicionaNaLista(caminho, no);
				//printf ("PRIMEIRO NÓ A SER ADICIONADO: %p\n",no);
				destroiPossibilidades(possibilidades);
				return SUCESSO;
				break;
			
			case VALIDA:
				//Só analisa se situação não foi analisada ainda
				if (buscaNaLista (visitados, possibilidades[i]) == NULL){
					//printf("Possibilidade válida e nova: %d\n",i);
					//Coloca na lista das situações analisadas
					//if (no != NULL) destroiNo(no);
					no = criaNo(possibilidades[i], i);
					adicionaNaLista (visitados, no);
					
					//Analisa a situação
					verificacao = achaCaminhoDoSucesso(visitados, caminho, possibilidades[i]);
					
					//Se ela leva ao sucesso, trata como se fosse uma possibilidade que deu sucesso
					if (verificacao == SUCESSO){
						//printf ("PRÓXIMOS NÓS: %p\n",no);
						no = criaNo(possibilidades[i], i);
						adicionaNaLista(caminho, no);
						destroiPossibilidades(possibilidades);
						//printaCaminho(caminho);
						return SUCESSO;
					}
					printf("Mas a %d no deu sucesso\n",i);
				}
				//printf ("Possibilidade válida, mas já analisada: %d\n",i);
				//Só chega aqui se essa situação já foi analisada
				break;
			
			default: //Situação deu falha
				//printf ("Falha na possibilidade %d\n",i);
				break;
		}
	}
	
	//Nenhum caminho levou ao sucesso
	destroiPossibilidades(possibilidades);
	return FALHA;
}

int main (){
	Lista *caminho, *visitados;
	int i,j,*primeiraSituacao;
	No *no;
	
	primeiraSituacao = criaSituacao1();
	caminho = criaLista();
	visitados = criaLista();
	no = criaNo(primeiraSituacao, -1);
	adicionaNaLista(visitados, no);
	
	achaCaminhoDoSucesso(visitados, caminho, primeiraSituacao);
	printaSituacao (primeiraSituacao);
	printf("\n");
	printaCaminho (caminho);
	
	destroiSituacao(primeiraSituacao);
	destroiLista(visitados);
	destroiLista(caminho);
	
	return 0;
}
