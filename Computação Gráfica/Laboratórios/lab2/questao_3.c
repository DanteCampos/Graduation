#include <GL/glut.h>
#include <stdlib.h>

void init (void){
	glClearColor (0.0,0.0,0.0,0.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}
void lineSegment (void){
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.5, 1.0,0.5);
	glBegin (GL_LINES);
	glVertex2i (100, 50);
	glVertex2i (80, 135);
	glEnd ();
	glFlush ();
}
int main (int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition (200, 300);
	glutInitWindowSize (800, 300);
	glutCreateWindow ("Segmento de Reta");
	init();
	glutDisplayFunc (lineSegment);
	glutMainLoop ();
}

/*
Tive que incluir a stdlib para definir a funçao main.
O programa cria uma janela definindo nome, posição e tamanho, os quais alterei livremente.
Também modifiquei as coordenadas da linha, a cor de clear para preto, e a cor da linha para um verde claro.
As coordenadas virtuais são especificadas na função lineSegment, mas as coordenadas de visualização
dependem da glMatrixMode(GL_PROJECTION) (que diz que as alterações posteriores alteram a câmera),
da gluOrtho2D (que especifica um intervalo de x e de y nas coordenadas virtuais que serão visualizados), e,
por fim, as funções de janela (com Window no nome), que definem o tamanho da janela que de fato está
sendo visualizada e deformam a visualização para encaixar na tela.
*/
