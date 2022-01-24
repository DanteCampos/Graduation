#include <stdio.h>
#define T 9
#define N 7

void ordena (int*v);

int main(){
	
	int n,v[T],x,i,j;
	
	scanf ("%d",&n);
	
	for (n;n>0;n--){
	
		x=-100;
		
		for (i=0;i<T;i++){
			scanf ("%d",&v[i]);
			x+=v[i];
		}
		
		for (i=0;i<T;i++){
			for (j=0;j<T;j++){
				if ((v[i]+v[j])==x){
					v[i]=100;
					v[j]=100;
					break;
				}
			}
			if (v[i]+v[j]==200) break;
		}
		
		ordena (v);
		
		for (i=0;i<N;i++) printf ("%d\n",v[i]);
	}
	
	return 0;
}

void ordena (int*v){
	int i=0,j=0,aux=0;
	
	for (i=1;i<T;i++){
		for (j=0;j<T-i;j++){
			if (v[j]>v[j+1]){
				aux=v[j];
				v[j]=v[j+1];
				v[j+1]=aux;
			}
		}
	}
}
