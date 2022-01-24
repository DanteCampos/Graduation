#include <GL/glut.h>

void init(){
	glClearColor(0,0,0,0);
	gluOrtho2D(-25,25,-25,25);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin (GL_LINES);
		//Eixo x
		glColor3f (1,1,1);
		glVertex2f(-10,0);
		glVertex2f(10,0);
		
		//Eixo y
		glColor3f (1,1,1);
		glVertex2f(0,-10);
		glVertex2f(0,10);
		
		//Eixo 45 graus
		glColor3f (0,1,0);
		glVertex2f(-10,-10);
		glVertex2f(10,10);
	glEnd();
	
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
	
	//Quadrado Azul (espelhado)
	glPushMatrix ();
	glRotatef (-45, 0.0, 0.0, 1.0); //Iguala reta com o eixo x
	glRotatef (180, 0.0, 0.0, 1.0); //Espelha
	glRotatef (+45, 0.0, 0.0, 1.0); //Volta reta pro normal
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
	glutInitWindowSize(800,600);
	glutInitWindowPosition(10,50);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Questao 4");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
