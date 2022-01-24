#include <iostream>

using namespace std;

int main(){
	
	int n,p,q;
	char operacao;
	
	cin >>n>>p;
	cin.ignore();
	cin>>operacao>>q;
	
	if ((operacao == '+' and (p+q>n)) or (operacao=='*' and (p*q>n)))
		cout<<"OVERFLOW";
	else
		cout<<"OK";
	
	return 0;
}
