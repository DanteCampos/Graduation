#include <stdio.h>
#include <stdlib.h>
#define Tnome 201

typedef struct data{
	int dia;
	int mes;
	int ano;
}data;

typedef struct aluno{
	data nasc;
	int matricula;
	char *nome;
}aluno;

int maisnovo (aluno a, aluno b);

int main(){
	
	int n=0,i=0,j=0;
	aluno *alunox=NULL, aux;
	
	scanf ("%d",&n);
	
	alunox = (aluno*) malloc (n* sizeof (aluno));
	
	for (i=0;i<n;i++){
		
		alunox[i].nome = (char*) malloc (Tnome*sizeof(char));
		
		scanf ("%d",&alunox[i].matricula);
		scanf ("%d %d %d", &alunox[i].nasc.dia, &alunox[i].nasc.mes, &alunox[i].nasc.ano);
		scanf ("%*c%[^\n]%*c",alunox[i].nome);
	}
	
	for (i=0;i<n;i++){
		for (j=0;j<n-i-1;j++){
			if (maisnovo(alunox[j], alunox[j+1]) == 1) continue;
			else{
				aux=alunox[j];
				alunox[j]=alunox[j+1];
				alunox[j+1]=aux;
			}
		}
	}
	
	for (i=0;i<n;i++){
		printf ("Matric.: %d ",alunox[i].matricula);
		printf ("Nome: %s ",alunox[i].nome);
		printf ("Data Nasc: %d/%d/%d\n", alunox[i].nasc.dia, alunox[i].nasc.mes, alunox[i].nasc.ano);
		
		free (alunox[i].nome);
	}
	
	free (alunox);
	
	return 0;
}

/**compara aluno a em
* relação ao aluno b e
* retorna 0 para mais velho
* retorna 1 para mais novo
* ou mesma idade
*/

int maisnovo (aluno a, aluno b){
	
	if (a.nasc.ano<b.nasc.ano) return 0;
	else if (a.nasc.ano>b.nasc.ano) return 1;
	else{
		if (a.nasc.mes<b.nasc.mes) return 0;
		else if (a.nasc.mes>b.nasc.mes) return 1;
		else{
			if (a.nasc.dia<b.nasc.dia) return 0;
			else return 1;
		}
	}
}
