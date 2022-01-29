#include <vector>
#include <iostream>

using namespace std;

int main (){

	int n;
	cin >> n;
	
	int i = n;
	
	vector <int> fila;
	
	while (i--){
		int aux;
		cin >> aux;
		fila.push_back(aux);
	}
	
	int m;
	cin >> m;
	
	
	for (i = m; i; i--){
		int id;
		cin >> id;
		
		int pos;
		for (pos = 0; pos < n; pos++){
			if (id == fila[pos]){
				fila.erase(fila.begin() + pos);
				break;
			}
		}
	}
	
	for (i=0; i < n-m; i++)
		cout << fila[i] << ' ';
	
	
	return 0;
}
