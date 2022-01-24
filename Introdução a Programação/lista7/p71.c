#include <stdio.h>
#include <stdlib.h>
typedef struct frac{
	int num;
	int den;
}frac;

int main (){
	
	int testes,n,i,j,p,a;
	frac *x;
	
	scanf ("%d",&testes);
	
	for (a=0;a<testes;a++){
		printf ("Caso de teste %d\n",a+1);
		
		p=0;
		
		scanf ("%d",&n);
		
		x = (frac*) malloc(n*sizeof(frac));
		
		for (i=0;i<n;i++) scanf ("%d/%d",&x[i].num,&x[i].den);
		
		for (i=0;i<n-1;i++){
			for (j=i+1;j<n;j++){
				if ( ((float) x[i].num/x[i].den) == ((float) x[j].num/x[j].den) ){
					p=1;
					printf ("%d/%d equivalente a %d/%d\n", x[i].num, x[i].den, x[j].num, x[j].den);
				}
			}
		}
		
		if (p==0) printf ("Nao ha fracoes equivalentes na sequencia\n");
		
		free (x);
	}
	return 0;
}
