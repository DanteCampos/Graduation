#include <stdio.h>
#include <stdlib.h>

void ordena (int *v, int n);
int buscaqmenores (int a,int *v,int n);

int main (){
	int i,t,n,k,a,max,ladroes,l,j;
	char *m;
	
	scanf ("%d",&t);
	
	for (i=0;i<t;i++){
		scanf ("%d %d",&n,&k);
		ladroes=0;
		for (a=0;a<n;a++){
			m = (char*) malloc (n*sizeof(char));
			for (j=0;j<n;j++) scanf ("%*c%c",&m[j]);
			
			for (j=0;j<n;j++){
				if (m[j]=='P'){
				
					if (j-k<0) l=0;
					else l=j-k;
					
					if (j+k+1>n) max=n;
					else max=j+k+1;
					
					for (l;l<max;l++){
						if (m[l]=='L'){
							ladroes++;
							m[l]='X';
							break;
						}
					}
				}
			}
			
			free (m);
		}
		printf ("%d\n",ladroes);
	}
	return 0;
}
