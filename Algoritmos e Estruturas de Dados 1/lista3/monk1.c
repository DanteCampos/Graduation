#include <stdio.h>

int main (){
	int n,vogais=0;
	char c;
	
	scanf ("%d",&n);
	getchar();
	
	while (n>0){
		scanf ("%c",&c);
		if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') vogais++;
		else if (c=='\n'){
			printf ("%d\n",vogais);
			vogais=0;
			n--;
		}
	}
	
	return 0;
}
