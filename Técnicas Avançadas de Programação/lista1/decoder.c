#include <stdio.h>

int main(){
	char caractere;
	
	while (scanf ("%c",&caractere) != EOF){
		if (caractere == '\n'){
			printf ("\n");
			continue;
		}
		
		printf ("%c", caractere-('p'-'i'));
	}
	return 0;
}
