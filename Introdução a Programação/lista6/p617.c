#include <stdio.h>
#define T 6
#define N 50000
int main (){
	
	int n,m[N][T],r[T],p,i,j,a,quadra=0,quina=0,sena=0;
	
	scanf ("%d",&n);
	
	for (i=0;i<n;i++){
		for (j=0;j<T;j++) scanf ("%d",&m[i][j]);
	}
	
	for (i=0;i<T;i++) scanf ("%d",&r[i]);
	
	for (i=0;i<n;i++){
		p=0;
		for (j=0;j<T;j++){
			for (a=0;a<T;a++) {
				if (m[i][j]==r[a]) p++;
			}
		}
		if (p<4) continue;
		else if (p==4) quadra++;
		else if (p==5) quina++;
		else sena++;
	}
	
	if (sena==0) printf ("Nao houve acertador para sena\n");
	else printf ("Houve %d acertador(es) da sena\n",sena);
	
	if (quina==0) printf ("Nao houve acertador para quina\n");
	else printf ("Houve %d acertador(es) da quina\n",quina);
	
	if (quadra==0) printf ("Nao houve acertador para quadra\n");
	else printf ("Houve %d acertador(es) da quadra\n",quadra);
	
	return 0;
}
