#include <stdio.h>
#include <stdlib.h>
int main(){
	int aeroportos, voos, *vetor, i, maior, teste=1,a,b,primeiro=0;
	
	while (scanf ("%d %d", &aeroportos, &voos), (aeroportos!=0 && voos !=0)){
		
		vetor = (int*) malloc (aeroportos*sizeof(int));
		for (i=0;i<aeroportos;i++) vetor[i]=0;
		
		for (voos;voos>0;voos--){
			scanf ("%d %d",&a,&b);
			vetor[a-1]++;
			vetor[b-1]++;
		}
		
		maior=0;
		
		for (i=0; i<aeroportos; i++) if(vetor[i] > maior) maior=vetor[i];
		
		for (i=0; i<aeroportos; i++) if (maior > vetor[i]) vetor[i]=0;
		
		printf ("Teste %d\n",teste);
		for (i=0; i<aeroportos; i++){
			if (vetor[i] != 0 && primeiro==0){
				primeiro=1;
				printf ("%d", i+1);
			}
			else if (vetor[i] != 0 && primeiro==1) printf (" %d", i+1);
		}
		
		printf ("\n\n");
		
		teste++;
		primeiro=0;
		free (vetor);
	}
	
	return 0;
}
