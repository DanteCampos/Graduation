#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	
	int max, N;
	
	cin >> max >> N;
	
	vector <pair<int, int>> intervalo;
	
	for (int i = 0; i < N; i++){
		pair <int, int> aux;
		cin >>aux.first >>aux.second;
		intervalo.push_back(aux);
	}
	
	sort(intervalo.begin(), intervalo.end());
	
	auto it = intervalo.begin();
	while(it != intervalo.end()){
		pair <int, int> aux = (*it);
		
		/*
		aux já está com menor início do seu intervalo, falta achar o final
		CASOS:
			DESCONEXO aux.first <= aux.second < it->first <= it->second
			DENTRO aux.first <= it->first <= it->second <= aux.second
			UNIDO aux.first <= it->first <= aux.second <= it->second
			
			DESCONEXO -> aux é o maior intervalo que conseguimos, começa um novo a partir de it
			DENTRO -> mantém aux do jeito que está e ignora it
			UNIDO -> aux.second extende para it->second
			
			Lembrando que aux.first <= aux.second e it->first <= it->second são verdades
		*/
		
		for (it++ ;it != intervalo.end(); it++){
			if (aux.second < it->first) //DESCONEXO
				break;
			if (it->second <= aux.second) //DENTRO
				continue;
			else //UNIDO
				aux.second = it->second;
		}
		
		cout << aux.first << ' ' << aux.second << '\n';
	}
	
	return 0;
}
