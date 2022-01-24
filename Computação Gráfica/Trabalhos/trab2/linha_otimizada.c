//Trabalho 2 de Computação Gráfica 2020/01
//Feito em 01/10/2020
//Para compilar, use os seguintes modificadores: -lglut -lGL -lGLU -lm

#include <GL/glut.h>
#include <stdio.h>

//Defines para facilitar a escrita e seleção de cores
#define DESENHA_COM_COR_VERMELHA glColor3f (1.0, 0.0, 0.0);
#define DESENHA_COM_COR_VERDE glColor3f (0.0, 1.0, 0.0);
#define DESENHA_COM_COR_AZUL glColor3f (0.0, 0.0, 1.0);
#define DESENHA_COM_COR_PRETA glColor3f (0.0, 0.0, 0.0);
#define DESENHA_COM_COR_BRANCA glColor3f (1.0, 1.0, 1.0);
#define DESENHA_COM_COR_AMARELA glColor3f (1.0, 1.0, 0.0);

/*
	Pinta retas entre 2 pontos (x1, y1) e (x2, y2)
	Usam mesmas coordenadas da Ortho2D
	Restrições:
		x1 < x2 e y1 < y2
		A reta deve ter inclinação entre 0 e 45 graus
*/
void linha1octante (int x1, int y1, int x2, int y2){
	int dx, dy, deltaE, deltaNE, d, x, y;
	
	//printf ("Reta de (%d, %d) até (%d, %d)\n", x1, y1, x2, y2);
	
	dx = x2-x1;
	dy = y2-y1;
	d = 2*dy - dx; //2F(x,y) do ponto inicial
	deltaE = 2*dy; //2F(x+2,y+1/2) - 2F(x+1, y+1/2) = diferença de d quando escolhe E
	deltaNE = 2*(dy - dx); //2F(x+2,y+3/2) - 2F(x+1, y+1/2) = diferença de d quando escolhe NE
	x = x1; //O primeiro ponto a ser pintado é o (x1, y1)
	y = y1; //O primeiro ponto a ser pintado é o (x1, y1)
	
	glBegin(GL_POINTS);
	
	do{
		//printf("PINTANDO (%d, %d)\n", x, y);
		glVertex2i(x,y); //Pinta o pixel
		
		if (d > 0){ //Escolhe NE
			d += deltaNE; //d sofre a alteração de NE pra continuar atualizado
			y++; //Ao escolher NE, subimos em 1 pixel 
		}else //Escolhe E
			d += deltaE; //d sofre a alteração de E pra continuar atualizado
		x++; //Andamos 1 pixel pra direita
	} while(x < x2);
	
	glEnd();
	
	return;
}

//Função que desenha na tela
void desenha(){
	//Limpa a tela com a cor preta
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Desenha a linha vermelha
	DESENHA_COM_COR_VERMELHA
	linha1octante(-200, -200, 200, 100);
	
	glFlush();
}

//Inicializa parâmentros antes de começar a desenhar
void inicializa(){
	//Limpa a tela com cor preta
	glClearColor(0,0,0,0);
	//Pontos exibidos devem estar dentro desse intervalo:
	gluOrtho2D(-400.0, 400.0, -400.0, 400.0); 
}

//Função chamada quando alguma tecla é pressionada
void keyboard(unsigned char key, int x, int y){
	switch (key) {
		case 27: // tecla ESC (encerra o programa)
		exit(0);
		break;
	}
}

int main(int argc, char ** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(10,50);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Trabalho 2");
	inicializa();
	glutDisplayFunc(desenha);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
