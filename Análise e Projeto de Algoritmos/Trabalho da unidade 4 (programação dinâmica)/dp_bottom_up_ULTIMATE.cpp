#include <bits/stdc++.h>
#define EMPTY -1
#define MAXLEN 1001

using namespace std;

int DNA[MAXLEN][MAXLEN];

// Printar a tabela DNA (que armazena a programação dinâmica)
void print_table (string S1, string S2){
	int s1_size = S1.size();
	int s2_size = S2.size();
	
	int rows = s1_size + 1;
	int cols = s2_size + 1;
	
	cout<<endl<<"  " <<'0';
	for (int i = 0; i < s2_size; i++)
		cout << ' ' << S2[i];
	cout << endl;
	
	for (int i=0; i < rows; i++){
		if (i==0)
			cout << '0';
		else
			cout << S1[i-1];
		
		for (int j = 0; j < cols; j++)
			cout <<' '<< DNA[i][j];
			
		cout << endl;
	}
	
	cout << endl;
}


int main(){
	// Zerando linha 0 e coluna 0 da DP porque são a subsequência com a string nula (caso base i==0 or j==0)
	for (int i = 0; i < MAXLEN; i++)
		DNA[i][0] = 0;
	for (int j = 0; j < MAXLEN; j++)
		DNA[0][j] = 0;

	// Pra cada problema: ler o tamanho mínimo do segmento (k) e as duas strings (S1 e S2)
	int k;
	string S1, S2;
	while(cin >> k and k != 0){
		cin >> S1;
		cin >> S2;
		
		int s1_size = S1.size();
		int s2_size = S2.size();
		
		// Por adicionarmos a linha e a coluna de string vazia no começo, somamos 1 às dimensões da matriz
		int rows = s1_size + 1;
		int cols = s2_size + 1;
		
		// i e j são posições na tabela, para acessar as strings, usamos i-1 e j-1 (por conta das linhas/colunas 0)
		// Para cada posição (i,j) na tabela DNA que não é caso base:
		for (int i=1; i < rows; i++)
			for (int j=1; j < cols; j++){
			
			// Verificamos se a posição (i,j) é o final de um segmento >= k
			// olhando na diagonal enquanto dentro de um segmento comum de tamanho l
			// Dentre os possíveis segmentos l, pegamos o "corte" que nos dá a maior subsequência com segmentos >=k
			int diag = 0;
			for(int l=0; i-1-l >= 0 and j-1-l >= 0 and S1[i-1-l] == S2[j-1-l]; l++){
				// Ao entrar aqui, significa que o segmento atual tem comprimento l+1, mas não incrementamos l ainda
				// Por isso, em vez de l, vamos usar l+1
				if (l+1>=k)
					diag = max(DNA[i-(l+1)][j-(l+1)] + l+1, diag); // Fazemos um "corte" de um segmento de tamanho l
			}
			
			// Escolhe o maior: diagonal (o maior segmento escolhido),
			// cima (excluindo o último caractere de S1) ou esquerda (excluindo o último caractere de S2)
			DNA[i][j] = max({DNA[i-1][j], DNA[i][j-1], diag});
		}
		
		// O resultado do problema completo:
		cout << DNA[s1_size][s2_size] << endl;

		// Para printar a tabela, descomente a linha abaixo:
		//print_table (S1, S2);
	}

	return 0;
}
