#include <stdio.h>
#include <stdlib.h>
 
typedef struct imovel{
    int moradores;
    float consumo;
}imovel;
 
int main (){
    int n=0,i=0,j=0,cidade=1;
    imovel *casa=NULL,aux,media;
    
    while(1){
        scanf ("%d",&n);
        
        if (n==0) return 0;
        
        casa = (imovel*) malloc (n*sizeof(imovel));
        media.moradores=0;
        media.consumo=0;
        
        for (i=0;i<n;i++){
            scanf ("%d %f",&casa[i].moradores, &casa[i].consumo);
            media.moradores+=casa[i].moradores;
            media.consumo+=casa[i].consumo;
        }
        
        for (i=0;i<n;i++){
            for (j=0;j<n-1-i;j++){
                if ( (casa[j].consumo/casa[j].moradores) > (casa[j+1].consumo/casa[j+1].moradores)){
                    aux=casa[j];
                    casa[j]=casa[j+1];
                    casa[j+1]=aux;
                }
            }    
        }
        
        if (cidade>1) printf ("\n");
        printf ("Cidade# %d:\n",cidade);
        cidade++;
        
        for (i=0;i<n-1;i++) printf ("%d-%d ",casa[i].moradores,((int)casa[i].consumo/casa[i].moradores));
        printf ("%d-%d",casa[i].moradores,((int)casa[i].consumo/casa[i].moradores));
        printf ("\nConsumo medio: %.2f m3.\n",media.consumo/(float)media.moradores);
        
        free (casa);
    }
}
