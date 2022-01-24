#include<GL/glut.h>//inclua a biblioteca glut

void init(){
	glClearColor(0,0,0,0);
	gluOrtho2D(-5,5,-5,5);//estabeleca a area de visualizacao
}

//A seguir e discriminada a nossa fincao de exibicao chamada display.
//Temos tres objetos com suas respectiva cores.
//Algumas funcoes novas serao apresentadas.
//glPushMatrix(); cria uma nova matrix na pilha de matrizes.
//glPopMatrix(); retira uma matriz da pilha de matrizes.
//glRotatef(ang,x,y,z); rotaciona objetos em torno da origem. O primeiro argumento e o angulo da
//rotacao em radianos. Os outros argumentos estao relacionados aos eixos de rotacao. Se voce usar
//(90,1,0,0) sera rotacionado 90 graus em torno do eixo X..
//glScalef(sx,sy,sz);
//glTranslatef(tx,ty,tz);

void display(){
	GLdouble theta = 90;
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1,0,0);//cor vermelha
	glBegin(GL_QUADS);//comeca a desenhar quadrilatros
	glVertex2f(-4,-4);//primeiro vertice
	glVertex2f(-4,-2);//segundo vertice
	glVertex2f(-2,-2);//terceiro vertice
	glVertex2f(-2,-4);//ultimo vertice
	glEnd();//termina o desenho
	
	glPushMatrix();
	glColor3f(1,0,0);//cor vermelha
	glRotatef(theta,0,0,1);
	glBegin(GL_TRIANGLES);//comeca a desenhar
	glVertex2f(3,-4);//1st vertex
	glVertex2f(3.5,-3);//2nd vertex
	glVertex2f(4,-4);//last vertex
	glEnd();//termina o desenho
	glPopMatrix();
	
	glColor3f(0,1,0);//cor verde
	glPushMatrix();
	glTranslatef(3,3,0);
	glBegin(GL_QUADS);//comeca a desenhar quadrilatros
	glVertex2f(-4,-4);//primeiro vertice
	glVertex2f(-4,-2);//segundo vertice
	glColor3f(0,0,1);//troca a cor para azul
	glVertex2f(-2,-2);//terceiro vertice
	glVertex2f(-2,-4);//ultimo vertice
	glEnd();//termina o desenho
	glPopMatrix();//(interompe todas as transformacoes correntes
	
	glPushMatrix();//cria nova matriz
	glScalef(2,2,2);
	glColor3f(1,0,0);//primeiro vertice e vermelho
	glBegin(GL_POLYGON);
	glVertex2f(-2,2);//primeiro vertice
	glColor3f(0,1,0);//segundo vertice e verde
	glVertex2f(-1,3);//segundo vertice
	glColor3f(0,0,1);//terceiro vertice e azul
	glVertex2f(0,2);//third vertex
	glColor3f(1,0,1);//quarto vertice e purpura
	glVertex2f(-0.5,0);//quarto vertice
	glColor3f(1,1,0);//ultimo vertice e amarelo
	glVertex2f(-1.5,0);//ultimo vertice
	glEnd();
	glPopMatrix();

	glFlush();
}

int main(int argc, char ** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(10,50);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Transformacoes");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
