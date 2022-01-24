#include <stdio.h>

int procura (char a, char *str);

int main (){
	
	int n,x;
	char a, *str;
	
	scanf ("%d",&n);
	
	for (n;n>0;n--){
	
		scanf ("%*c %c %[^\n]",&a,str);
		
		x = procura (a,str);
		
		if (x==-1) printf ("Caractere %c nao encontrado.\n",a);
		else printf ("Caractere %c encontrado no indice %d da string.\n",a,x);
	}
	return 0;
}

int procura (char a, char *str){

	int i;
	
	for (i=0;str[i]!='\0';i++){
		if (str[i]==a) return i;
	}
	return -1;
}
