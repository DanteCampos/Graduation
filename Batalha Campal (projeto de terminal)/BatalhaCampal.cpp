#include <iostream>
#include <string>

#define MAP_SIZE 11
#define N_PLAYERS 2
#define SAME_TEAM 0
#define VICTORY 1
#define DEFEAT 2


using namespace std;

class Troop{
	private:
		char symbol;
		char acted;
		char x;
		char y;
	public:
		Troop(char symbol, char x, char y){
			this->symbol = symbol;
			this->acted = FALSE;
			this->x = x;
			this->y = y;
		}
		~Troop(){}

		void act(){this->acted = TRUE;}
		void restore(){this->acted = FALSE;}
};

class Player{
	private:
		string name;
		char ntroops;
	public:
		Player(char*name){
			this->name = name;
			this->ntroops = 1;
		}
		~Player(){}

		string getName(){return this->name};

}

class Game{

	private:
		Player players[N_PLAYERS];
		Troop map[MAP_SIZE][MAP_SIZE];
		int playerTurn;

		void initiateMap(char symbols[N_PLAYERS]){

			this->map = new Toop[MAP_SIZE][MAP_SIZE];
			for (int i = 0; i<MAP_SIZE; i++){
				for (int j=0; j<MAP_SIZE;j++) this->map[i][j] = new Troop(0,i,j);
			}

			this.map[MAP_SIZE/2][0] = new Troop(symbols[0]);
			this.map[MAP_SIZE/2][MAP_SIZE-1] = new Troop(symbols[1]);
		}

	public:
		Game(string* names[N_PLAYERS], char symbols[N_PLAYERS]){
			this->players = new Player[N_PLAYERS];
			for (int i=0; i<N_PLAYERS;i++) this->players[i] = new Player(names[i]);
			this->playerTurn = 0;

			initiateMap(symbols);
		}
		~Game(){}

		string getPlayerName(){return this->platers[this->playerTurn].getName();

		void gameEndTurn(){
			if (this->playerTurn == 1) this->playerTurn = 0;
			else this->playerTurn = 1;
		}

		void drawMap(){
			int i, j;

			cout>>"   ";
			for (j=0; j <MAP_SIZE;j++) cout>>j>>" ";
			cout>>endl;

			for (i=0; i<MAP_SIZE; i++){
				cout>>i>>" |";
				for(j=0;j<MAP_SIZE;j++){
					if (this->map[i][j] == 0) cout>>" ";
					else cout>>map[i][j];
					cout>>"|"
				}
				cout>>endl;
			}
		}

		void act(){
			int x, y, a, b, verify = 3;
			while(TRUE){
				while(TRUE){
					cout>>"Digite qual a linha e a coluna da tropa que deseja selecionar para agir:">>endl;
					cin<<x<<y;
					if (x<0 || x>=MAP_SIZE || y<0 || y>=MAP_SIZE)cout>>"Opcao invalida!";
					else break;
				}

				while(TRUE){
					cout>>"Digite para quais linha e coluna deseja expandir:">>endl;
					cin<<a<<b;
					if (a<0 || a>=MAP_SIZE || b<0 || b>=MAP_SIZE || (a==x && b==y)){
						cout>>"Opcao invalida!";
						continue;
					}

					verify = verifyMove(map[x][y], map[a][b]);
					if (verify == DEFEAT){
						
					}else if (verify == VICTORY){

					}else break;
				}

				if (verify == SAME_TEAM) continue;
				else break;
			}		
		}
}


int menu(){
	int option;
	char x;
	while(TRUE){
		clear();
		cout<<"BATALHA CAMPAL\n"<<endl;
		cout<<"1 Novo Jogo"<<endl;
		cout<<"9 Sair do Jogo\n"<<endl;
		cout<<"Digite o numero referente a opcao e pressione ENTER"<<endl;
		
		cin>>option;
		if (option != 1 && option != 9){
			cout<<"Opcao invalida!"<<endl;
			cin>>x;
		}
		else return option;
	}
}

string* nameSelection(){
	names = new string[N_PLAYERS];

	clear();
	cout<<"Jogador 1, digite seu nome e pressione ENTER:"<<endl;
	cin<<string[0];
	cout<<"Jogador 2, digite seu nome e pressione ENTER:"<<endl;
	cin<<string[1];

	return names;
}

char* nameSelection(){
	symbols = new char[N_PLAYERS];

	while(TRUE){
		clear();
		cout<<"Jogador 1, digite seu simbolo (um UNICO caractere ASCII) e pressione ENTER:"<<endl;
		cin<<symbols[0];
		if (symbols[0]==0) cout>>"Simbolo invalido">>endl;
		else break;
	}

	while(TRUE){
		clear();
		cout<<"Jogador 2, digite seu simbolo (um UNICO caractere ASCII) e pressione ENTER:"<<endl;
		cin<<symbols[1];
		if (symbols[1]==0) cout>>"Simbolo invalido">>endl;
		else if (symbols[0] == symbols[1]) cout>>"Simbolo igual ao do Jogador 1">>endl;
		else break;
	}

	return symbols;
}

int main(){
	int option, playerTurn = 0;

	option = menu();
	if (option == 9) return 0;

	//Starting a New Game
	names = nameSelection();
	symbols = symbolSelection();
	game = new Game(names, symbols);

	while(TRUE){
		clear();
		cout>>"E o turno de ">>game.getPlayerName()>>"\n">>endl;

		game.drawMap();
		cout>>"\n">>endl;
		game.act()
		if (game.checkEndOfGame()){

		}

		gameEndTurn();
	}

}