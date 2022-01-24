#include <stdio.h>

//CONSTANTS

#define TRUE (1==1)
#define FALSE (!TRUE)

#define NAME_LENGTH 50
#define MAP_SIZE 7

#define PLAYER1_WINS 20
#define PLAYER2_WINS 21
#define NOT_FINISHED 22
#define DRAW 23

#define ATTACK 3
#define EXPAND 4

#define BATTLEDRAW 6
#define BATTLEATTACK 7
#define BATTLEDEFENSE 8

#define OUT_OF_MAP 15
#define EMPTY_SPACE 16
#define WRONG_TROOP 17
#define OUT_OF_RANGE 18

//STRUCTURES

typedef struct{
	int x;
	int y;
	char symbol;
}Troop;

typedef struct{
	char name[NAME_LENGTH];
	int n_troops;
	int moves;
	char symbol;
}Player;

//FUNCTIONS

void clear();
void initiatePlayer(Player *p);
void readPlayerName(char* name, int player);
void newGame(Troop map[MAP_SIZE][MAP_SIZE], char* name1, char* name2, int *playerTurn, Player *player1, Player *player2);
void initiateMap(Troop map[MAP_SIZE][MAP_SIZE], char symbol1, char symbol2);
void endGame(Player player1, Player player2, int gameState);
int verifyVictory(Troop map[MAP_SIZE][MAP_SIZE], Player player1, Player player2);
void drawMap(Troop map[MAP_SIZE][MAP_SIZE]);
int validateSelectedTroop(Troop map[MAP_SIZE][MAP_SIZE], int xSelected, int ySelected, Player attacker);
int validateMove(Troop map[MAP_SIZE][MAP_SIZE], Troop troop, int xMove, int yMove, Player defender);
int sameTeamAround(Troop map[MAP_SIZE][MAP_SIZE], Troop troop);
int checksBattle(Troop map[MAP_SIZE][MAP_SIZE], Troop attacker, Troop defender);
void invalidOptionMessage(int option);
void drawScene(Troop map[MAP_SIZE][MAP_SIZE], Player player1, Player player2, Player attacker);
void battleStage(Troop map[MAP_SIZE][MAP_SIZE], int xSelected, int ySelected, int xMove, int yMove, Player *attacker, Player *defender);
void expandTroops(Troop map[MAP_SIZE][MAP_SIZE], int xMove, int yMove, Player *attacker);
void playTurn(Troop map[MAP_SIZE][MAP_SIZE], Player *player1, Player *player2, int playerTurn);
void changeTurn (Player *player1, Player *player2, int *playerturn);

//IMPLEMENTATIONS

void clear(){
	int i;
	for(i=0;i<50;i++) printf("\n");
}

void initiatePlayer(Player *p){
	p->name[0]='\0';
	p->n_troops=1;
	p->moves = 0;
	p->symbol = 0;
}

void readPlayerName(char* name, int player){
	int i;
	char aux_name[NAME_LENGTH];

	clear();
	printf("Jogador %d, digite seu nome:\n",player);
	scanf ("%[^\n]%*c",aux_name);
	for (i=0; i < NAME_LENGTH;i++){
		name[i] = aux_name[i];
		if (aux_name[i]=='\0') break;
	}
	if (i>(NAME_LENGTH-1)) i = NAME_LENGTH-1;
	name[i]='\0';
}

//Sets the players's names and symbols and choose who'll be the first to play
void newGame(Troop map[MAP_SIZE][MAP_SIZE], char* name1, char* name2, int *playerTurn, Player *player1, Player *player2){

	char symbol1, symbol2;

	initiatePlayer(player1);
	initiatePlayer(player2);

	//Player1 is the first to play
	*playerTurn = 1;
	player1->moves++;

	//Reading the names
	readPlayerName(player1->name, 1);
	readPlayerName(player2->name, 2);

	//Reading the symbol of the player1
	while(TRUE){
		clear();
		printf("%s, digite seu símbolo:\n", player1->name);
		scanf("%c%*c",&symbol1);
		if (symbol1 == 0){
			printf("Símbolo inválido!\n");
			getchar();
			continue;
		}else break;
	}

	//Reading the symbol of the player2
	while(TRUE){
		clear();
		printf("%s, digite seu símbolo:\n", player2->name);
		scanf("%c%*c",&symbol2);
		if (symbol2 == 0){
			printf("Símbolo inválido!\n");
			getchar();
			continue;
		}else if (symbol2 == symbol1){
			printf("Símbolo igual ao do outro jogador!\n");
			getchar();
			continue;
		}else break;
	}

	player1->symbol = symbol1;
	player2->symbol = symbol2;
	initiateMap(map, symbol1, symbol2);
}

