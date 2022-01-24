#include <stdio.h>

int main(){
	char caractere;
	int palavras=0,letra=0;
	
	while (scanf("%c",&caractere) != EOF){
		if ((caractere>='a' && caractere <='z') || (caractere >= 'A' && caractere <= 'Z')) letra=1;
		else if (letra==1){
			palavras++;
			letra=0;
		}
		
		if (caractere == '\n' || caractere == EOF){
			printf ("%d\n",palavras);
			palavras=0;
		}
	}
	return 0;
}
