#include <GL/glut.h>

void init(){
	glClearColor(0,0,0,0);
	gluOrtho2D(-25,25,-25,25);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Quadrado Vermelho (não espelhado)
	glPushMatrix ();
	glColor3f(1,0,0);
	glBegin(GL_QUADS);
	glVertex2f(+4,-4);
	glVertex2f(+4,-2);
	glVertex2f(+2,-2);
	glVertex2f(+2,-4);
	glEnd();
	glPopMatrix();
	
	//Quadrado Azul (escalado)
	glPushMatrix ();
	glTranslatef (-3,+3,0); //Iguala centro do quadrado com a origem
	glScalef (2, 2, 0); // Escala o quadrado
	glTranslatef (+3,-3,0); //Volta centro pra posição anterior
	glColor3f(0,0,1);
	glBegin(GL_QUADS);
	glVertex2f(+4,-4);
	glVertex2f(+4,-2);
	glVertex2f(+2,-2);
	glVertex2f(+2,-4);
	glEnd();
	glPopMatrix();
	
	glFlush();
}


int main(int argc, char ** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(10,50);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Questao 5");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
