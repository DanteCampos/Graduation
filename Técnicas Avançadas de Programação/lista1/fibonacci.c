#include<stdio.h>

int main(){
	int patual, panterior, i;
	unsigned long long int fibonacci[5001];
	
	fibonacci[0] = 0;
	fibonacci [1] = 1;
	fibonacci [2] = 1;
	panterior = 2;
	
	while (scanf ("%d", &patual) != EOF){
		if (patual>panterior && patual>1) for (i=panterior+1; i<patual+1; i++) fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
		
		printf ("The Fibonacci number for %d is %Lu\n", patual, fibonacci[patual]);
		panterior = patual;
	}
	return 0;
}
