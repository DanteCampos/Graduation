#include <iostream>

using namespace std;

int fib(int a){
	if (a<2)
		return 1;
	else
		return fib(a-1) + fib(a-2);
}

int main (){
	int n;
	cin >>n;
	cout <<fib(n);
	
	return 0;
}
