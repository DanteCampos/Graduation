#include <stdio.h>

void converteEmNotasMoedas (int a);

int main (){

	int a;
	
	scanf ("%d",&a);
	
	converteEmNotasMoedas (a);
	
	return 0;
}

void converteEmNotasMoedas (int a){

	printf ("NOTAS DE 100 = %d\n",a/100);
	printf ("NOTAS DE 50 = %d\n",(a%100)/50);
	printf ("NOTAS DE 10 = %d\n",((a%100)%50)/10);
	printf ("MOEDAS DE 1 = %d\n",a%10);
}
