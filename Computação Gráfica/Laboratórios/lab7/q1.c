#include <GL/glut.h>
void init (void){
	glClearColor (1.0,1.0,1.0,0.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

//Desenho de segmentos de reta com inclinacao entre 0 e 45 graus
void lineBres (GLint x0, GLint y0, GLint xEnd, GLint yEnd){
	GLint dx = xEnd -x0, dy = yEnd -y0;
	GLint p = 2* dy - dx; //o d inicial
	GLint twoDy = 2 + dy; //o delta E
	GLint twoDyMinusDx = 2 * (dy - dx); //o delta NE
	GLint x, y; //x e y do ponto que está sendo pintado agora
 
	/* Determina qual ponto é o inicial*/
	if(x0 > xEnd){ //o ponto End é o mais à esquerda
		x = xEnd;
		y = yEnd;
		xEnd = x0;
	}else{ //o ponto 0 é o mais à esquerda
		x = x0;
		y = y0;
	}
	
	//Desenha o primeiro pixel
	glBegin( GL_POINTS );
	glVertex2i( x, y );
	glEnd();

	while(x < xEnd){ //o loop para pintar cada pixel
		x++; //avança o ponto 1 pixel à direita
		
		if (p < 0) //ponto médio acima da reta, escolhe o ponto E para pintar
			p+=twoDy; //o ponto médio é referente ao novo x,y que escolheu o E
		else{ //ponto médio abaixo ou na reta, escolhe o ponto NE para pintar
			y++; //escolher o ponto NE é subir um pixel
			p+=twoDyMinusDx; //o ponto médio é referente ao novo x,y que escolheu o NE
		}
		
		//pinta o pixel novo
		glBegin( GL_POINTS );
		glVertex2i( x, y );
		glEnd();
	}
}

void displayFcn (void){
	glClear (GL_COLOR_BUFFER_BIT); //limpa a janela de visao (display window)
	glColor3f (0.0,0.0,1.0); //estalebece a cor de preenchimento inicial como azul
	lineBres (10, 10, 70, 70); //segmento de reto do ponto (10,10) ao ponto (70,70)
	glFlush();
}

int main (int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition (50, 100);
	glutInitWindowSize (61, 61);
	glutCreateWindow ("Exemplo 1 do Open GL");
	init();
	glutDisplayFunc (displayFcn);
	glutMainLoop ();
}
