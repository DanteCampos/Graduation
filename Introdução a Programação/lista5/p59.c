#include <stdio.h>

void cript (char*v);

int main (){
	
	int n;
	char *v;
	
	scanf ("%d%*c",&n);
	
	for (n;n>0;n--){
		scanf ("%[^\n]%*c",v);
		
		cript (v);
		
		printf ("%s\n",v);
		}
	return 0;
}

void cript (char*v){

	int i=0,j=0,T;
	char aux;

	for (T=0;v[i]!='\0';i++) T++; //contar quantidade de caracteres

	for (i=0;i<T;i++){ //passagem 1:adicionar +3 ao char de letras
		if ((v[i]>='a'&&v[i]<='z')||(v[i]>='A'&&v[i]<='Z')) v[i]=v[i]+3;
	}
	
	i--;
	
	while (i>0){ //passagem 2: inverter o vetor
	
		if (j>=i) break;
		
		aux=v[j];
		v[j]=v[i];
		v[i]=aux;
		
		j++;
		i--;
	}
	for (j/2;j<T;j++) v[j]--; //passagem 3: subtrair -1 de todos os caracteres
	
	return;
}
