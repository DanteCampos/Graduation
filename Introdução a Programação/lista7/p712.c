#include <stdio.h>
#include <stdlib.h>

typedef struct fracao{
	long int num;
	long int den;
}fracao;


long int MDC (long int x, long int y);
long int MMC (long int x, long int y);
fracao reduz (fracao x);
fracao ajeitasinal (fracao x);
fracao somafracao (fracao a, fracao b);
fracao subtraifracao (fracao a, fracao b);
fracao multiplicafracao (fracao a, fracao b);
fracao dividefracao (fracao a, fracao b);





long int main(){
	
	fracao a, b, r;
	char operacao;
	
	while (scanf ("%ld",&a.num)!=EOF){
		scanf ("%ld",&a.den);
		
		a = ajeitasinal (a);
		
		scanf (" %c",&operacao);
		scanf ("%ld %ld", &b.num, &b.den);
		
		b = ajeitasinal(b);
		
		if (operacao=='+') r = somafracao (a,b);
		else if (operacao=='-') r = subtraifracao (a,b);
		else if (operacao=='*') r = multiplicafracao (a,b);
		else r = dividefracao (a,b);
		
		r = reduz (r);
		
		printf ("%ld %ld\n", r.num, r.den);
	}
	return 0;
}





long int MDC (long int x, long int y){
	long int i;
	
	if (x<0) x*=(-1);
	if (y<0) y*=(-1);
	
	for (i=2;i<=x && i<=y;i++){
		if (x%i==0 && y%i==0) return i;
	}
	
	return 1;
}

long int MMC (long int x, long int y){
	long int i,menor;
	
	if (x<0) x *= (-1);
	if (y<0) y *= (-1);
	
	if (x<y) menor=x;
	else menor=y;
	
	i=menor;
	
	while (i<x*y){
		if (i%x==0 && i%y==0) return i;	
		i+=menor;
	}
	return x*y;
}

fracao reduz (fracao x){
	long int i,mdc;
	
	while (MDC(x.num, x.den)!=1){
		mdc=MDC(x.num, x.den);
		x.num/=mdc;
		x.den/=mdc;
	}
	return x;
}

fracao ajeitasinal (fracao x){
	if (x.den<0){
		x.num*=(-1);
		x.den*=(-1);
	}
	return x;
}

fracao somafracao (fracao a, fracao b){
	long int mmc;
	
	mmc = MMC(a.den,b.den);
	
	a.num *= mmc/a.den;
	a.den = mmc;
	b.num *= mmc/b.den;
	b.den = mmc;
	
	a.num+=b.num;
	
	return a;
}

fracao subtraifracao (fracao a, fracao b){
	long int mmc;
	
	mmc = MMC(a.den,b.den);
	
	a.num *= mmc/a.den;
	a.den = mmc;
	b.num *= mmc/b.den;
	b.den = mmc;
	
	a.num-=b.num;
	
	return a;
}

fracao multiplicafracao (fracao a, fracao b){
	a.num*=b.num;
	a.den*=b.den;
	
	return a;
}

fracao dividefracao (fracao a, fracao b){
	a.num*=b.den;
	a.den*=b.num;
	
	return a;
}
