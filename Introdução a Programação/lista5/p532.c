#include <stdio.h>
#define T 6

int acertos (int *sort , int *jogo);

int main(){
	
	int sort[T],jogo[T],quadra=0,quina=0,sena=0,x,i,n;
	
	for (i=0;i<T;i++) scanf ("%d", &sort[i]);
	
	scanf ("%d",&n);
	
	for (n;n>0;n--){
		
		for (i=0;i<T;i++) scanf ("%d",&jogo[i]);
		
		x = acertos (sort,jogo);
		
		if (x==4) quadra++;
		else if (x==5) quina++;
		else if (x==6) sena++;
		
	}
	
	if (sena==0) printf ("Nao houve acertador para sena");
	else printf ("Houve %d acertador(es) da sena",sena);
	
	printf ("\n");
	
	if (quina==0) printf ("Nao houve acertador para quina");
	else printf ("Houve %d acertador(es) da quina",quina);
	
	printf ("\n");
	
	if (quadra==0) printf ("Nao houve acertador para quadra");
	else printf ("Houve %d acertador(es) da quadra",quadra);
	
	printf ("\n");
		
	return 0;
}

int acertos (int *sort , int *jogo){
	
	int i=0,j=0,k=0;
	
	for (i=0;i<T;i++){
		for (j=0;j<T;j++){
			if (sort[i]==jogo[j]) k++;
		}	
	}
	
	return k;
}
