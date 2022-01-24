#include <stdio.h>
#define N 10
int main (){
	
	int l,c,i,j,m[N][N],ai=0,aj=0;
	
	scanf ("%d %d",&l,&c);
	
	if (l<1||l>10||c<1||c>10){
		printf ("Dimensao invalida");
		return 0;
	}
	
	for (i=0;i<l;i++){
		for (j=0;j<c;j++) scanf ("%d",&m[i][j]);
	}
	
	
	i=0;
	j=-1;
	
	while (1){
	
		for (j++;j<c-aj;j++) printf ("%d ",m[i][j]); //vai pra direita
		j--; //porque o for incrementa j antes de terminar
		if (i+1>=l-ai) break; //se o próximo print não printar nada, acaba o programa
		
		for (i++;i<l-ai;i++) printf ("%d ",m[i][j]); //vai pra baixo
		i--; //porque o for incrementa i antes de terminar
		ai++;
		if (j-1<aj) break; //se o próximo print não printar nada, acaba o programa
		
		for (j--;j>=aj;j--) printf ("%d ",m[i][j]); //vai pra esquerda
		j++; //porque o for decrementa j antes de terminar
		aj++;
		if (i-1<ai) break; //se o próximo print não printar nada, acaba o programa
		
		for (i--;i>=ai;i--) printf ("%d ",m[i][j]); //vai pra cima
		i++; //porque o for decrementa i antes de terminar
		if (j+1>=c-aj) break; //se o próximo print não printar nada, acaba o programa
	}
	return 0;
}
