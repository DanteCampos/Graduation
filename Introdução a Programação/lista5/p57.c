#include <stdio.h>

int numcarac (char*str);

int main (){
	
	int n;
	char str[6];
	
	scanf ("%d",&n);
	
	for (n;n>0;n--){
	
		scanf ("%s",str);
		
		if (numcarac (str)==5) printf ("3");
		else{
			if (str[0]=='o'&&(str[1]=='n'||str[2]=='e')) printf ("1");
			else printf ("2");
		}
		printf ("\n");
	}
	return 0;
}

int numcarac (char*str){
	int i;
	for (i=0;str[i]!=0;i++);
	return i;
}
