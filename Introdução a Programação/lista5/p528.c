#include <stdio.h>
#define T 51

int main(){
	
	char str[T];
	int i,p;
	
	while (scanf("%[^\n]%*c",str)!=EOF){
		p=2;
		for (i=0;str[i]!='\0';i++){
			if ((str[i]<'A') || (str[i]>'Z' && str[i]<'a') || (str[i]>'z')) continue;
			else{
				if (p==2){ //primeira letra da string, deve ser maiúscula
					p=0; //próxima letra deve ser minúscula
					if (str[i]>='A' && str[i]<='Z') continue;
					else str[i]-=('a'-'A');
				}
				
				else if (p==0){ //a letra deve ser minúscula
					p=1; //próxima letra deve ser maiúscula
					if (str[i]>='a' && str[i]<='z') continue;
					else str[i]+=('a'-'A');
				}
				
				else if (p==1){ //a letra deve ser maiúscula
					p=0; //próxima letra deve ser minúscula
					if (str[i]>='A' && str[i]<='Z') continue;
					else str[i]-=('a'-'A');
				}
			}
		}
		
		printf ("%s\n",str);
	}
	
	return 0;
}
