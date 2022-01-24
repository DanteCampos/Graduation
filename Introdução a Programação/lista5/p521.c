#include <stdio.h>
#include <string.h>

int avance (char *a, char *b);

int main (){
	
	int n,x;
	char a[1000], b[1000];
	scanf ("%d",&n);
	
	for (n;n>0;n--){
	
		scanf ("%s %s",a,b);
	
		printf ("%d\n",avance(a,b));
	}
	return 0;
}

int avance (char *a, char *b){
	
	int i,tamanho=strlen(a),x=0;
	
	for (i=0;i<tamanho;i++){
	
		if (a[i]>b[i]) x += b[i]-a[i] + ('z'-'a'+1);
		else x+= b[i]-a[i];
	}
	return x;
}
