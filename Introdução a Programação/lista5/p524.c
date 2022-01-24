#include <stdio.h>

void ordena (int*v, int n);
int reduz (int*v, int n);

int main (){
	
	int n,i,j,a,m,b,l=0,N;
	scanf ("%d",&n);
	int v[n];

	for (i=0;i<n;i++) scanf ("%d",&v[i]);
	
	ordena (v,n);

	n=reduz (v,n);
	
	for (i=0;i<n;i++) printf ("%d\n",v[i]);

	return 0;
}

void ordena (int*v, int n){
	
	int m,i,j;
	
	for (i=0;i<n;i++){
		for (j=i;j<n;j++){
			if (v[j]<v[i]){
				m=v[j];
				v[j]=v[i];
				v[i]=m;
			}
		}
	}
	
}

int reduz (int*v,int n){

	int i,j;

	for (i=0;i<n-1;i++){
		if (v[i]==v[i+1]){
			for (j=i+1;j<n;j++) v[j]=v[j+1];
			n--;
			i--;
		}
	}
	
	return n;
}
