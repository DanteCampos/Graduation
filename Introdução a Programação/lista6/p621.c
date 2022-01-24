#include <stdio.h>
#define N 100
#define T 6
int main (){
	
	int i,n,v[N],rota=0,tab[T][T]={{0,63,210,190,-1,190},{63,0,160,150,95,10},{210,160,0,10,1,10},{190,150,10,0,10,20},{10,95,7,21,0,80},{190,2,-1,41,80,0}};
	
	scanf ("%d",&n);
	
	for (i=0;i<n;i++) scanf ("%d",&v[i]);
	
	for (i=0;i<n-1;i++){
		if (tab[v[i]][v[i+1]]<0){
			printf ("rota invalida!\n");
			return 0;
		}
		rota+=tab[v[i]][v[i+1]];
	}
	printf ("%d\n",rota);
	
	return 0;
}