void initiateMap(Troop map[MAP_SIZE][MAP_SIZE], char symbol1, char symbol2){
	int i,j;
	for (i=0;i<MAP_SIZE; i++){
		for (j=0;j<MAP_SIZE; j++){
			map[i][j].x = i;
			map[i][j].y = j;
			map[i][j].symbol = 0;
		}
	}

	//Player1's first troop
	map[MAP_SIZE/2][0].symbol = symbol1;
	//Player2's first troop
	map[MAP_SIZE/2][MAP_SIZE-1].symbol = symbol2;
}

void endGame(Player player1, Player player2, int gameState){
	clear();

	//Case player1 wins
	if (gameState==PLAYER1_WINS) printf("PARABÉNS %s! Você venceu o jogo com %d tropas!\n\n", player1.name, player1.n_troops);
	//Case player2 wins
	else if (gameState==PLAYER2_WINS) printf("PARABÉNS %s! Você venceu o jogo com %d tropas!\n\n", player2.name, player2.n_troops);
	//Case of draw
	else if (gameState==DRAW) printf("JOGO EMPATADO! Tentem de novo no próximo jogo!\n\n");
	//Case of error
	else printf("ERRO NO FIM DO JOGO\n\n");

	getchar();
}

int verifyVictory(Troop map[MAP_SIZE][MAP_SIZE], Player player1, Player player2){
	//Game end condition: map is completely full of troops
	//Win condition: the player who have more troops in the end is the winner

	int i, j;
	for (i=0; i< MAP_SIZE; i++){
		for (j=0; j< MAP_SIZE; j++) if (map[i][j].symbol == 0) break;
	}
	
	if (i==MAP_SIZE && j==MAP_SIZE){
		if (player1.n_troops == player2.n_troops) return DRAW;
		else if (player1.n_troops > player2.n_troops) return PLAYER1_WINS;
		else return PLAYER2_WINS;
	}else return NOT_FINISHED;
}

void drawMap(Troop map[MAP_SIZE][MAP_SIZE]){
	int i, j;

	printf("   ");
	for(j=0;j<MAP_SIZE; j++) printf(" %d",j);
	printf("\n");
	for (i=0;i<MAP_SIZE; i++){
		if (i<10) printf(" ");
		printf ("%d |", i);
		for (j=0;j<MAP_SIZE;j++)
			if (map[i][j].symbol != 0) printf("%c|",map[i][j].symbol);
			else printf(" |");
		printf("\n");
	}
}

int validateSelectedTroop(Troop map[MAP_SIZE][MAP_SIZE], int xSelected, int ySelected, Player attacker){
	//Out of the map
	if (xSelected <0 || ySelected< 0 || xSelected>=MAP_SIZE || ySelected >= MAP_SIZE) return OUT_OF_MAP;
	//Attacker selects it's own troop
	else if (map[xSelected][ySelected].symbol == attacker.symbol) return TRUE;
	else if (map[xSelected][ySelected].symbol == 0) return EMPTY_SPACE;
	else return WRONG_TROOP;
}

int validateMove(Troop map[MAP_SIZE][MAP_SIZE], Troop troop, int xMove, int yMove, Player defender){
	//Out of the map
	if (xMove <0 || yMove< 0 || xMove>=MAP_SIZE || yMove >= MAP_SIZE) return OUT_OF_MAP;
	//Out of troop's range
	if (xMove < troop.x-1 || xMove > troop.x+1 || yMove < troop.y-1 || yMove > troop.y+1) return OUT_OF_RANGE;
	//Attacker will attack
	else if (map[xMove][yMove].symbol == defender.symbol) return ATTACK;
	//Attacker will expand to an empty space
	else if (map[xMove][yMove].symbol == 0) return EXPAND;
	else return WRONG_TROOP;
}

int sameTeamAround(Troop map[MAP_SIZE][MAP_SIZE], Troop troop){
	int i,j, count=0;

	//In the x range of the troop
	for (i = troop.x-1; i <= troop.x+1;i++){
		//Out of map
		if (i<0 || i>= MAP_SIZE) continue;
		//In the y range of the troop
		for(j = troop.y-1; j <= troop.y+1;j++){
			//Out of map
			if (j<0 || j>= MAP_SIZE) continue;
			//Found a troop of the same team
			else if (troop.symbol == map[i][j].symbol) count++;
		}
	}

	return count;
}

int checksBattle(Troop map[MAP_SIZE][MAP_SIZE], Troop attacker, Troop defender){
	int attackPower, defensePower;

	attackPower = sameTeamAround(map, attacker);
	defensePower = sameTeamAround(map, defender);

	if (attackPower == defensePower) return BATTLEDRAW;
	else if (attackPower > defensePower) return BATTLEATTACK;
	else return BATTLEDEFENSE;
}

void invalidOptionMessage(int option){
	printf ("Opção inválida!\n");
	if (option == OUT_OF_MAP) printf("Essa localização está fora do mapa!\n");
	else if (option==EMPTY_SPACE) printf("Essa localização está vazia!\n");
	else if (option == WRONG_TROOP) printf("Tropa incorreta!\n");
	else printf ("Esta localização está fora do alcance da sua tropa!\n");
	getchar();
}

