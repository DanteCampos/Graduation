#include <stdio.h>
#include <stdlib.h>

unsigned long int elevado(int i, int n);
int main (){
	int n, i, *v,a;
	unsigned long int produto=1;
	
	scanf ("%d",&n);
	v = (int*) malloc (n*sizeof(int));
	for (i=0;i<n;i++){
		scanf ("%d",&v[i]);
		produto*=v[i];
	}
	
	for (i=0;i<n;i++){
		if (elevado(i,n)>produto) break;
	}
	
	for (a=0;a<n;a++) printf ("%d ",i);
	
	free(v);
	return 0;
}

unsigned long int elevado(int i, int n){
	unsigned long int pot=1;
	for(n;n>0;n--) pot*=i;
	return pot;
}
