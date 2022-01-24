#include <iostream>

using namespace std;

int main(){
	int n, count=0;
	
	cin >>n;
	
	while (n--){
		int l,c;
		cin >>l >>c;
		if (l>c) count+=c;
	}
	
	cout <<count;
	
	return 0;
}
