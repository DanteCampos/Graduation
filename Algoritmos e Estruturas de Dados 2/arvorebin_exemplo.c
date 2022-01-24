#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "arvorebin.h"

int main (){
	int comando, chave;
	Dado dadinho;
	Arvore a;
	Ponteiro p;

    	setlocale(LC_ALL, "Portuguese");

	printf ("MANIPULAÇÃO DE ÁRVORES\n\n\nComandos:\n\n1 Inicia Árvore\n2 Insere Nó\n3 Busca Nó\n4 Remove Nó\n5 Printa Árvore em Pré-Ordem\n6 Printa Árvore Em Ordem\n7 Printa Árvore em Pós-Ordem\n8 Menor Nó\n9 Maior Nó\n10 Quantidade de Nós\n11 Altura da Árvore\n12 Exclui Árvore\n0 Fecha Programa\n\n");

	while (scanf ("%d", &comando), comando){
		printf ("\n");

		switch (comando){

			case 1:
				criaArvore (&a);
				printf ("Árvore Iniciada!\n\n");
				break;

			case 2:
				printf("Digite, em ordem, a chave inteira única e o dado (número inteiro):\n");
				scanf ("%d %d", &chave, &dadinho.dado);

				if (insere(&a, chave, dadinho)) printf ("Inserido com sucesso!\n");
				else printf ("Erro na inserção.\n");
				break;

			case 3:
				printf ("Digite a chave do nó a ser buscado:\n");
				scanf ("%d",&chave);
				p = busca (&a, chave);
				if (p == NULL) printf ("Nó não encontrado!\n");
				else printf ("Nó encontrado!\nChave: %d, Dado: %d",p->chave, p->dado.dado);
				break;

			case 4:
				printf ("Digite a chave do nó a ser removido:\n");
				scanf ("%d",&chave);

				if (remover(&a, chave)) printf ("Nó removido com sucesso!\n");
				else printf ("Erro na remoção.\n");
				break;

			case 5:
				printaPreOrdem (&a);
				break;

			case 6:
				printaEmOrdem (&a);
				break;

			case 7:
				printaPosOrdem (&a);
				break;

			case 8:
				p = menor(&a);
				if ( p != NULL) printf ("Menor Nó:\nChave: %d, Dado: %d\n", p->chave, p->dado.dado);
				else printf ("Árvore vazia.\n");
				break;

			case 9:
				p = maior(&a);
				if (p != NULL) printf ("Maior Nó:\nChave: %d, Dado: %d\n", p->chave, p->dado.dado);
				else printf ("Árvore vazia.\n");
				break;

			case 10:
				printf ("Quantidade de nós: %d\n", quantidadeDeNos(&a));
				break;

			case 11:
				printf ("Altura da árvore: %d\n", altura(&a));
				break;

			case 12:
				exclui(&a);
				printf ("Árvore excluída com sucesso!\n");
				break;

			default:
				printf ("Opção inválida.\n");
				break;
		}
	}

	return 0;
}
