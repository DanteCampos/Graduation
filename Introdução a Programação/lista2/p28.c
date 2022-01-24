#include <stdio.h>

int main(){

	int x;
	
	scanf ("%d",&x);
	
	if (x < 1){
		x = x;
	}else if (x == 1){
		x = 0;
	}else{
		x *= x;
	}

	printf("Y = %d\n",x);

	return 0;
}


