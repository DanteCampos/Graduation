#include <stdio.h>

int main(){

	int a,b,c,d;

	scanf("%d %d %d %d",&a,&b,&c,&d);

	if ((a>=b) && (a>=c) && (a>=d)){

		printf("%d\n",(b+c+d));

	}else if ((b>=a) && (b>=c) && (b>=d)){

		printf("%d\n",(a+c+d));

	}else if ((c>=a) && (c>=b) && (c>=d)){

		printf("%d\n",(a+b+d));

	}else{

		printf("%d\n",(a+b+c));

	}

	return 0;
}
