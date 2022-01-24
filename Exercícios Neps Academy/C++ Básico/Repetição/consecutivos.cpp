#include <iostream>

using namespace std;

int main(){
	int n,a,b, count,max;
	cin >>n;
	
	cin >>a;
	
	for (max=count=1;--n;a=b){
		cin >>b;
		if (a==b) count++;
		if (count > max) max = count;
		if (a!=b) count=1;
	}
	
	cout <<max;
	
	return 0;
}
