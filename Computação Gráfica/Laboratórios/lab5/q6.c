#include <GL/glut.h>
#include <stdio.h>

GLfloat pivotX=0, pivotY=0, graus=0;

void rotacionaPivot (){
	glTranslatef(-pivotX, -pivotY, 0);
	glRotatef(graus, 0,0,1);
	glTranslatef(pivotX, pivotY, 0);
	
	return;
}

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
	rotacionaPivot ();
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
	
	printf("Digite as coordenadas do pivot (x,y):\n");
	scanf("%f %f", &pivotX, &pivotY);
	
	printf("Digite os graus da rotação:\n");
	scanf("%f",&graus);

	glutInit(&argc, argv);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(10,50);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Questao 6");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