void drawScene(Troop map[MAP_SIZE][MAP_SIZE], Player player1, Player player2, Player attacker){
	clear();
	printf ("É a vez de %s jogar\n\n",attacker.name);
	drawMap(map);
	printf("\n\nTropas de %s: %d %c",player1.name, player1.n_troops, player1.symbol);
	printf("\nTropas de %s: %d %c",player2.name,player2.n_troops, player2.symbol);
}

void battleStage(Troop map[MAP_SIZE][MAP_SIZE], int xSelected, int ySelected, int xMove, int yMove, Player *attacker, Player *defender){
	int battle;

	battle = checksBattle(map, map[xSelected][ySelected], map[xMove][yMove]);
	
	printf("Tropa %dx%d de %s ataca a tropa %dx%d de %s!\n",xSelected,ySelected,attacker->name, xMove,yMove,defender->name);
	getchar();
	getchar();

	//Draws the battle
	if (battle == BATTLEDRAW){
		//Attacker is eliminated
		map[xSelected][ySelected].symbol = 0;
		attacker->n_troops--;
		printf ("A batalha termina em empate, a tropa atacante de %s é eliminada.\n",attacker->name);

	//Attacker wins the battle
	}else if (battle == BATTLEATTACK){
		//Defender is eliminated
		map[xMove][yMove].symbol = 0;
		defender->n_troops--;
		//Attacker gets one more move
		attacker->moves++;
		printf ("%s vence a batalha e elimina uma das tropas de %s.\n%s ganhou mais um movimento.\n", attacker->name, defender->name, attacker->name);

	//Defender wins the battle
	}else{
		//Attacker is eliminated
		map[xSelected][ySelected].symbol = 0;
		attacker->n_troops--;
		//Defender gets one more move
		defender->moves++;
		printf("%s perde a batalha e sua tropa é eliminada por %s.\n%s ganhou um movimento extra.\n", attacker->name, defender->name, defender->name);
	}
	getchar();
}

void expandTroops(Troop map[MAP_SIZE][MAP_SIZE], int xMove, int yMove, Player *attacker){
	map[xMove][yMove].symbol = attacker->symbol;
	attacker->n_troops++;
	printf ("%s expande sua tropa para %dx%d.\n",attacker->name, xMove,yMove);
	getchar();
}

void playTurn(Troop map[MAP_SIZE][MAP_SIZE], Player *player1, Player *player2, int playerTurn){
	int xSelected, ySelected, xMove, yMove, battle, option;
	Player *attacker, *defender;

	if (playerTurn == 1){
		attacker = player1;
		defender = player2;
	}else{
		attacker = player2;
		defender = player1;
	}

	while(attacker->moves > 0){
		//Draw map and number of troops

		drawScene(map, *player1, *player2, *attacker);

		//Player selects the troop to act
		printf("\n\nDigite a linha e a coluna da tropa que deseja usar:\n");
		scanf("%d %d", &xSelected, &ySelected);

		option = validateSelectedTroop(map, xSelected, ySelected, *attacker);
		if(option != TRUE){
			invalidOptionMessage(option);
			continue;
		}

		//Here we already assumed that the selected troop is valid

		printf("Digite a linha e a coluna do movimento que quer que sua tropa faça:\n");
		scanf("%d %d",&xMove, &yMove);

		option = validateMove(map, map[xSelected][ySelected], xMove, yMove, *defender);
		if (option != EXPAND && option != ATTACK){
			invalidOptionMessage(option);
			continue;
		}
		//Here we alredy assumed that the movement is valid
		attacker->moves--;

		//Attacker will expand the selected troop to an empty space
		if (option == EXPAND) expandTroops(map, xMove, yMove, attacker);

		//Attacker will attack the defender
		else battleStage(map, xSelected, ySelected, xMove, yMove, attacker, defender);
	}
}

//Changes the player who will play the next turn
void changeTurn (Player *player1, Player *player2, int *playerTurn){
	if (*playerTurn==1){
		player2->moves++;
		*playerTurn = 2;
	}else{
		player1->moves++;
		*playerTurn = 1;
	}
}

//MAIN

int main(){
	Player player1, player2;
	char name1[NAME_LENGTH], name2[NAME_LENGTH];
	char symbol1, symbol2;
	Troop map[MAP_SIZE][MAP_SIZE];
	int playerTurn, gameState;

	newGame(map, name1, name2, &playerTurn,&player1, &player2);
	
	while(TRUE){
		playTurn(map, &player1, &player2, playerTurn);
		gameState = verifyVictory(map, player1, player2);
		
		//Finish the game
		if (gameState != NOT_FINISHED){
			endGame(player1, player2, gameState);
			return 0;

		//Continue the game
		}else changeTurn (&player1, &player2, &playerTurn);
	}
}