#include <stdio.h>
#include <string.h>
#define T 257

int main(){
	
	char str [T], clr [T];
	
	int i,j,l;
	
	scanf ("%[^\n]%*c",str);
	scanf ("%[^\n]",clr);
	
	for (i=0;clr[i]!='\0';i++){
		for (j=0;str[j]!='\0';j++){
			if (str[j]==clr[i]){
				for (l=j+1;str[l-1]!='\0';l++) str[l-1]=str[l];
				j=-1;
			}
		}
	}
	
	printf ("%s",str);
	
	return 0;
}
