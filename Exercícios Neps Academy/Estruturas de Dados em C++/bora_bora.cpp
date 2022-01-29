#include <iostream>
#include <algorithm>
#include <vector>

#define HORARIO 1
#define ANTIHORARIO -1


using namespace std;

struct CARTA {
	int valor;
	char naipe;
};

typedef struct CARTA CARTA;

bool ordemCarta(CARTA a, CARTA b){
	if (a.valor < b.valor)
		return true;
	else if (a.valor == b.valor){
		if (a.naipe < b.naipe)
			return true;
	}
	
	return false;
}

int novoJogadorAtual (int jogador_atual, int total_jogadores, int sentido){
	jogador_atual += sentido;
	
	if (jogador_atual < 0)
		jogador_atual = total_jogadores -1;
	else if (jogador_atual >= total_jogadores)
		jogador_atual = 0;
	
	return jogador_atual;
}

int inverteSentido (int sentido){
	
	//cout << "Sentido invertido!\n";
	
	if (sentido == HORARIO)
		return ANTIHORARIO;
	else
		return HORARIO;
}

void jogadorCompraCarta (vector<CARTA>& mao_jogador, vector<CARTA>& saque){
	
	//cout << "Comprou 1 carta!\n";
	
	mao_jogador.push_back (saque[saque.size()-1]);
	saque.pop_back();
}

void descartaCarta (vector<CARTA>& mao_jogador, CARTA &carta_atual){
	
	//Garantindo que as maiores cartas estão no final da mão
	sort(mao_jogador.rbegin(), mao_jogador.rend(), ordemCarta);
	
	auto pos_descartada = mao_jogador.begin();
	
	//Vai procurando a maior carta que pode ser descartada
	for ( ; pos_descartada != mao_jogador.end() ; pos_descartada++){
		if ((*pos_descartada).valor == carta_atual.valor or (*pos_descartada).naipe == carta_atual.naipe){
			
			//Vai descartar essa carta
			
			//Carta atual do jogo alterada por parâmetro
			carta_atual = *pos_descartada;
			
			//cout << "Descartou a " << carta_atual.valor << carta_atual.naipe <<"\n";
			
			break;
		}
	}
	
	//cout<<"Vai eliminar da mão\n";
	
	//Eliminando a carta da mão do jogador
	mao_jogador.erase(pos_descartada);
	
	//cout << "Conseguiu eliminar\n";
	
	return;
}

/*
void veMaoDoJogador (vector <CARTA>& mao_do_jogador){
	for (int i= 0; i < mao_do_jogador.size(); i++)
		cout << mao_do_jogador[i].valor << mao_do_jogador[i].naipe << ' ';
	cout << '\n';
}
*/

bool jogadorPodeDescartar( vector <CARTA> mao_jogador, CARTA carta_atual){
	
	for (int i=0; i < mao_jogador.size(); i++)
		if (mao_jogador[i].valor == carta_atual.valor or mao_jogador[i].naipe == carta_atual.naipe){
			//cout << "Pode descartar a "<< mao_jogador[i].valor << mao_jogador[i].naipe <<"\n";
			return true;
		}
	return false;
}


int main(){

	while (true){
		int P, M, N;
		
		cin >> P >> M >> N;
		
		//N cartas totais, para P jogadores, cada um com M cartas na mão
		if (P == 0 and M == 0 and N == 0)
			break;
		
		vector <CARTA> saque, entrada;
		
		//Montando pilha de saque com N cartas
		for (int i=0; i < N; i++){
			CARTA aux;
			cin >> aux.valor >> aux.naipe;
			entrada.push_back(aux);
		}
		
		for (int i=0; i < N; i++){
			saque.push_back (entrada[entrada.size()-1]);
			entrada.pop_back();
		}
		
		/*
		cout << "Saque: ";
		veMaoDoJogador (saque);
		cout << '\n';
		*/
		
		vector<vector<CARTA>> jogadores(P);
		
		//Distribuindo M cartas da pilha de saque para cada um dos P jogadores
		for (int i=0; i < P; i++){
			for (int j=0; j < M; j++){
				jogadores[i].push_back (saque[saque.size()-1]);
				saque.pop_back();
			}
		}
		
		//Tira a primeira carta da pilha de saque
		CARTA carta_atual = saque[saque.size()-1];
		saque.pop_back();
		
		//Jogo começa em sentido horário com o primeiro jogador sendo 0
		int sentido = HORARIO;
		int jogador_atual = 0;
		
		//Verifica se o jogador do primeiro turno será bloqueado
		bool bloqueado = (carta_atual.valor == 7 or carta_atual.valor == 1 or carta_atual.valor == 11);

		//Dama inverte sentido
		if (carta_atual.valor == 12)
			sentido = inverteSentido(sentido);

		while(true){
			//Um turno inteiro acontece nesse while
			
			/*
			cout << "Turno do jogador "<< jogador_atual << ", carta atual: ";
			cout << carta_atual.valor << carta_atual.naipe <<'\n';
			
			cout << "Pilha de saque: ";
			veMaoDoJogador(saque);
			
			for (int l=0; l< P; l++){
				cout << "Mão do jogador: " << l << ": ";
				veMaoDoJogador(jogadores[l]);
			}
			
			*/
			
			//Se jogador terá seu turno bloqueado:
			if (bloqueado){
				//cout << "Foi bloqueado!\n";
				
				//Próximo jogador não será bloqueado
				bloqueado = false;
				
				//Todas as cartas que pedem pra comprar mais bloqueiam também
				if (carta_atual.valor == 7){ // Carta 7 pede pra comprar 2 cartas
					jogadorCompraCarta (jogadores[jogador_atual], saque);
					jogadorCompraCarta (jogadores[jogador_atual], saque);
				}else if (carta_atual.valor == 1) // Carta 1 pede pra comprar 1 carta
					jogadorCompraCarta (jogadores[jogador_atual], saque);
				
				jogador_atual = novoJogadorAtual(jogador_atual, P, sentido);
				
				//Avança o turno
				continue;
			}
			
			//Se jogador não pode descartar, compra uma carta
			if(!jogadorPodeDescartar(jogadores[jogador_atual], carta_atual)){
				
				//cout << "Não tem carta para descartar!\n";
				jogadorCompraCarta (jogadores[jogador_atual], saque);
				
				
				//Se o jogador ainda não pode descartar, passa a vez
				if(!jogadorPodeDescartar(jogadores[jogador_atual], carta_atual)){
					//cout << "Ainda não tem carta, pula a vez\n";
					//Avança para o próximo jogador
					jogador_atual = novoJogadorAtual(jogador_atual, P, sentido);
					continue;
				}
			}
			
			//Jogador descarta a maior carta da mão, que vira a nova carta_atual
			descartaCarta (jogadores[jogador_atual], carta_atual);
			
			//Se jogador tiver descartado sua última carta, ganha e o jogo acaba
			if (jogadores[jogador_atual].empty()){
				//cout << "Fim de jogo\n";
				break;
			}
			//Preparando para o próximo turno, ativamos os efeitos da nova carta:
			
			//Verifica se próximo jogador será bloqueado
			bloqueado = (carta_atual.valor == 7 or carta_atual.valor == 1 or carta_atual.valor == 11);
			
			//Dama inverte sentido
			if (carta_atual.valor == 12)
				sentido = inverteSentido(sentido);
			
			//Avança para o próximo jogador
			jogador_atual = novoJogadorAtual(jogador_atual, P, sentido);
		}
		
		cout << jogador_atual+1 << '\n';
		
	}
	return 0;
}
