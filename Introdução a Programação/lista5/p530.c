#include <stdio.h>
#include <math.h>
#define T 1000
#define N 5

void contavog (char*a, int*va);

int main(){
	
	char a[T],b[T],str[T];
	int va[N],vb[N],i=0,l=0;
	double x=0;
	
	scanf ("%[^\n]%*c",str);
	
	for (i=0;i<T;i++){
		a[i]=str[i];
		if (str[i]==';') break;
	}

	if (i==T){
		printf ("FORMATO INVALIDO!");
		return 0;
	}
	
	a[i+1]='\0';

	for (i++;str[i-1]!='\0';i++){
		if (str[i]==';'){
			printf ("FORMATO INVALIDO!");
			return 0;
		}else b[l]=str[i];
		l++;
	}

	contavog (a,va);
	contavog (b,vb);
	
	for (i=0;i<N;i++) x+=(va[i]-vb[i])*(va[i]-vb[i]);
	
	x=sqrt(x);
	
	printf ("(%d",va[0]);
	for (i=1;i<N;i++) printf (",%d",va[i]);
	printf (")\n");
	
	printf ("(%d",vb[0]);
	for (i=1;i<N;i++) printf (",%d",vb[i]);
	printf (")\n");
	
	printf ("%.2lf\n",x);
	
	return 0;
}

void contavog (char*a, int*va){
		
	int i;	
	for (i=0;i<N;i++) va[i]=0;
	
	for (i=0;a[i]!='\0';i++){
		if ((a[i]<'A')||(a[i]>'U' && a[i]<'a')||(a[i]>'u')) continue;
		else if ((a[i]=='a')||(a[i]=='A')) va[0]++;
		else if ((a[i]=='e')||(a[i]=='E')) va[1]++;
		else if ((a[i]=='i')||(a[i]=='I')) va[2]++;
		else if ((a[i]=='o')||(a[i]=='O')) va[3]++;
		else if ((a[i]=='u')||(a[i]=='U')) va[4]++;
	}
}

