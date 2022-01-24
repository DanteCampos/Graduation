#include <stdio.h>

int qgrau(int carb, int dur, int res);

int main (){

	int grau,carb,dur,res;
	
	scanf ("%d %d %d",&carb,&dur,&res);
	
	grau = qgrau(carb,dur,res);
	
	printf ("ACO DE GRAU = %d\n",grau);
	return 0;
}

int qgrau (int carb, int dur, int res){

	if ((carb<7)&&(dur>50)&&(res>80000)) return 10;
	else if ((carb<7)&&(dur>50)) return 9;
	else if (carb<7) return 8;
	else return 7;
}
