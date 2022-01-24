#include <stdio.h>

float raiz (float x, float y, float erro);
float absoluto (float x);

int main (){
	
	float x, erro;
	
	scanf ("%f %f",&x,&erro);
	
	printf ("%.6f",raiz(x,(x/2),erro));
	
	return 0;
}

float raiz (float x, float y, float erro){
	if (absoluto(y*y-x)<erro) return y;
	else return raiz (x,(((x/y)+y)/2),erro);
}

float absoluto (float x){
	if (x<0) return -x;
	else return x;
}
