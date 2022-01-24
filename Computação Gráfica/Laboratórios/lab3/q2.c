#include <GL/glut.h>

void init(){
	glClearColor(0,0,0,0);
	gluOrtho2D(-25,25,-25,25);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Quadrado Vermelho
	glPushMatrix ();
	glScalef(3,3,0); //figura 2D 3 vezes maior nos eixos x e y
	glColor3f(1,0,0);
	glBegin(GL_QUADS);
	glVertex2f(-4,-4);
	glVertex2f(-4,-2);
	glVertex2f(-2,-2);
	glVertex2f(-2,-4);
	glEnd();
	glPopMatrix();
	
	//Triângulo Verde
	glPushMatrix ();
	glScalef(1.0 + (1.0/3.0),1.0 + (1.0/3.0),0); //figura 2D 1 terço maior nos eixos x e y
	glColor3f(0,1,0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-4,-4);
	glVertex2f(-4,-2);
	glVertex2f(-2,-4);
	glEnd();
	glPopMatrix();
	
	//Pentágono Azul
	glPushMatrix ();
	glScalef(4,1,0); //figura 2D 4 vezes no eixo x
	glColor3f(0,0,1);
	glBegin(GL_POLYGON);
	glVertex2f(3,4);
	glVertex2f(6,2);
	glVertex2f(6,6);
	glVertex2f(5,5);
	glVertex2f(3,8);
	glEnd();
	glPopMatrix();
	
	//Triângulo Amarelo
	glPushMatrix ();
	glScalef(1,2.0/3.0,0); //figura 2D 4 vezes no eixo x
	glColor3f(1,1,0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-3,4);
	glVertex2f(-6,2);
	glVertex2f(-3,8);
	glEnd();
	glPopMatrix();
	
	//Quadrado Branco
	glPushMatrix ();
	glScalef(3.0/4.0,7.0/5.0,0); //figura 2D 4 vezes no eixo x
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glVertex2f(-10,10);
	glVertex2f(-10,5);
	glVertex2f(-5,5);
	glVertex2f(-5,10);
	glEnd();
	glPopMatrix();
	
	glFlush();
}


int main(int argc, char ** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(10,50);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Questao 2");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
