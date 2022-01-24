#include <stdio.h>

int main(){

	unsigned int x,d,m,a;

	scanf ("%u", &x);

	d = x/1000000;
	m = x/10000 - d*100;
	a = x - d*1000000 - m*10000;

	if (d<1){
		printf ("Data invalida!");
	}else{

		if (m==1){
			if (d>31){
				printf ("Data invalida!");
			}else{
				printf ("%d de janeiro de %d",d,a);
			}
	
		}else if (m==2){
	
			if (d>28){
				printf ("Data invalida!");
			}else{
				printf ("%d de fevereiro de %d",d,a);
			}
		
		}else if (m==3){
	
			if (d>31){
				printf ("Data invalida!");
			}else{
				printf ("%d de marco de %d",d,a);
			}
	
		}else if (m==4){
	
			if (d>30){
				printf ("Data invalida!");
			}else{
				printf ("%d de abril de %d",d,a);
			}
	
		}else if (m==5){
	
			if (d>31){
				printf ("Data invalida!");
			}else{
				printf ("%d de maio de %d",d,a);
			}
	
		}else if (m==6){
	
			if (d>30){
				printf ("Data invalida!");
			}else{
				printf ("%d de junho de %d",d,a);
			}
	
		}else if (m==7){
	
			if (d>31){
				printf ("Data invalida!");
			}else{
				printf ("%d de julho de %d",d,a);
			}
	
		}else if (m==8){
	
			if (d>31){
				printf ("Data invalida!");
			}else{
				printf ("%d de agosto de %d",d,a);
			}
	
		}else if (m==9){
	
			if (d>30){
				printf ("Data invalida!");
			}else{
				printf ("%d de setembro de %d",d,a);
			}
	
		}else if (m==10){
	
			if (d>31){
				printf ("Data invalida!");
			}else{
				printf ("%d de outubro de %d",d,a);
			}
	
		}else if (m==11){
	
			if (d>30){
				printf ("Data invalida!");
			}else{
				printf ("%d de novembro de %d",d,a);
			}
	
		}else if (m==12){
	
			if (d>31){
				printf ("Data invalida!");
			}else{
				printf ("%d de dezembro de %d",d,a);
			}
		}else{
	
			printf ("Data invalida!");
	
		}
	}
		return 0;
}
