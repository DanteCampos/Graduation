#include <stdio.h>
#include <string.h>
#define T 3

double absoluto (double n);
void ordena (double *v);

int main(){
	
	int n,i;
	double v[T],a[T],b[T];
	
	scanf ("%d",&n);
	for (i=0;i<T;i++) scanf ("%lf",&a[i]);
	
	for (n--;n>0;n--){
		for (i=0;i<T;i++){
			scanf ("%lf",&b[i]);
			v[i] = absoluto (a[i]-b[i]);
			a[i]=b[i];
		}
		
		ordena (v);
		
		printf ("%.2lf\n",v[T-1]);
	}
	return 0;
}

double absoluto (double n){
	if (n<0) n=-n;
	return n;
}

void ordena (double *v){
	int i,j;
	double aux;

	for (i = 1; i < T-1; i++){
		for (j = 0; j < T-i; j++){
			if (v[j] > v[j+1]){
                	aux = v[j];
                	v[j] = v[j+1];
                	v[j+1] = aux;
			}
		}
	}
}


