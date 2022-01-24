#include <iostream>

using namespace std;

int main(){
	int n;
	string prova;
	cin>>n>>prova;
	
	int count=0;
	for (int i=0; i<n; i++){
		char c;
		cin>>c;
		if (c==prova[i])
			count++;
	}
	
	cout<<count;
	
	return 0;
}
