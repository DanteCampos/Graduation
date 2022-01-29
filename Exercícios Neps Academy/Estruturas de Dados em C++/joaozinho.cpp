#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	
	int max, N;
	
	vector <pair<int, int>> intervalo;
	
	for (int i = 0; i < N; i++){
		pair <int, int> aux;
		cin >>aux.first >>aux.second;
		intervalo.push_back(aux);
	}
	
	sort(intervalo.begin(), intervalo.end());
	
	vector <pair<int, int>> unioes;
	
	auto it = intervalo.begin();
	while(true){
		pair <int, int> aux = (*it);
		
		for (it++ ; (*it).begin < aux.second; it++)
			aux.second = (*it).second;
		
		unioes.push_back(aux);
	}
	
	for (auto it = unioes.begin(); it != unioes.end(); it++)
		cout << (*it).first << ' ' << (*it).second << '\n';
	
	return 0;
}
