#include <stdio.h>
#include <math.h>

#define getsig(i)        ((i)>>31 & 1)
#define getexp(i)        ((i)>>23 & 0xff)
#define getfrac(i)       ((i) & 0x7fffff)
#define makefloat(s,e,f) ( (((s) & 1) << 31) | (((e) & 0xff) << 23) | ((f) & 0x7fffff) )
#define MASK1ESQUERDA 0x80000000

typedef union {
  float f;
  unsigned int i;
} U;


float int2float(int i){
	unsigned int s;
	unsigned int e;
	unsigned int f;
	char qshifts;
	U num;
	
	// Sinal
	if (i < 0){
		s = 1;
		i *= -1;
	}else
		s = 0;
		
		
	f = (unsigned int) i;
	
	// Descobrindo em qual bit está o primeiro 1 mais à esquerda
	for (qshifts = 0; qshifts < 32 && i != 1 ; i >> 1, qshifts++);
	
	if (qshifts == 32){ // Número é 0
		e = 0;
		f = 0;
	}else{ // Não é zero
		e = qshifts + 127;
		f = ((f >> (qshifts-23)) << (qshifts-23)) & 0x7fffff;
	}
	
	num.i = makefloat(s, e, f);
	return num.f;
}


int main() {

   int i;
   printf("\n******** int2float ****************\n");

   i = 0;
   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));

   i = 1;
   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));

   i = -1;
   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));

   i = 0x7fffffff;
   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));

   i = -i;
   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));

   i = 12345;
   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));

   i = -12345;
   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));

   return 0;
}
