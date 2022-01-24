#include <stdio.h>
#include <math.h>
#define T 129

double string2double (const char * str);

int main (){
	
	char str[T];
	double n;
	
	while (scanf ("%s",str)!=EOF){
		
		n=string2double (str);
		
		printf ("%.3lf %.3lf\n",n,n*2);
	}
	return 0;
}

double string2double (const char * str){
	
	int i=0,casas=0,ponto;
	long int parteint=0;
	double partefrac=0;
	
	if (str[0]=='-') i=1;
	for (i;(str[i]!=0) && (str[i]!='.');i++) casas++;
	
	if (str[0]=='-') i=1;
	else i=0;
	
	ponto = casas+i;
	
	if (i==0){
		for (i;casas>0;i++){
			parteint+=(str[i]-'0')*pow(10,casas-1);
			casas--;
		}
		
		if (str[ponto]==0) return (double)parteint;
		
		casas=1;
		
		for (i=ponto+1;str[i]!=0;i++){
			partefrac+=((double)str[i]-'0')*pow(10,-casas);
			casas++;
		}	
	}else{
		for (i;casas>0;i++){
			parteint-=(str[i]-'0')*pow(10,casas-1);
			casas--;
		}
		
		if (str[ponto]==0) return (double)parteint;
		
		casas=1;
		
		for (i=ponto+1;str[i]!=0;i++){
			partefrac-=((double)str[i]-'0')*pow(10,-casas);
			casas++;
		}
	}
	return (double)parteint+partefrac;
}
