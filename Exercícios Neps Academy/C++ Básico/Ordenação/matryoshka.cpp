#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	
	int original[n];
	int sorted[n];
	
	for(int i=0;i<n;i++){
		cin >>original[i];
		sorted[i]=original[i];
	}
	
	sort(sorted, sorted+n);
	
	int count=0;
	for (int i=0;i<n;i++)
		if (sorted[i] != original[i])
			count++;
	
	cout<<count<<endl;
	
	for (int i=0;i<n;i++)
		if (sorted[i] != original[i])
			cout<<sorted[i]<<' ';
	
	return 0;
}
