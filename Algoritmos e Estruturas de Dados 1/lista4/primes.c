#include <stdio.h>
#include <math.h>
void insertionsort (int *v, int n);
int eprimo (int num);

int main (){
	int i,qprimos,posprimo,n,num,v[1000];
	
	scanf ("%d",&n);
	for (i=0;i<n;i++) scanf ("%d",&v[i]);
	
	insertionsort (v,n);
	
	i=0;
	qprimos=0;
	posprimo=v[i];
	
	for (num=2;i<n;num++){
		if (eprimo(num)==0){
			qprimos++;
			if (qprimos==posprimo){
				printf ("%d ",num);
				i++;
				while (posprimo==v[i] && i<n){
					i++;
					printf ("%d ",num);
				}
				posprimo=v[i];
			}
		}
	}
	
	printf ("\n");
	return 0;
}

void insertionsort (int *v, int n){
	int aux,i,j;
	
	for (i=1;i<n;i++){
		aux = v[i];
		for (j=i-1;(j>=0) && (aux<v[j]);j--) v[j+1]=v[j];
		v[j+1]=aux;
	}
	return;
}

int eprimo (int num){
	int a;
	
	for (a=2;a<num;a++){
		if (num%a==0) break;
	}
	
	if (a==num) return 0;
	else return 1;
}
