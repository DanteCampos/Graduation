#include <iostream>

using namespace std;

int main(){
	double a,b;
	
	cin >>a >>b;
	
	a=(a+b)/2;
	
	if (a>=7) cout <<"Aprovado";
	else if (a>=4) cout<<"Recuperacao";
	else cout<<"Reprovado";
	
	return 0;
}
