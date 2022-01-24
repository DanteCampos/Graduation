#include <stdio.h>
#include <math.h>
#define T 129

long int string2int (char * str);

int main (){

	long int n;
	char str[T];

	while (scanf("%s",str)!=EOF){
	
		n = string2int (str);
		
		printf ("%ld %ld\n",n,n*2);
	}
	return 0;
}

long int string2int (char * str){
	int i;
	long int a=0,casas=0;
	
	for (i=0;i<T;i++){
		if ((str[i]<'0'||str[i]>'9')&&str[i]!='-') break;
		if (str[i]=='-') casas--;
		casas++;
	}
	
	if (str[0]=='-'){
		for (i=1;i<T;i++){
			if (str[i]<'0'||str[i]>'9') break;
			a-=(str[i]-'0')*((long int)pow(10,casas-1));
			casas--;
			
		}
	}else{
		for (i=0;i<T;i++){
			if (str[i]<'0'||str[i]>'9') break;
			a+=(str[i]-'0')*((long int)pow(10,casas-1));
			casas--;
			
		}
	}
	return a;
}
