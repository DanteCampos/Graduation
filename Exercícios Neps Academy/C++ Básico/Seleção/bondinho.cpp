#include <iostream>
using namespace std;

int main(){
	int alunos, monitores;
	cin >>alunos >>monitores;
	
	if (alunos + monitores > 50) cout <<"N";
	else cout <<"S";
	
	return 0;
}
