#include <GL/glut.h>

void init(){
	glClearColor(0,0,0,0);
	gluOrtho2D(-25,25,-25,25);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Quadrado Vermelho
	glPushMatrix ();
	glRotatef(180,0,0,1);
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
	glRotatef(90,0,0,1);
	glColor3f(0,1,0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-4,-4);
	glVertex2f(-4,-2);
	glVertex2f(-2,-4);
	glEnd();
	glPopMatrix();
	
	//Pentágono Azul
	glPushMatrix ();
	glRotatef(-90,0,0,1); //anti-horário = ângulo negativo
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
	//Para rodar ao redor de um ponto (x,y) devemos transladar ele para a origem,
	//rotacionar a figura ao redor dessa origem, e então transladar de volta.
	//Usei como exemplo o ponto (4, 3) aqui:
	glTranslatef(-4,-3,0);
	glRotatef(45,0,0,1);
	glTranslatef(4,3,0);
	glColor3f(1,1,0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-3,4);
	glVertex2f(-6,2);
	glVertex2f(-3,8);
	glEnd();
	glPopMatrix();
	
	//Quadrado Branco
	glPushMatrix ();
	//Para rodar ao redor de um ponto (x,y) devemos transladar ele para a origem,
	//rotacionar a figura ao redor dessa origem, e então transladar de volta.
	//Usei como exemplo o ponto (-7, 3) aqui:
	glTranslatef(7,-3,0);
	glRotatef(-180,0,0,1); //anti-horário = ângulo negativo
	glTranslatef(-7,3,0);
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
