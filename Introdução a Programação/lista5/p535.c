#include <stdio.h>
#define T 100

int main(){
	
	int a[T],b[T],U[2*T],I[T],ta,tb,i,j,x,l,tU,tI;
	
	while (1){
		scanf ("%d",&ta);
		if (ta>=1&&ta<=100) break;
	}
	
	while (1){
		scanf ("%d",&tb);
		if (tb>=1&&tb<=100) break;
	}
	
	for (i=0;i<ta;i++){
		scanf ("%d",&x);
		for (j=0;j<i;j++){
			if (x==a[j]) break;
		}
		
		if (j==i) a[i]=x;
		else i--;
	}
	

	
	for (i=0;i<tb;i++){
		scanf ("%d",&x);
		for (j=0;j<i;j++){
			if (x==b[j]) break;
		}
		
		if (j==i) b[i]=x;
		else i--;
	}
		
	for (l=0;l<ta;l++) U[l]=a[l];
	
	for (i=0;i<tb;i++){
		for (j=0;j<ta;j++){
			if (b[i]==a[j]) break;
		}
		if (j==ta){
			U[l]=b[i];
			l++;
		}
	}
	
	tU=l;
	l=0;
	
	for (i=0;i<tb;i++){
		for (j=0;j<ta;j++){
			if (a[j]==b[i]){
				I[l]=b[i];
				l++;
			}
		}
	}
	
	tI=l;
	
	printf ("(");
	if (tU>0) printf ("%d",U[0]);
	for (i=1;i<tU;i++) printf (",%d",U[i]);
	printf (")\n");
	
	printf ("(");
	if (tI>0) printf ("%d",I[0]);
	for (i=1;i<tI;i++) printf (",%d",I[i]);
	printf (")\n");
	
	return 0;
}
