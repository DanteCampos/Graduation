#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comparaAlfabetica (pair <int, string> A, pair <int, string> B){
	return A.second < B.second;
}

int main(){
	
	int N, T;
	cin >> N >> T;
	
	vector <pair <int, string>> alunos;
	
	for (int i=0; i < N; i++){
		pair <int, string> aux;
		cin >> aux.second >> aux.first;
		alunos.push_back(aux);
	}
	
	sort (alunos.begin(), alunos.end());
	
	vector<vector<pair<int,string>>> times (T);
	
	int time_atual = 0;
	for (auto it = alunos.rbegin(); it != alunos.rend(); it++){
		times[time_atual].push_back(*it);
		time_atual = (time_atual+1)%T; //Avança time e volta pro primeiro depois do último
	}
	
	for (int i = 0; i < T; i++){
		sort (times[i].begin(), times[i].end(), comparaAlfabetica);
		cout << "Time " << i+1 << '\n';
		for (auto it = times[i].begin() ; it != times[i].end(); it++){
			cout << (*it).second <<'\n';
		}
		cout << '\n';
	}
	
	return 0;
}
