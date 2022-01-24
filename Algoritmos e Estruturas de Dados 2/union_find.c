#include <stdio.h>
#define SIZE 15
#define TRUE (1==1)

void initiateSet (int *set, int size){
	int i;
	for (i=0; i < size; i++) set[i]=i;
	return;
}

int root (int *set, int pos){
	int root;
	for (root = set[pos]; root != set[root]; root = set[root]);
	return root;
}

void unite (int *set, int pos1, int pos2){
	set[root(set, pos1)] = root(set, pos2);
	return;
}

void compress (int *set, int size){
	int i;
	for (i=0;i < size; i++) set[i] = root (set, i);
	return;
}

void printConnections (int *set, int size){
	int i;
	printf ("Connections:\n");
	for (i=0;i<size;i++)printf ("%d ", i);
	printf ("\n");
	for (i=0;i<size;i++)printf ("%d ", set[i]);
}

void printRoots (int *set, int size){
	int i;
	printf ("Connections:\n");
	for (i=0;i<size;i++)printf ("%d ", i);
	printf ("\n");
	for (i=0;i<size;i++)printf ("%d ", root(set,i));
}

int numberSets(int *set, int size){
	int i, count=0;
	for (i=0;i<size;i++) if (set[i] == i) count++;
	return count;
}

int main (){
	int set[SIZE], option, a, b;
	
	initiateSet (set, SIZE);
	
	while (TRUE){
		printf ("\n\nUNION - FIND\n\n1 Unite two positions\n2 Find the root of a position\n3 Copress set\n4 Print the connections of the positions\n5 Print the root of the positions\n6 Number of sets\n0 Close Program\n\n");
		scanf ("%d", &option);
		printf ("\n\n");
		switch (option){
			case 0:
				return 0;
			case 1:
				printf ("Input two positions to unite:\n");
				scanf ("%d %d", &a, &b);
				unite (set, a, b);
				printf ("%d and %d united!",a,b);
				break;
			case 2:
				printf ("Input the position which you want to find the root:\n");
				scanf ("%d",&a);
				printf ("Root of %d = %d",a, root(set, a));
				break;
			case 3:
				compress (set, SIZE);
				printf ("Set compressed!");
				break;
			case 4:
				printConnections(set, SIZE);
				break;
			case 5:
				printRoots(set, SIZE);
				break;
			case 6:
				printf ("There are a total of %d subsets in the set", numberSets(set, SIZE));
				break;
			default:
				break;
		}
	}
}
