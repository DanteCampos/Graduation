#include <stdio.h>

unsigned long int mdc (unsigned long int n, unsigned long int d);
void racionais(unsigned long int a);

int main (){
	unsigned long int n;
	
	while (1){
		scanf ("%lu",&n);
		if (n==0) return 0;
		racionais(n);
	}
}

void racionais(unsigned long int a){
	unsigned long int d,n;
	if (a==1){
		printf ("0/1\n");
		return;
	}
	for (d=1;d;d++){
		for (n=1;n<=d;n++){
			if (mdc(n,d)==1){
				a--;
				if (a==1){
					printf ("%lu/%lu\n",n,d);
					return;
				}
			}
		}
	}
}

unsigned long int mdc (unsigned long int n, unsigned long int d){
	unsigned long int mdc;
	if (n==d) return n;
	if (n>d) mdc=n/2;
	else mdc=d/2;
	while (mdc>1){
		if (d%mdc==0 && n%mdc==0) return mdc;
		mdc--;
	}
	return 1;
}
