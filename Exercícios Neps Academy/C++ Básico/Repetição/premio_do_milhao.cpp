#include <iostream>

using namespace std;

int main(){
	int i,n, sum=0, day=0;
	
	cin>>n;
	
	for (i=0;i<n;i++){
		int number;
		cin>>number;
		sum+=number;
		if (sum >= 1000000 and day==0)
			day=i+1;
	}
	
	cout <<day;
	
	return 0;
}
