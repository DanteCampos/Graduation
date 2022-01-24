#include<stdio.h>
#include <stdlib.h>

int main(){
	int quarteiroes, maxpalanque, i, jogador, *movimentos, teste=1, trocas, j;
	
	while (scanf ("%d %d",&quarteiroes, &maxpalanque), (quarteiroes || maxpalanque)){
	
		trocas = quarteiroes - maxpalanque;
		
		movimentos = (int*) malloc (quarteiroes*sizeof(int));
		for (i=0;i<quarteiroes;i++) scanf ("%d", &movimentos[i]);
		
		for (i=0;i<quarteiroes-maxpalanque;i++){
			for (j=i+1;j<i+maxpalanque+1 && j<quarteiroes;j++) if (movimentos[i]==movimentos[j]) trocas--;
		}
		
		printf ("Teste %d\n%d\n\n", teste, trocas);
		teste++;
		free (movimentos);
	}
	
	return 0;
}

