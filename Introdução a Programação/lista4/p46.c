#include <stdio.h>

float interceptoEmX(float a,float b);
float interceptoEmY(float a,float b);

int main (){

	int n;
	float a,b;
	
	scanf ("%d",&n);
	
	for (n;n>0;n--){
	
		scanf ("%f %f",&a,&b);
		
		printf ("Intercepto em x: (%.2f, 0.00)\n",interceptoEmX(a,b));
		printf ("Intercepto em y: (0.00, %.2f)\n",interceptoEmY(a,b));
	}
	return 0;
}

float interceptoEmX(float a,float b){
	return -(b/a);
}

float interceptoEmY(float a,float b){
	return b;
}
