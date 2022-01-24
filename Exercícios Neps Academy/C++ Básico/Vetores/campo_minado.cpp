#include <iostream>

using namespace std;

int main(){
	int n, array[50];
	
	cin >>n;
	
	for (int i=0;i<n;i++)
		cin>>array[i];
	
	for (int i=0;i<n;i++){
	
		int count = array[i];
		if (i>0) count += array[i-1];
		if (i < (n-1)) count += array[i+1];
		
		cout <<count <<endl;
	}
	
	return 0;
}
