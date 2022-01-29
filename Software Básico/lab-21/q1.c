#include <stdio.h>
#include <math.h>

#define getsig(i)        ((i)>>31 & 1)
#define getexp(i)        ((i)>>23 & 0xff)
#define getfrac(i)       ((i) & 0x7fffff)
#define makefloat(s,e,f) ( (((s) & 1) << 31) | (((e) & 0xff) << 23) | ((f) & 0x7fffff) )

typedef union {
  float f;
  unsigned int i;
} U;


float float2 (float f){
	U num;
	unsigned int e;
	
	num.f = f;
	e = getexp(num.i);
	
	//Multiplicar por dois é somar um ao expoente
	
	e = (e + 1) & 0xff;
	
	num.i = makefloat(getsig(num.i), e, getfrac(num.i));
	
	return num.f;
}

int main(){
	float num = 1.5;
	
	printf ("%f\n", float2 (num));
	
	return 0;
}
