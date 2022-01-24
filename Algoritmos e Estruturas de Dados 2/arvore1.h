#define ERRO (1==2)
#define SUCESSO (1==1)


typedef struct dado{
	int dado;
}Dado;


typedef struct nolista{
	int chave;
	Dado dado;
	struct no *prox;
}NoLista;

typedef struct lista{
	NoLista *raiz;
	NoLista *folha;
}Lista;


void iniciaarvore (Lista *a);
int insereno (Lista *a, int c, Dado d);
void buscano (Lista *a, int c);
int removeno (Lista *a, int c);
void menorno (Lista *a);
void maiorno (Lista*a);
void printaarvore (Lista *a);
int excluiarvore (Lista *a);
