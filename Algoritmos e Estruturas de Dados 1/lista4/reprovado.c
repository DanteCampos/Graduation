#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[100];
	int nota;
}aluno;

int main(){
	int i,n,maiornota,posicaomenor,j,l;
	char *menorstring;
	aluno alunos[100], aux;
	
	scanf ("%d",&n);
	
	for (i=0;i<n;i++) scanf ("%s %d",alunos[i].nome,&alunos[i].nota);
	
	for (i=0;i<n-1;i++){
		maiornota=alunos[i].nota;
		menorstring=alunos[i].nome;
		posicaomenor=i;
		
		//printf ("\n");
		//for (l=0;l<n;l++) printf ("Nome: %s, Nota: %d\n",alunos[l].nome,alunos[l].nota);
		//printf ("\n");
		
		for (j=i+1;j<n;j++){
			if (alunos[j].nota > maiornota){
				maiornota=alunos[j].nota;
				posicaomenor=j;
				menorstring=alunos[j].nome;
			}else if (alunos[j].nota == maiornota){
				for (l=0;alunos[j].nome[l]!='\0' && menorstring[l]!='\0';l++){
					//printf ("Comparando %s com %s: %c < %c ?\n",alunos[j].nome, menorstring,alunos[j].nome[l],menorstring[l]);
					if (alunos[j].nome[l]<menorstring[l]){
						//printf ("Sim, %c < %c\n",alunos[j].nome[l],menorstring[l]);
						posicaomenor=j;
						menorstring=alunos[j].nome;
						break;
					}else if (alunos[j].nome[l]>menorstring[l]) break;
				}
			}
		}
		
		aux=alunos[i];
		alunos[i]=alunos[posicaomenor];
		alunos[posicaomenor]=aux; 
		
	}
	
	for (i=0;i<n-1;i++)printf ("%s %d\n",alunos[i].nome, alunos[i].nota);
	printf ("%s %d*",alunos[i].nome, alunos[i].nota);
	
	return 0;
}
