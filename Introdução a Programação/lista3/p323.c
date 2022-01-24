#include <stdio.h>

int main (){
	
	unsigned long int c,melhorc, maisc;
	float pc,pv,totalc,totalv,perc,melhorl;
	int v,maisv,qmenor,qmeio,qmaior,i;
	
	qmenor=qmeio=qmaior=melhorc=maisc=maisv=totalc=totalv=0;
	
	for (i=6;i>0;i--){
	
		scanf ("%lu %f %f %d",&c,&pc,&pv,&v);
		
		if (((pv-pc)/pc)>0.2) qmaior++;
		else if ((((pv-pc)/pc)<=0.2)&&(((pv-pc)/pc))>=0.1) qmeio++;
		else if (((pv-pc)/pc)<0.1) qmenor++;
		
		if ((pv-pc)>melhorl){
			melhorl=pv-pc;
			melhorc=c;
		}
		
		if (v>maisv){
			maisv=v;
			maisc=c;
		}
		
		totalc+=pc*v;
		totalv+=pv*v;
		perc = 100*totalv/totalc-100;
	}
	printf ("Quantidade de mercadorias que geraram lucro menor que 10%%: %d\n",qmenor);
	printf ("Quantidade de mercadorias que geraram lucro maior ou igual a 10%% e menor ou igual a 20%%: %d\n",qmeio);
	printf ("Quantidade de mercadorias que geraram lucro maior do que 20%%: %d\n",qmaior);
	printf ("Codigo da mercadoria que gerou maior lucro: %lu\n",melhorc);
	printf ("Codigo da mercadoria mais vendida: %lu\n",maisc);
	printf ("Valor total de compras: %.2f, valor total de vendas: %.2f e percentual de lucro total: %.2f%%",totalc,totalv,perc);
	printf ("\n");
		
	return 0;
}




	
	
	
