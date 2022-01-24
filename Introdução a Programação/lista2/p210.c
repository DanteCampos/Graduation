#include <stdio.h>

int main(){

	int x,x1,x2,x3,x4;
	
	scanf ("%d",&x);
	
	if (x>9999){
		printf("Numero invalido!");
	}else{
		
			x1 = x/1000;
			x2 = x%1000/100;
			x3 = x%100/10;
			x4 = x%10;

		if (x>999){
			
			printf("(quarta ordem) %d = ",x);

			if (x1==1){
				printf("%d unidade de milhar ",x1);
			}else if (x1==0){

			}else{
				printf("%d unidades de milhar ",x1);
			}

			if (x2==1){
				printf("+ %d centena ",x2);
			}else if (x2==0){

			}else{
				printf("+ %d centenas ",x2);
			}
			
			if (x3==1){
				printf("+ %d dezena ",x3);
			}else if (x3==0){

			}else{
				printf("+ %d dezenas ",x3);
			}
		
			if (x4==1){
				printf("+ %d unidade ",x4);
			}else if (x4==0){

			}else{
				printf("+ %d unidades ",x4);
			}

			printf("= ");

			if (x1==0){
			
			}else{
				printf("%d ",x1*1000);
			}

			if (x2==0){
			
			}else{
				printf("+ %d ",x2*100);
			}
			
			if (x3==0){
			
			}else{
				printf("+ %d ",x3*10);
			}

			if (x4==0){
			
			}else{
				printf("+ %d",x4);
			}

		}else if (x>99){
			
			printf("(terceira ordem) %d = ",x);

			if (x2==1){
				printf("%d centena ",x2);
			}else if (x2==0){

			}else{
				printf("%d centenas ",x2);
			}
			
			if (x3==1){
				printf("+ %d dezena ",x3);
			}else if (x3==0){

			}else{
				printf("+ %d dezenas ",x3);
			}
		
			if (x4==1){
				printf("+ %d unidade ",x4);
			}else if (x4==0){

			}else{
				printf("+ %d unidades ",x4);
			}
			
			printf("= ");

			if (x2==0){
			
			}else{
				printf("%d ",x2*100);
			}

			if (x3==0){
			
			}else{
				printf("+ %d ",x3*10);
			}
			
			if (x4==0){
			
			}else{
				printf("+ %d",x4);
			}

			
		}else if (x> 9){
			
			printf("(terceira ordem) %d = ",x);

			if (x1==1){
				printf("%d dezena ",x3);
			}else if (x1==0){

			}else{
				printf("%d dezenas ",x3);
			}
			
			if (x2==1){
				printf("+ %d unidade ",x4);
			}else if (x2==0){

			}else{
				printf("+ %d unidades ",x4);
			}

			printf("= ");

			if (x3==0){
			
			}else{
				printf("%d ",x3*10);
			}

			if (x4==0){
			
			}else{
				printf("+ %d",x4);
			}

		}else if (x>=0){
			
			printf("(terceira ordem) %d = ",x);

			if (x==1){
				printf("%d unidade ",x);
			}else{
				printf("%d unidades ",x);
			}
			
			printf("= %d",x);
			
		}else{

		}
		
	}

	return 0;
}
