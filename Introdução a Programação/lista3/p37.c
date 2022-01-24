#include <stdio.h>
     
int main (){
     
	int matricula;
	double p1,p2,p3,p4,p5,p6,p7,p8,l1,l2,l3,l4,l5,t,f,nf;
     
	while ((p1>=0)||(p2>=0)||(p3>=0)||(p4>=0)||(p5>=0)||(p6>=0)||(p7>=0)||(p8>=0)||(l1>=0)||(l2>=0)||(l3>=0)||(l4>=0)||(l5>=0)||(t>=0)||(f>=0)){
     
		scanf ("%d %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",&matricula,&p1,&p2,&p3,&p4,&p5,&p6,&p7,&p8,&l1,&l2,&l3,&l4,&l5,&t,&f);
            
		if ((p1>=0)||(p2>=0)||(p3>=0)||(p4>=0)||(p5>=0)||(p6>=0)||(p7>=0)||(p8>=0)||(l1>=0)||(l2>=0)||(l3>=0)||(l4>=0)||(l5>=0)||(t>=0)||(f>=0)){
            
     
			nf = 0.7*(p1+p2+p3+p4+p5+p6+p7+p8)/8 + 0.15*(l1+l2+l3+l4+l5)/5 + 0.15*t;
                
			printf ("Matricula: %d, Nota Final: %.2lf, Situacao Final: ",matricula,nf);
        
			if ((nf>=6)&&(f>=(128*0.75))){
                
				printf ("APROVADO");
        
			}else if (nf>=6){
                
				printf ("REPROVADO POR FREQUENCIA");
                    
			}else if (f>=(128*0.75)){
                
				printf ("REPROVADO POR NOTA");
			}else{
				printf ("REPROVADO POR NOTA E POR FREQUENCIA");
			}
                
			printf ("\n");
		}        
	}
     
	return 0;
}
