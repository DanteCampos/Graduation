#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin >>n;
	
	cout.precision(4);
	cout << fixed;
	
	while (n--){
		double number;
		cin >>number;
		cout<< sqrt(number)<<endl;
	}
	
	return 0;
}
