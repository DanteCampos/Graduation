#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "arvore1.h"

int main (){
	int comando, chave;
	Dado dadinho;
	Arvore a;

    	setlocale(LC_ALL, "Portuguese");

	printf ("MANIPULAÇÃO DE ÁRVORES\n\n\nComandos:\n\n1 Inicia Árvore\n2 Insere Nó\n3 Busca Nó\n4 Remove Nó\n5 Printa Árvore\n6 Menor Nó\n7 Maior Nó\n8 Exclui Árvore\n0 Fecha Programa\n\n");

	while (scanf ("%d", &comando), comando){
		printf ("\n");

		switch (comando){

			case 1:
				iniciaarvore (&a);
				printf ("Árvore Iniciada!\n\n");
				break;

			case 2:
				printf("Digite, em ordem, a chave inteira única e o dado (número inteiro):\n\n");
				scanf ("%d %d", &chave, &dadinho.d);

				if (insereno(&a, chave, dadinho)) printf ("Inserido com sucesso!\n\n");
				else printf ("Erro na inserção.\n\n");
				break;

			case 3:
				printf ("Digite a chave do nó a ser buscado:\n\n");
				scanf ("%d",&chave);
				buscano (&a, chave);
				
				break;

			case 4:
				printf ("Digite a chave do nó a ser removido:\n\n");
				scanf ("%d",&chave);

				if (removeno(&a, chave)) printf ("Nó removido com sucesso!\n\n");
				else printf ("Erro na remoção.\n\n");
				break;

			case 5:
				printaarvore (&a);
				break;

			case 6:
				menorno(&a);
				break;

			case 7:
				maiorno(&a);
				break;

			case 8:
				if (excluiarvore (&a)) printf ("Árvore excluída com sucesso!\n\n");
				else printf ("Árvore vazia.\n\n");
				break;

			default:
				printf ("Opção inválida.\n\n");
				break;
		}
	}

	return 0;
}
