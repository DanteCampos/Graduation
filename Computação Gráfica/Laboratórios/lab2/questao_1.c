#include <GL/glut.h>
#include <stdlib.h>
// prototipos das funcoes
void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
// funcao principal
int main(int argc, char** argv){
	glutInit(&argc, argv); // inicializa o glut
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // especifica o uso de cores e buffers
	glutInitWindowSize (256, 256); // especifica as dimensoes da janela
	glutInitWindowPosition (100, 100); // especifica aonde a janela aparece na tela
	glutCreateWindow ("Desenhando uma linha"); // cria a janela
	init();
	glutDisplayFunc(display); // funcao que sera redesenhada pelo GLUT
	glutKeyboardFunc(keyboard); // funcoes de teclado
	glutMainLoop(); // mostra todas as janelas criadas
	return 0;
}
// definicao de cada funcao
void init(void){
	glClearColor(1.0, 1.0, 1.0, 1.0); // cor de fundo
	glOrtho (0, 256, 0, 256, -1 ,1); // modo de projecao ortogonal - Recorte
}
void display(void){
	int i;
	glClear(GL_COLOR_BUFFER_BIT); // limpa a janela
	glColor3f (0.0, 0.0, 0.0); // cor da linha
	glBegin(GL_LINES);
	//Ponto1 x1 y1
	glVertex2i(20,250); // coordenadas inicial e final da linha
	//Ponto2 x2 y2
	glVertex2i(200,10);
	//glVertex2i(40,200); glVertex2i(200,10);
	glEnd();
	glFlush();
}
void keyboard(unsigned char key, int x, int y){
	switch (key) {
		case 27: // tecla Esc (encerra o programa)
		exit(0);
		break;
	}
}

/*
Simplesmente escolhe dois pontos e traça uma reta preta entre eles com um fundo branco.
A função display é escrita por nós, mas chamada internamente pelo OpenGL, assim como a keyboard.
Por ser uma máquina de estados, a função utilizada para essas tarefas também é um estado alterável.
*/
