#include <stdio.h>
#define VAZIO -1
#define SIZE 15
#define TRUE (1==1)

void initiateHeap (int *heap, int size){
	int i;
	for (i=0;i<size;i++) heap[i] = VAZIO;
	return;
}

void printHeap (int *heap, int size){
	int i;
	for (i=0; i <size; i++) printf ("%d ",heap[i]);
	return;
}

int father (int pos){
	return (pos-1)/2;
}

int leftSon(int pos){
	return pos*2 +1;
}

int rightSon (int pos){
	return pos*2 +2;
}

void swap (int *heap, int pos1, int pos2){
	int aux;
	aux = heap[pos1];
	heap[pos1] = heap[pos2];
	heap[pos2] = aux;
	return;
}

void bubbleUp (int *heap, int pos){
	int Father = father(pos);
	
	while (heap[pos] < heap[Father]){ //min heap
		swap (heap, pos, Father);
		pos = Father;
		Father = father(pos);
	}
	return;
}

void putOnHeap(int *heap, int size, int n){
	int i;
	for (i=0; i < size; i++){
		if (heap[i] == VAZIO){
			heap[i] = n;
			bubbleUp (heap, i);
			return;
		}
	}
	
	printf ("Heap is full!");
	return;
}

int pullOffHeap (int *heap, int size){
	int aux, i, pos=0, ls, rs;
	aux = heap[0];
	
	for (i = size-1; i>0 && heap[i]==VAZIO; i--);
	heap[0] = heap[i];
	heap[i] = VAZIO;
	
	while (TRUE){
		ls = leftSon(pos);
		rs = rightSon(pos);
		if (ls>=size) break;
		else if (heap[ls] == VAZIO) break;
		else if (rs >= size){
			if (heap[pos] > heap[ls]){
				swap (heap, pos, ls);
				pos = ls;
			}
			break;
		}else if (heap[rs]==VAZIO){
			if (heap[pos] > heap[ls]){
				swap (heap, pos, ls);
				pos = ls;
			}
			break;
		}else{
			if (heap[ls] < heap[rs]){
				swap (heap, pos, ls);
				pos = ls;
			}else{
				swap (heap, pos, rs);
				pos = rs;
			}
		}
	}
	
	return aux;
}


int main (){
	int heap[SIZE], option, a;
	
	initiateHeap (heap, SIZE);
	printf ("MIN HEAP\n\n1 Put number on heap\n2 Pull off heap root\n3 Print heap\n0 Close Program\n\n");
	while (TRUE){
		
		scanf ("%d", &option);
		switch (option){
			case 0:
				return 0;
			case 1:
				printf ("Input the number you want to put on the heap:\n");
				scanf ("%d", &a);
				putOnHeap(heap, SIZE, a);
				break;
			case 2:
				a = pullOffHeap (heap, SIZE);
				if (a == VAZIO) printf ("Empty heap!");
				else printf ("%d pulled off!\n", a);
				break;
			case 3:
				printHeap(heap, SIZE);
				printf ("\n");
				break;
			default:
				break;
		}
	}
}
