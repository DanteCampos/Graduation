//Seminário 1 de Computação Gráfica 2020/01
//Feito em 08/09/2020
//Para compilar, use os seguintes modificadores: -lglut -lGL -lGLU -lm

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

//Defines para facilitar a escrita e seleção de cores
#define DESENHA_COM_COR_VERMELHA glColor3f (1.0, 0.0, 0.0);
#define DESENHA_COM_COR_VERDE glColor3f (0.0, 1.0, 0.0);
#define DESENHA_COM_COR_AZUL glColor3f (0.0, 0.0, 1.0);
#define DESENHA_COM_COR_PRETA glColor3f (0.0, 0.0, 0.0);
#define DESENHA_COM_COR_BRANCA glColor3f (1.0, 1.0, 1.0);
#define DESENHA_COM_COR_AMARELA glColor3f (1.0, 1.0, 0.0);

int N_PASSOS = 20;
int op = 1;
//Todo ponto tem suas coordenadas (x,y) e um ponteiro para o próximo ponto da curva
typedef struct estruturaPonto {
	GLfloat x;
	GLfloat y;
	struct estruturaPonto *prox;
} PONTO;

//Toda curva tem um número de pontos e uma lista dos pontos que a compõem
typedef struct estruturaCurva{
	GLuint n_pontos;
	PONTO *pontos;
} CURVA;

//Cria uma curva vazia (sem pontos)
CURVA* criaCurva(){
	CURVA* curva = malloc (sizeof(CURVA));
	curva->n_pontos = 0;
	curva->pontos = NULL;
	
	return curva;
}

//Cria um ponto com as coordenadas (x,y)
PONTO* criaPonto (GLfloat x, GLfloat y){
	PONTO* novoPonto = malloc (sizeof(PONTO));
	novoPonto->x = x;
	novoPonto->y = y;
	novoPonto->prox = NULL;
	
	return novoPonto;
}

//Soma 2 pontos e retorna o ponto resultante
PONTO soma2Pontos(PONTO p1, PONTO p2){
	p1.x += p2.x;
	p1.y += p2.y;
	
	return p1;
}

//Multiplica um ponto por uma constante
PONTO multiplicaPonto (PONTO p, GLfloat constante){
	p.x *= constante;
	p.y *= constante;
	
	return p;
}

//Adiciona um ponto de coordenadas (x,y) numa curva
void adicionaPonto (CURVA* curva, GLfloat x, GLfloat y){
	PONTO *novoPonto = criaPonto (x, y);
	
	//Adiciona no começo da lista de pontos
	novoPonto->prox = curva->pontos;
	curva->pontos = novoPonto;
	
	//Aumenta o número de pontos da curva em 1
	curva->n_pontos++;
	
	return;
}

//Deleta a lista de pontos de uma curva
void deletaPontos (PONTO* ponto){
	PONTO* proximoPonto = ponto->prox;
	
	while(proximoPonto != NULL){
		free(ponto);
		ponto = proximoPonto;
		proximoPonto = proximoPonto->prox;
	}
	
	free(ponto);
	
	return;
}

//Deleta uma curva
void deletaCurva (CURVA* curva){
	if (curva->pontos != NULL)
		deletaPontos(curva->pontos);
	
	free(curva);
	
	return;
}

//Apenas desenha a curva pelos seus pontos
void desenhaCurva (CURVA* curva){
	PONTO* pontoAtual = curva->pontos;
	
	//Vai conectando os vértices adjacentes com retas
	glBegin(GL_LINE_STRIP);
	
	while (pontoAtual != NULL){
		glVertex2f (pontoAtual->x, pontoAtual->y);
		pontoAtual = pontoAtual->prox;
	}
	
	glEnd();
	
	return;
}

//Retorna o ponto de uma curva de bezier de acordo com um t entre 0 e 1
PONTO bezierRecursiva(PONTO* ponto, GLfloat t, GLint nivel){
	PONTO resultado;
	if (nivel == 0)
		return (*ponto);
	else
		//Como a lista está invertida, retornamos P0*t + P1*(1-t) em vez de P0*(1-t) + P1*t
		return soma2Pontos(
			multiplicaPonto(bezierRecursiva(ponto, t, nivel-1), t),
			multiplicaPonto(bezierRecursiva(ponto->prox, t, nivel-1), 1.0-t)
		);
}

//Retorna o ponto de uma curva de bezier de acordo com um t entre 0 e 1
PONTO bezierCubica(PONTO* ponto, GLfloat t){
	PONTO P1, P2, P3, P4;
	P1 = *ponto;
	P2 = *(P1.prox);
	P3 = *(P2.prox);
	P4 = *(P3.prox);
	
	/*Retorna P4*t*t*t + P3*3*t*t*(1-t) + P2*3*t*(1-t)*(1-t) + P1*(1-t)*(1-t)*(1-t)

	em vez de P1*(1-t)*(1-t)*(1-t) + P2*3*t*(1-t)*(1-t) + P3*3*t*t*(1-t) + P1*t*t*t
	porque a lista de pontos está invertida*/
	return soma2Pontos (
		multiplicaPonto(P1, t*t*t),
		soma2Pontos(
			multiplicaPonto(P2, 3*t*t*(1-t)),
			soma2Pontos(
				multiplicaPonto(P3, 3*t*(1-t)*(1-t)),
				multiplicaPonto(P4, (1-t)*(1-t)*(1-t))
			)
		)
	);
}

