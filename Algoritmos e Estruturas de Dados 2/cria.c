#include <stdio.h>

int main (){
	int i;
	
	printf ("1\n");
	for (i=-1000;i<100;i++) printf ("2 %d %d\n", i, i+1);
	for (i=8000;i>6000;i--) printf ("2 %d %d\n", i, i+1);
	for (i=300; i<5000; i++) printf ("2 %d %d\n", i, i+1);
	printf ("6\n7\n5\n3 1000\n7\n4 1000\n3 1000\n6\n7\n8\n0");
	return 0;

}
