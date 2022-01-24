#include <stdio.h>

int E_Triangulo (float a, float b, float c);
float Perimetro (float a, float b, float c);
float areaTrapezio (float a, float b, float c);
float mod (float a);

int main (){

	float a,b,c;
	
	scanf ("%f %f %f",&a,&b,&c);
	
	if (E_Triangulo (a,b,c)==0) printf ("Area = %.1f\n",areaTrapezio(a,b,c));
	else printf ("Perimetro = %.1f\n",Perimetro(a,b,c));
	
	return 0;
}

float areaTrapezio (float a, float b, float c){
	return (a+b)*c/2;
}

float Perimetro (float a, float b, float c){
	return a+b+c;
}


int E_Triangulo (float a, float b, float c){

	if ((mod(b-c)<a)&&(a<b+c)&&(mod(a-c)<b)&&(b<a+c)&&(mod(a-b)<c)&&(c<a+b)) return 1;
	else return 0;
}

float mod (float a){

	if (a<0) a=-a;
	return a;
}
