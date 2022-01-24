#include <stdio.h>
#define T 5000 

void ordena (int*v, int q);

int main(){
	
	int v[T], q1, q2, q,i;
	
	scanf ("%d",&q1);
	scanf ("%d",&q2);
	q=q1+q2;
	
	for (i=0;i<q;i++) scanf ("%d",&v[i]);
	
	ordena (v,q);
	
	for (i=0;i<q;i++) printf ("%d\n",v[i]);
	
	return 0;
}


void ordena (int*v, int q){
	int i=0,j=0,aux=0;
	
	for (i=1;i<q;i++){
		for (j=0;j<q-i;j++){
			if (v[j]>v[j+1]){
				aux=v[j];
				v[j]=v[j+1];
				v[j+1]=aux;
			}
		}
	}
}
