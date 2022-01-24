#include <GL/glut.h>
#include <stdlib.h>

// Função callback chamada para fazer o desenho
void Desenha(void){
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);
	
	glLineWidth(3);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2i(50,100);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2i(100,150);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2i(150,100);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glVertex2i(50,1);
	glVertex2i(50,99);
	glVertex2i(150,99);
	glVertex2i(150,1);
	glEnd(); 
	
	//Fazendo uma portinha
	glColor3f(0.5f, 0.3f, 0.05f);
	glBegin(GL_QUADS);
	glVertex2i(90,2);
	glVertex2i(110,2);
	glVertex2i(110,50);
	glVertex2i(90,50);
	glEnd();
	
	// Executa os comandos OpenGL
	glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa (void){
	// Define a cor de fundo da janela de visualização como ciano
	glClearColor(0.0f, 0.8f, 1.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h){
	// Evita a divisao por zero
	if(h == 0) h = 1;
	// Especifica as dimensões da Viewport
	glViewport(0, 0, w, h);
	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Estabelece a janela de seleção (left, right, bottom, top)
	if (w <= h)
	gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
	else
	gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

// Programa Principal
void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400,350);
	glutInitWindowPosition(10,10);
	glutCreateWindow("Quadrado");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	Inicializa();
	glutMainLoop();
}
