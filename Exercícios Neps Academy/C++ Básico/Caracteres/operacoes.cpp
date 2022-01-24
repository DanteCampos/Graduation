#include <iostream>

using namespace std;

int main(){
	
	double a, b;
	char operacao;
	
	cin >>operacao;
	cin >>a>>b;
	
	cout.precision(2);
	cout<<fixed;
	
	if (operacao=='M')
		cout<<(a*b);
	else
		cout<<(a/b);
	
	return 0;
}
