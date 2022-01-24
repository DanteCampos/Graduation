#include <stdio.h>

int main (){
	
	int t1,t2,matricula;
	double salmin, salbruto, salliq, lim, pt1, pt2;
	
	scanf ("%lf %lf %lf %lf",&salmin,&lim,&pt1,&pt2);

	while (1){
	
		salbruto = salmin;
		
		scanf ("%d %d %d",&matricula,&t1,&t2);
		
		if (matricula==0) return 0;
		
		if (t1>=10) salbruto+= t1*pt1*0.14;
		else salbruto += t1*pt1*0.13;
	
		if (t2>=20) salbruto += t2*pt2*0.13;
		else salbruto += t2*pt2*0.12;
		
		salliq=salbruto;
		
		salliq-=salliq*0.08; //INSS
		
		if (salliq>lim) salliq -= (salliq-lim)*0.15;
		
		printf ("MATRICULA = %d, SALARIO BRUTO = %.2lf, SALARIO LIQUIDO = %.2lf\n",matricula,salbruto,salliq);
	}
	return 0;
}
