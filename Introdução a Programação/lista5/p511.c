#include <stdio.h>

int main (){
	
	int n,m=0,i,im=0,vezes=0;
	
	scanf ("%d",&n);
	
	int v[n];
	
	for (i=0;i<n;i++){
		scanf ("%d",&v[i]);
		
		if (v[i]>m){ //salvar o maior número e sua posição no vetor
			m=v[i];
			im=i;
		}
	}
	
	for (i=0;i<n;i++){ //verificar quantidade de vezes que a última nota aparece
		if (v[n-1]==v[i]) vezes++;
	}
	
	printf ("Nota %d, %d ",v[n-1],vezes);
	if (vezes == 1) printf ("vez\n");
	else printf ("vezes\n");
	printf ("Nota %d, indice %d\n",m,im);
	
	return 0;
}
