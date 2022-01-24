#include <stdio.h>
#define T 499

char *prefix (int a, char *str); 

int main (){
	
	int n,a,i;
	char str[T],*p;
	
	scanf ("%d",&n);
	
	for (n;n>0;n--){
		
		scanf ("%d",&a);
		scanf ("%*c%[^\n]%*c",str);
		
		p=prefix(a,str);
		
		printf ("%s",p);

		if (n-1>0) printf ("\n");
	}
	
	return 0;
}

char *prefix (int a, char *str){
	int i=0;
	
	if (a>T) return NULL;
	
	else str[a]='\0';
	
	return str;
}
