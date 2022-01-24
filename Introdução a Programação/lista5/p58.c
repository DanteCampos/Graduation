#include <stdio.h>

void tirazero (char*);

int main (){
	
	int a,b,i;
	char s[10];
	
	do{
		scanf ("%d %d",&a,&b);
		
		sprintf (s,"%d",a+b);
		
		for (i=0;i<10;i++){
			if (s[i]==0) break;
			if (s[i]=='0') continue;
			else printf ("%c",s[i]);
		}
		
		printf ("\n");
	
	}while (a!=0 && b!=0);
	
	return 0;
}

