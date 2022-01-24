#include <stdio.h>

int main(){

	int matri, depen;
	float salmin, salfun, taxa, impbruto, impliq, impnorm, resultado;

	scanf ("%d %f %d %f %f",&matri,&salmin,&depen,&salfun,&taxa);

	if (salfun>salmin*12){
		impbruto = salfun*0.2;
	}else if (salfun>salmin*5){
		impbruto = salfun*0.08;
	}else{
		impbruto = 0;
	}

	impliq = impbruto - 300*depen;
	
	impnorm = (taxa/100)*salfun;
	
	resultado = impliq - impnorm;

	printf ("MATRICULA = %d",matri);
	printf ("\nIMPOSTO BRUTO = %.2f",impbruto);
	printf ("\nIMPOSTO LIQUIDO = %.2f",impliq);
	printf ("\nRESULTADO = %.2f",resultado);

	if (resultado>0){
		printf ("IMPOSTO A PAGAR");
	}else if (resultado == 0){
		printf ("\nIMPOSTO QUITADO");
	}else{
		printf ("\nIMPOSTO A RECEBER");
	}

	return 0;
}
