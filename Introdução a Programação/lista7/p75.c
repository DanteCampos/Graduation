#include <stdio.h>
#include <stdlib.h>
#define Tcurso 101
#define Taluno 501

typedef struct curso{
	int codcurso;
	float valorcred;
	char *nomecurso;
}curso;

typedef struct aluno{
	char *nomealuno;
	int codcurso;
	int quantcred;
}aluno;

int main (){
	
	int n=0,m=0,i=0,j=0;
	curso *cursox=NULL;
	aluno *alunox=NULL;
	
	scanf ("%d",&n);
	
	cursox = (curso*) malloc (n*sizeof(curso));
	if (cursox==NULL){
		printf ("DEU RUIM\n");
		return 0;
	}
	
	for (i=0;i<n;i++){
	
		cursox[i].nomecurso = (char*) malloc (n*Tcurso);
		if (cursox[i].nomecurso==NULL){
			printf ("DEU RUIM\n");
			return 0;
		}
		
		scanf ("%d",&cursox[i].codcurso);
		scanf ("%f",&cursox[i].valorcred);
		scanf ("%*c%[^\n]%*c",cursox[i].nomecurso);
	}
	
	scanf ("%d",&m);
	
	alunox = (aluno*) malloc (m*sizeof(aluno));
	if (alunox==NULL){
		printf ("DEU RUIM\n");
		return 0;
	}
	
	for (i=0;i<m;i++){
	
		alunox[i].nomealuno = (char*) malloc (m*Taluno);
		if (alunox[i].nomealuno==NULL){
			printf ("DEU RUIM\n");
			return 0;
		}
		
		scanf ("%*c%[^\n]%*c",alunox[i].nomealuno);
		scanf ("%d",&alunox[i].codcurso);
		scanf ("%d",&alunox[i].quantcred);
		
		for (j=0;j<n;j++){ //encontra o curso do aluno
			if (alunox[i].codcurso==cursox[j].codcurso) break;
		}
		
		printf ("Aluno(a): %s Curso: %s ", alunox[i].nomealuno, cursox[j].nomecurso);
		printf ("Num. Creditos: %d ",alunox[i].quantcred);
		printf ("Valor Credito: %.2f ",cursox[j].valorcred);
		printf ("Mensalidade: %.2f\n",alunox[i].quantcred*cursox[j].valorcred);
	}
	
	return 0;
}
