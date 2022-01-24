#include <stdio.h>

int main (){
	
	int v[11],n,b1=0,b2=0,i;
	
	scanf ("%d",&n);
	
	for (n;n>0;n--){
		
		for (i=0;i<11;i++){
		
			scanf ("%d",&v[i]);
			if (i<9){
				b1+=v[i]*(i+1);
				b2+=v[i]*(9-i);
			}
		}
		
		b1=b1%11;
		b2=b2%11;
		
		if (b1==10) b1=0;
		if (b2==10) b2=0;
		
		if ((v[9]==b1) && (v[10]==b2)) printf ("CPF valido\n");
		else printf ("CPF invalido\n");
		
		b1=b2=0;
	}
	
	return 0;
}
