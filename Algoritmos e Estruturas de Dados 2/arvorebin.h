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


int criaArvore (Arvore *a);
int insere (Arvore *a, int chave, Dado dado);
Ponteiro busca (Arvore *a, int chave);
int remover (Arvore *a, int chave);
Ponteiro menor (Arvore *a);
Ponteiro maior (Arvore *a);
void printaPreOrdem (Arvore *a);
void printaEmOrdem (Arvore *a);
void printaPosOrdem (Arvore *a);
int quantidadeDeNos (Arvore *a);
int altura (Arvore *a);
int exclui (Arvore*a);
