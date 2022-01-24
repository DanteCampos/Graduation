#include <bits/stdc++.h>
#define EMPTY -1

using namespace std;

string S1, S2;
int cache[1010][1010];
int k, s1_size, s2_size;

// i e j são as posições finais da substring a ser analisada: [0, ... , i] = tamanho i+1
int dpSol(int i, int j){
	
	if(i < 0 or j < 0)
		return 0;
		
	if(cache[i][j] != EMPTY)
		return cache[i][j];
	
	// Encontrando o maior segmento em comum na esquerda
	int seg;
	for (seg = 0; i-seg >= 0  and j-seg >= 0  and S1[i-seg] == S2[j-seg]; seg++);
	
	// Computando a resposta
	int ans = 0;
	
	// Olhando a diagonal enquanto dentro do segmento comum
	int l;
	for (l=k; l <= seg; l++) 
		ans = max(dpSol(i-l, j-l) + l, ans);
	
	// Olha baixo e direita quando estiver fora do segmento comum
	for (; i-l+1 >= 0 and j-l+1 >= 0; l++); 
		ans = max({dpSol(i - 1, j), dpSol(i, j - 1), ans});
	
	return cache[i][j] = ans;
}

void print_table (){
	// Printando a tabela
	
	cout<<endl<<"  " <<'0';
	for (int i = 0; i < s2_size; i++)
		cout << ' ' << S2[i];
	
	
	for (int i=0; i < s1_size+1; i++){
		cout << endl;
		if (i == 0)
			cout << '0';
		else
			cout << S1[i-1];
		
		for (int j = 0; j < s2_size+1; j++)
			cout <<' '<< cache[i][j];
	}
	
	cout << endl;
}

int main(){

while(cin >> k and k != 0){
	cin >> S1;
	cin >> S2;
	memset(cache, EMPTY, sizeof(cache));
	
	s1_size = S1.size();
	s2_size = S2.size();
	
	cout << dpSol(s1_size-1, s2_size-1) << endl;

	//print_table ();
	
}

return 0;
}
