#include <iostream>

using namespace std;

int main(){
	int n, a=0,b=0;
	
	cin >>n;

	while (n--){
		int command;
		cin >>command;
		if (command == 1) a = !a;	
		else{
			a = !a;
			b = !b;
		}
	}

	cout <<a<<endl<<b<<endl;
	
	return 0;
}
