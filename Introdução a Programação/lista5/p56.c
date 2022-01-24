#include <stdio.h>

void letvogcon (char*v);

int main (){
	
	int n;
	char v[10001];
	
	scanf ("%d%*c",&n);
	
	for (n;n>0;n--){
	
		scanf ("%[^\n]%*c",v);
		letvogcon (v);
		
	}
	
	return 0;
}

void letvogcon (char*v){
	
	int i=0,let=0,vog=0,con=0;
	
	while (v[i]!='\0'){
		
		if ((v[i]>='a'&&v[i]<='z')||(v[i]>='A'&&v[i]<='Z')){
			let++;
			if ((v[i]=='a')||(v[i]=='e')||(v[i]=='i')||(v[i]=='o')||(v[i]=='u')||(v[i]=='A')||(v[i]=='E')||(v[i]=='I')||(v[i]=='O')||(v[i]=='U')) vog++;
			else con++;
		}
		
		i++;
	}
	printf ("Letras = %d\n",let);
	printf ("Vogais = %d\n",vog);
	printf ("Consoantes = %d\n",con);
}
