#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n,v[50],maior,max,i,j,*primos,fermat,divisor,numero;
	double quadrado;
	
	scanf ("%d",&n);
	
	maior=0;
	for (i=0;i<n;i++){
		scanf ("%d",&v[i]);
		if (v[i]>maior) maior=v[i];
	}
	
	primos = (int*) malloc (maior * sizeof(int));
	for (i=0;i<maior;i++) primos[i]=i+1; //vetor de 1 ao maior número
	
	for (i=1;i<maior;i++){
		divisor=primos[i];
		if (divisor==1) continue;		
		for (j=i+1;j<maior;j++){
			if (primos[j]%divisor==0) primos[j]=1;
		}
	}

	for (i=1;i<maior;i++){
		numero=primos[i];
		if (numero==1) continue;
		
		fermat=0;
		for (j=1;j*j<numero;j++){
			quadrado=sqrt(numero-j*j);
			if (quadrado - ((int)quadrado) == 0){
				fermat=1;
				break;
			}
		}
		
		if (fermat==1) fermat=0;
		else primos[i]=1;
	}

	for (i=0;i<n;i++){
		max=v[i];
		
		if (i%2==0){
			for (j=0;j<max;j++){
				if (primos[j]!=1) printf ("%d ",primos[j]);
			}
		}else{
			for (j=max-1;j>=0;j--){
				if (primos[j]!=1) printf ("%d ",primos[j]);
			}
		}
		
		printf ("\n");
	}
	
	free (primos);
	return 0;
}
