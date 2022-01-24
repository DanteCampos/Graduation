#include <stdio.h>

int main (){
	
	int n,i,j,menor,maior;
	
	scanf ("%d",&n);
	
	int v[n],w[n];
	
	for (i=0;i<n;i++) scanf ("%d",&v[i]);
	
	j=n-1;
	
	maior=v[0];
	menor=v[n-1];
	
	for (i=0;i<n;i++){
	
		printf ("%d",v[i]); //printa vetor v
		
		if (v[i]>maior) maior = v[i]; //armazena maior valor do vetor v
		
		w[j]=v[i]; //atribui valores ao vetor w na ordem inversa
		
		j--;
		
		if (i+1<n) printf (" "); //printa espaço para o próximo número (se houver)
	}
	
	printf ("\n");
	
	for (i=0;i<n;i++){
	
		printf ("%d",w[i]); //printa vetor w (que tem ordem inversa do vetor v)
		
		if (w[i]<menor) menor = w[i]; //armazena menor valor do vetor w
		
		if (i+1<n) printf (" "); //printa espaço para o próximo número (se houver)
	}
	
	printf ("\n");
	
	printf ("%d\n",maior); //printa maior valor do vetor v
	printf ("%d\n",menor); //printa menor valor do vetor w
	
	return 0;
}
