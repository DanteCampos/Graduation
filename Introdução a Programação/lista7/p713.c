#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct complex{
	float r, i;
}complex;

typedef struct raizeq2{
	complex x1,x2;
}raizeq2;

raizeq2 calcula_raizeq2 (float a, float b, float c);
void complex_print (complex c);

int main(){
	
	float a,b,c;
	raizeq2 raiz;
	
	scanf ("%f %f %f",&a,&b,&c);
	
	raiz = calcula_raizeq2 (a,b,c);
	
	if (raiz.x1.i==0){
		printf ("x1 = %.2f\n",raiz.x1.r);
		printf ("x2 = %.2f\n",raiz.x2.r);
	}else{
		printf ("x1 = ");
		complex_print (raiz.x1);
		printf ("\n");
		
		printf ("x2 = ");
		complex_print (raiz.x2);
		printf ("\n");
	}
	
	return 0;
}

raizeq2 calcula_raizeq2 (float a, float b, float c){
	
	raizeq2 raiz;
	complex delta;
	delta.i=0;
	
	delta.r=(b*b)-(4*a*c);
	
	if (delta.r<0){
		delta.i=delta.r*(-1);
		delta.r=0;
	}
	
	delta.r = sqrt (delta.r);
	delta.i = sqrt (delta.i);
	
	if (delta.i>0){
		raiz.x1.r = (-b+delta.r)/(2*a);
		raiz.x2.r = (-b-delta.r)/(2*a);
		raiz.x1.i = (+delta.i)/(2*a);
		raiz.x2.i = (-delta.i)/(2*a);
	}else{
		raiz.x1.r = (-b+delta.r)/(2*a);
		raiz.x2.r = (-b-delta.r)/(2*a);
		raiz.x1.i=0;
		raiz.x2.i=0;
	}
	
	if (raiz.x1.r==0) raiz.x1.r=0;
	if (raiz.x1.i==0) raiz.x1.i=0;
	if (raiz.x2.r==0) raiz.x2.r=0;
	if (raiz.x2.i==0) raiz.x2.i=0;
	
	return raiz;
}

void complex_print (complex c){
	
	int p=0;
	
	if (c.i==0) printf ("%.2f",c.r);
	else{
		if (c.r!=0){
			printf ("%.2f",c.r);
			p=1;
		}
		
		if (p==1 && c.i>0) printf ("+");
		if (c.i<0){
			printf ("-");
			c.i*=(-1);
		}
		if (c.i!=1) printf ("%.2f",c.i);
		printf ("i");	
	}
}
