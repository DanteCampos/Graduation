#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int id;
	int ouro;
	int prata;
	int bronze;
}pais;

int main(){
	int i,n,m,o,p,b,j,l,troca;
	pais paises[100], aux;
	
	scanf ("%d %d",&n, &m);
	
	for (i=0;i<n;i++){
		paises[i].id=i+1;
		paises[i].ouro=0;
		paises[i].prata=0;
		paises[i].bronze=0;
	}
	
	for (i=0;i<m;i++){
		scanf ("%d %d %d",&o, &p, &b);
		paises[o-1].ouro++;
		paises[p-1].prata++;
		paises[b-1].bronze++;
	}
	
	//for (j=0;j<n;j++)printf ("\nPais %d, %d ouros, %d pratas, %d bronzes\n",paises[j].id,paises[j].ouro,paises[j].prata,paises[j].bronze);
	
	for (i=0;i<n;i++){
		for (j=0;j<n-1-i;j++){
			//for (l=0;l<n;l++) printf ("%d ",paises[l].id);
			//printf ("\n");
		
			troca=0;
			
			//printf ("Comparando:\nPais %d, %d ouros, %d pratas, %d bronzes\ncom\nPais %d, %d ouros, %d pratas, %d bronzes\n\n",paises[j].id,paises[j].ouro,paises[j].prata,paises[j].bronze,paises[j+1].id,paises[j+1].ouro,paises[j+1].prata,paises[j+1].bronze);
			
			if (paises[j].ouro > paises[j+1].ouro) troca=1;
			else if (paises[j].ouro == paises[j+1].ouro){
				if (paises[j].prata > paises[j+1].prata) troca=1;
				else if (paises[j].prata == paises[j+1].prata){
					if (paises[j].bronze > paises[j+1].prata) troca=1;
					else if (paises[j].bronze == paises[j+1].prata){
						if (paises[j].id<paises[j+1].id) troca=1;
					}
				}
			}
			
			if (troca==1){
				aux=paises[j];
				paises[j]=paises[j+1];
				paises[j+1]=aux;
			}
		}
	}
	
	for (i=n-1;i>=0;i--) printf ("%d ",paises[i].id);
	
	return 0;
}
