//Trabalho 1 de Computação Gráfica 2020/01
//Feito em 08/09/2020
//Para compilar, use os seguintes modificadores: -lglut -lGL -lGLU -lm

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Defines para facilitar a escrita e seleção de cores
#define DESENHA_COM_COR_VERMELHA glColor3f (1.0, 0.0, 0.0);
#define DESENHA_COM_COR_VERDE glColor3f (0.0, 1.0, 0.0);
#define DESENHA_COM_COR_AZUL glColor3f (0.0, 0.0, 1.0);
#define DESENHA_COM_COR_PRETA glColor3f (0.0, 0.0, 0.0);
#define DESENHA_COM_COR_BRANCA glColor3f (1.0, 1.0, 1.0);
#define DESENHA_COM_COR_AMARELA glColor3f (1.0, 1.0, 0.0);

//Todo vértice tem suas coordenadas (x,y) e um ponteiro para o próximo vértice do polígono
typedef struct estruturaVertice {
	GLfloat x;
	GLfloat y;
	struct estruturaVertice *prox;
} VERTICE;

//Todo polígono tem um número de vértices e uma lista dos vértices que o compõem
typedef struct estruturaPoligono{
	GLuint n_vertices;
	VERTICE *vertices;
} POLIGONO;

//Cria um polígono vazio (sem vértices)
POLIGONO* criaPoligono(){
	POLIGONO* figura = malloc (sizeof(POLIGONO));
	figura->n_vertices = 0;
	figura->vertices = NULL;
	
	return figura;
}

//Cria um vértice com as coordenadas (x,y)
VERTICE* criaVertice (GLfloat x, GLfloat y){
	VERTICE* novoVertice = malloc (sizeof(VERTICE));
	novoVertice->x = x;
	novoVertice->y = y;
	novoVertice->prox = NULL;
	
	return novoVertice;
}

//Adiciona um vértice de coordenadas (x, y) num polígono
void adicionaVertice (POLIGONO* figura, GLfloat x, GLfloat y){
	VERTICE *novoVertice = criaVertice (x, y);
	
	//Adiciona no começo da lista de vértices
	novoVertice->prox = figura->vertices;
	figura->vertices = novoVertice;
	
	//Aumenta o número de vértices do polígono em 1
	figura->n_vertices++;
	
	return;
}

//Deleta a lista de vértices de um polígono
void deletaVertices (VERTICE* vertice){
	VERTICE* proximoVertice = vertice->prox;
	
	while(proximoVertice != NULL){
		free(vertice);
		vertice = proximoVertice;
		proximoVertice = proximoVertice->prox;
	}
	
	free(vertice);
	
	return;
}

//Deleta um polígono
void deletaPoligono (POLIGONO* figura){
	if (figura->vertices != NULL)
		deletaVertices(figura->vertices);
	
	free(figura);
	
	return;
}

//Translada vértice pelos coeficientess tx e ty, ao longo dos eixos x e y, respectivamente
void transladaVertice (VERTICE* vertice, GLfloat tx, GLfloat ty){
	vertice->x += tx;
	vertice->y += ty;
	
	return;
}

//Translada polígono pelos coeficientess tx e ty, ao longo dos eixos x e y, respectivamente
void transladaPoligono (POLIGONO* figura, GLfloat tx, GLfloat ty){
	VERTICE* verticeAtual = figura->vertices;
	
	while(verticeAtual != NULL){
		transladaVertice (verticeAtual, tx, ty);
		verticeAtual = verticeAtual->prox;
	}
	
	return;
}

//Escala vértice pelos coeficientess sx e sy, ao longo dos eixos x e y, respectivamente
void escalaVertice (VERTICE *vertice, GLfloat sx, GLfloat sy){
	vertice->x *= sx;
	vertice->y *= sy;
	
	return;
}

//Escala polígono pelos coeficientess sx e sy, ao longo dos eixos x e y, respectivamente
void escalaPoligono (POLIGONO *figura, GLfloat sx, GLfloat sy){
	VERTICE* verticeAtual = figura->vertices;
	
	while(verticeAtual != NULL){
		escalaVertice (verticeAtual, sx, sy);
		verticeAtual = verticeAtual->prox;
	}
	
	return;
}

//Rotaciona ao redor da origem com ângulo em radianos
void rotacionaVertice (VERTICE *vertice, GLfloat angulo){
	GLfloat seno = sin(angulo), cosseno = cos(angulo);
	GLfloat x = vertice->x, y = vertice->y;
	
	vertice->x = x*cosseno - y*seno;
	vertice->y = x*seno + y*cosseno;
	
	return;
}

//Rotaciona ao redor da origem com ângulo em radianos
void rotacionaPoligono (POLIGONO *figura, GLfloat angulo){
	VERTICE* verticeAtual = figura->vertices;
	
	while(verticeAtual != NULL){
		rotacionaVertice (verticeAtual, angulo);
		verticeAtual = verticeAtual->prox;
	}
	
	return;
}

//Apenas desenha o polígono pelos seus vértices
void desenhaPoligono (POLIGONO* figura){
	VERTICE* verticeAtual = figura->vertices;
	
	glBegin(GL_POLYGON);
	
	while (verticeAtual != NULL){
		glVertex2f (verticeAtual->x, verticeAtual->y);
		verticeAtual = verticeAtual->prox;
	}
	
	glEnd();
	
	return;
}

//Função que desenha na tela
void desenha(){
	POLIGONO* Triangulo;
	
	//Limpa a tela com a cor preta
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Cria o triângulo original
	Triangulo = criaPoligono();
	adicionaVertice(Triangulo, 3.5, 4.5);
	adicionaVertice(Triangulo, 6.0, 4.5);
	adicionaVertice(Triangulo, 6.0, 5.5);
	
	//Desenha o triângulo original com cor vermelha
	DESENHA_COM_COR_VERMELHA
	desenhaPoligono (Triangulo);
	
	//Desenha triângulo transladado com cor azul
	transladaPoligono (Triangulo, -4.0, -3.0);
	DESENHA_COM_COR_AZUL
	desenhaPoligono (Triangulo);
	
	//Desenha triângulo transaladado e rotacionado com cor verde
	rotacionaPoligono (Triangulo, 0.5*M_PI);
	DESENHA_COM_COR_VERDE
	desenhaPoligono (Triangulo);
	
	//Desenha triângulo transladado, rotacionado e escalado com cor amarela
	escalaPoligono (Triangulo, 2.0, 1.5);
	DESENHA_COM_COR_AMARELA
	desenhaPoligono (Triangulo);
	
	deletaPoligono (Triangulo);
	
	glFlush();
	
}

//Inicializa parâmentros antes de começar a desenhar
void inicializa(){
	//Limpa a tela com cor preta
	glClearColor(0,0,0,0);
	//Só mostra o que estiver entre as coordenadas -10.0 e 10.0, tanto no eixo x, quanto no eixo y
	gluOrtho2D(-10.0,10.0,-10.0,10.0);
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
	glutInitWindowSize(800,600);
	glutInitWindowPosition(10,50);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Trabalho 1");
	inicializa();
	glutDisplayFunc(desenha);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
