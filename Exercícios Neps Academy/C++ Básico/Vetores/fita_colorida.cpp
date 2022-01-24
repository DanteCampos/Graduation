#include<iostream>

using namespace std;

int main(){
	int n, array[10000];
	
	cin >>n;
	
	for (int i=0; i<n; i++){
		int v;
		cin >>v;
		
		if (v) array[i]= 9;
		else array[i] = 0;
	}
	
	for (int i=0; i<n; i++){ //looking for 0's
		if (array[i]!=0) continue;
		
		for (int j=1; i-j >= 0; j++){ //left side
			if (array[i-j] == 0 or array[i-j]<j) break;
			else array[i-j] = j;
		}
		
		for (int j=1; i+j < n; j++){ //right side
			if (array[i+j] == 0 or array[i+j]<j) break;
			else array[i+j] = j;
		}
		
	}
	
	for (int i=0; i<n; i++)
		cout <<array[i] <<" ";
	
	return 0;
}
