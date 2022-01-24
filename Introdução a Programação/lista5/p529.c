#include <stdio.h>
#define T 100001

int main(){
	
	unsigned long int a,n;
	int i,mi,l;
	char v[T],aux[T],m;
	
		
	while (1){
		
		l=0;
		mi=-1;
		
		scanf ("%lu %lu",&a,&n);
		if (a==0&&n==0) return 0;
		
		scanf ("%s",v);
		
		for (n;n>0;n--){
			mi++;
			m=v[mi];
			
			for (i=mi+1;i<a-n+1;i++){
				if (m<v[i]){
					m=v[i];
					mi=i;	
				}
			}
			
			v[mi]='0'-1;
			aux[l]=m;
			l++;
		}
		
		aux[l]='\0';
		
		printf ("%s\n",aux);
	}
}
