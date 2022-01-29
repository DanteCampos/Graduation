#include <ctype.h>
#include <stdio.h>

int symbol(int num){
	if (num<10)
		return num+'0';
	else
		return num-10+'a';
}

int n_of_digits(int num, int base){
	int i;
	
	if(num==0)
		return 1;
	
	for (i=0;num>0;i++)
		num/=base;
		
	return i;
}

void num2string(int num, int base, char *resp){
	int i=n_of_digits(num,base);
	
	resp[i]='\0';
	
	for (i--;i>=0;i--){
		resp[i]=symbol(num%base);
		num/=base;
	}
}

int main () {
  char buf[128];

  num2string(1024, 2, buf);
  printf("==> %s\n", buf);

  num2string(1024, 16, buf);
  printf("==> %s\n", buf);

  num2string(1024, 32, buf);
  printf("==> %s\n", buf);

  return 0;
}
