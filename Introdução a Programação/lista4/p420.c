#include <stdio.h>
#define T 33
#define L 100

int string_cmp (char * s1, char * s2);
void string_swap(char * s1, char * s2);

int main (){
	
	char str[L][T];
	int n;
	
	scanf ("%d",&n);
	
	for (n;n>0;n--){
	
		scanf ("%s",str[n]);
		
		if (string_cmp (str[n],str[n+1])==2) string_swap (str[n],str[n+1]);
	}
	
	for(n=0;n<T;n++){
		if (str[n]==0) return 0;
		printf ("%s",str[n]);	
	}
	
	return 0;
}

int string_cmp (char * s1, char * s2){
	
	char i;
	for (i=0;i<T;i++){
		if (s1[i]<s2[i]) return 1;
	}
	return 2;
}

void string_swap(char * s1, char * s2){
	
	char s3[T],i;
	for (i=0;i<T;i++) s3[i]=s1[i];
	for (i=0;i<T;i++) s1[i]=s2[i];
	for (i=0;i<T;i++) s2[i]=s3[i];
}
