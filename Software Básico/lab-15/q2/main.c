#include <stdio.h>

int aux(int a, int b, int c, int d, int e, int f);

int calc(int i, int j, int k, int l, int m, int n) {

	printf("calc: %d, %d, %d, %d, %d, %d\n", i, j, k, l, m, n);

	return 0;
}



int main() {

	int r = aux(1, 2, 3, 4, 5, 6);

	printf("main: %d\n", r);
	return 0;
}
