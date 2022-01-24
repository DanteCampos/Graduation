#include <iostream>

using namespace std;

int main(){
	int n, array[10000];
	
	cin >>n;
	
	for (int i; i<n; i++) cin>>array[i];
	
	int count=0;
	for (int i; i<n-2; i++)
		if (array[i]==1 and array[i+1]==0 and array[i+2]==0)
			count++;
	
	cout <<count;
	
	return 0;
}
