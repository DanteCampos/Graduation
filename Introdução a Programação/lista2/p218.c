#include <stdio.h>

int main(){

	int x1,x2,x3,a,b,c;
	char y1,y2,y3;

	
	scanf ("%d %d %d\n %c%c%c",&x1,&x2,&x3,&y1,&y2,&y3);

	if ((x1<=x2) && (x1<=x3)){
		a = x1;

		if (x2<=x3){
			b = x2;
			c = x3;
		}else{
			b = x3;
			c = x2;		
		}

	}else if ((x2<=x1) && (x2<=x3)){
		a = x2;
		
		if (x1<=x3){
			b = x1;
			c = x3;
		}else{
			b = x3;
			c = x1;
		}	
	}else{
		a = x3;
		
		if (x1<=x2){
			b = x1;
			c = x2;
		}else{
			b = x2;
			c = x1;
		}	
	}
	
	if (y1 == 'A'){
	
		printf ("%d",a);
		
		if (y2 == 'B'){
			
			printf (" %d",b);
			printf (" %d",c);
		}else{
			
			printf (" %d",c);
			printf (" %d",b);
		}

	}else if (y1 == 'B'){

		printf ("%d",b);
		
		if (y2 == 'A'){
			
			printf (" %d",a);
			printf (" %d",c);
		}else{
			
			printf (" %d",c);
			printf (" %d",a);
		}

	}else{

		printf ("%d",c);
		
		if (y2 == 'A'){
			
			printf (" %d",a);
			printf (" %d",b);
		}else{
			
			printf (" %d",b);
			printf (" %d",a);
		}
	}
	
	printf ("\n");

	return 0;
}