//Retorna o ponto de uma curva de bezier de acordo com um t entre 0 e 1
PONTO bezierQuadratica(PONTO* ponto, GLfloat t){
	PONTO P1, P2, P3;
	P1 = *ponto;
	P2 = *(P1.prox);
	P3 = *(P2.prox);
	
	
	/*Retorna P3*t*t + P2*2*t*(1-t) + P1*(1-t)*(1-t)

	em vez de P1*(1-t)*(1-t) + P2*2*t*(1-t) + P3*t*t
	porque a lista de pontos está invertida*/
	return soma2Pontos(  
		multiplicaPonto(P1, t*t),
		soma2Pontos(
			multiplicaPonto(P2, 2*t*(1-t)),
			multiplicaPonto(P3, (1-t)*(1-t))
		)
	);
}

//Cria uma curva de bezier dada uma curva (conjunto de pontos) e um número de passos >= 2
CURVA* criaBezier (CURVA* curva, GLint passos){
	PONTO ponto;
	CURVA* bezier = criaCurva();
	GLfloat t=0, dt = 1.0/(passos-1.0);
	
	if (passos < 2 || curva->n_pontos < 2)
		return bezier;
	
	while(passos--){
		//Temos fórmulas diretas para as quadráticas e cúbicas de bezier
		if (curva->n_pontos == 3)
			ponto = bezierQuadratica (curva->pontos, t);
			
		else if (curva->n_pontos == 4)
			ponto = bezierCubica (curva->pontos, t);
			
		else
			ponto = bezierRecursiva (curva->pontos, t, curva->n_pontos-1);
		
		t += dt;
		if (t>1)
			t=1;
			
		adicionaPonto (bezier , ponto.x, ponto.y);
	}
		
	return bezier;
}


// Seleciona a quantidade de pontos que deseja mostrar
void opcoes_de_curva(CURVA* curva, int curva_selecioanda){

	switch (curva_selecioanda){
	
	case 2: // Cria uma Bezier linear
		adicionaPonto (curva, -2, 2);
		adicionaPonto (curva, 2, -2);

		break;

	case 3: // Cria uma Bezier quadradica 
	
		adicionaPonto (curva, -5, 1);
		adicionaPonto (curva, 0, -5);
		adicionaPonto (curva, 5, 1);

		break;

	case 4: // cria uma Bezier cubica
	
		adicionaPonto (curva, -8, 0);
		adicionaPonto (curva, -5, -5);
		adicionaPonto (curva, 5, 5);
		adicionaPonto (curva, +8, 0);
		break;
	

	case 5: // cria uma Bezier de grau 4
	
		adicionaPonto (curva, -8, 0);
		adicionaPonto (curva, -5, -5);
		adicionaPonto (curva, 5, 5);
		adicionaPonto (curva, +8, 0);
		adicionaPonto (curva, +8, -5);
		break;
	
	default:
		// cria uma Bezier recursiva
		adicionaPonto (curva, -8, 0);
		adicionaPonto (curva, -5, -5);
		adicionaPonto (curva, 5, 5);
		adicionaPonto (curva, +8, 0);
		adicionaPonto (curva, +8, 2);
		adicionaPonto (curva, -2, -4);
		adicionaPonto (curva, +9, -3);
		adicionaPonto (curva, -6, -1);
		adicionaPonto (curva, +1, 0);
		adicionaPonto (curva, -0, 7);
		adicionaPonto (curva, +7, 3);
		adicionaPonto (curva, 9, 6);

		
		break;
	
	}

}

//Função que desenha na tela
void desenha(){
	CURVA* curva = criaCurva();
	CURVA* bezier;
	GLint i;
	
	//Limpa a tela com a cor preta
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Traçando as linhas das coordenadas
	DESENHA_COM_COR_BRANCA
	glBegin (GL_LINES);
	glVertex2f (-10.0,0.0);
	glVertex2f (+10.0,0.0);
	glVertex2f (0.0,-10.0);
	glVertex2f (0.0,+10.0);
	glEnd();
	
	//Colocando pontos de medida nas coordenadas
	DESENHA_COM_COR_VERMELHA
	glPointSize(3);
	glBegin (GL_POINTS);
	for (i=-10; i<=10; i++){
		glVertex2f (i, 0);
		glVertex2f (0, i);
	}
	glEnd();
	
	opcoes_de_curva(curva,op);

	bezier = criaBezier (curva, N_PASSOS);
		
	DESENHA_COM_COR_AMARELA
	desenhaCurva (bezier);
		
	deletaCurva (curva);
	deletaCurva (bezier);



	glFlush();
}



//Inicializa parâmentros antes de começar a desenhar
void inicializa(){
	//Limpa a tela com cor preta
	glClearColor(0,0,0,0);
	//Só mostra o que estiver entre as coordenadas -10.0 e 10.0, tanto no eixo x, quanto no eixo y
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D(-10.0,10.0,-10.0,10.0);
}

//Função chamada quando alguma tecla é pressionada
void keyboard(unsigned char key, int x, int y){
	switch (key) {
		case 27: // tecla ESC (encerra o programa)
		exit(0);
		break;
		
		case 'w':
			N_PASSOS++;
			break;
			
		case 's':
			if (N_PASSOS > 2)
				N_PASSOS--;
			break;
		
		case 'a':
			op = (op+1)%6;
			break;
			
		case 'd':
			op = (op-1)%6;
			break;
	}
	
	desenha();
}

int main(int argc, char ** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(50,50);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Seminario 1 - Curvas de Bezier");
	inicializa();
	glutDisplayFunc(desenha);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
