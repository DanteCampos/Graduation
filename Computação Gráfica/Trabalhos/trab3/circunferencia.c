//Trabalho 3 de Computação Gráfica 2020/01
//Feito em 24/11/2020
//Para compilar, use os seguintes modificadores: -lglut -lGL -lGLU -lm

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

//Defines para facilitar a escrita e seleção de cores
#define DESENHA_COM_COR_VERMELHA glColor3f (1.0, 0.0, 0.0);
#define DESENHA_COM_COR_VERDE glColor3f (0.0, 1.0, 0.0);
#define DESENHA_COM_COR_AZUL glColor3f (0.0, 0.0, 1.0);
#define DESENHA_COM_COR_PRETA glColor3f (0.0, 0.0, 0.0);
#define DESENHA_COM_COR_BRANCA glColor3f (1.0, 1.0, 1.0);
#define DESENHA_COM_COR_AMARELA glColor3f (1.0, 1.0, 0.0);


int T_RAIO; //Variável para o raio do circulo
int TIPO; //Variável para o modelo do circulo, seja pequeno ou grande

//Função que desenha na tela
void desenha();

//Inicializa a maioria dos parâmetros do codigo
void inicializa();

/* MidPointCircle:  Usando o procedimento de CirclePoint para traçar os pontos da circunferencia, esse algoritimo
gera valores E e SE para a variável "h" a partir do raio, e depedendo do valor de h, positivo ou não, será marcado no plano diversos
pontos para cada pixel. Quanto maior o raio, mais pontos serão a circunferencia e melhor será o circulo*/  
void MidPointCircle (int r);


/*CirclePoint: Essa função usa e marca oq é chamada de simetria de ordem 8, onde apartir de cada ponto, é obtido e demarcado
 8 novos lugares alterando a posição e o sinal do valor dado formando uma cincunferencia*/ 
void CirclePoint (int x,int y);


//Função chamada quando alguma tecla é pressionada
void keyboard(unsigned char key, int x, int y);


int main(int argc, char ** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(50,50);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Trabalho 3 - Traçado de Circunferencia");
	inicializa();
	glutDisplayFunc(desenha);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}


//Função que desenha na tela
void desenha(){

	//Limpa a tela com a cor preta
	glClear(GL_COLOR_BUFFER_BIT);

	//Desenha em linha Branca
    DESENHA_COM_COR_BRANCA

	//Traçando as linhas das coordenadas, variando entre os Tipos 1 e 2
    glBegin (GL_LINES);
    if (TIPO == 1){
        glVertex2f (-19.0,0.0);
	    glVertex2f (+19.0,0.0);
	    glVertex2f (0.0,-19.0);
	    glVertex2f (0.0,+19.0);
    } else if (TIPO == 2){
        glVertex2f (-80.0,0.0);
	    glVertex2f (+80.0,0.0);
	    glVertex2f (0.0,-80.0);
	    glVertex2f (0.0,+80.0);  
    }
	glEnd();

    //Desenha em linha vermelha
	DESENHA_COM_COR_VERMELHA

    //Aumenta o tamanho dos pontos
    glPointSize(3);

    //Desenha o Circulo
    MidPointCircle (T_RAIO);
	
    glFlush();
}


//Inicializa a maioria dos parâmetros do codigo
void inicializa(){
    TIPO = 0; 
	//Limpa a tela com cor preta
	glClearColor(0,0,0,0);

    printf("\nEntre com o Tipo Desejado:\n\n[1] Modelo Pequeno\n[2] Modelo Grande\n");
    while(TIPO != 1 && TIPO != 2)
        scanf("%d",&TIPO);
    if (TIPO == 1){
        //Escala da Circunferência Pequeno
        gluOrtho2D(-20,20,-20,20);
        T_RAIO = 3;
    } else if (TIPO == 2){
        //Escala da Circunferência Grande
	    gluOrtho2D(-85,85,-85,85);
        T_RAIO = 20;
    }
}   


/* MidPointCircle:  Usando o procedimento de CirclePoint para traçar os pontos da circunferencia, esse algoritimo
gera valores E e SE para a variável "h" a partir do raio, e depedendo do valor de h, positivo ou não, será marcado no plano diversos
pontos para cada pixel. Quanto maior o raio, mais pontos serão a circunferencia e melhor será o circulo*/  
void MidPointCircle (int r){
    int x, y;
    float d,h;
    //Valores iniciais
    x = 0;
    y = r;
    h = 1 - r;
    glBegin(GL_POINTS);


    CirclePoint (x,y);
    while (y > x){
        if (h < 0 ){
            //Selecione E
            h = h + 2*x + 3;
            x++;
        } else {
            //Selecione SE
            h = h + 2 * (x - y) + 5;
            x++;
            y--;
        }
        CirclePoint (x,y);
    }
    glEnd();
}


/*CirclePoint: Essa função usa e marca oq é chamada de simetria de ordem 8, onde apartir de cada ponto, é obtido e demarcado
 8 novos lugares alterando a posição e o sinal do valor dado formando uma cincunferencia*/ 
void CirclePoint (int x,int y){
    glVertex2i (x,y);
    glVertex2i (x,-y);
    glVertex2i (-x,y);
    glVertex2i (-x,-y);
    glVertex2i (y,x);
    glVertex2i (y,-x);
    glVertex2i (-y,x);
    glVertex2i (-y,-x);
}


//Função chamada quando alguma tecla é pressionada
void keyboard(unsigned char key, int x, int y){

	switch (key) {
		case 27: // tecla ESC (encerra o programa)
		exit(0);
		break;
		
		case 'w':
            if ((T_RAIO < 19 && TIPO == 1) || (T_RAIO < 77 && TIPO == 2)) // Limites superiores para o circulo não exceder o plano limitado
			    T_RAIO++;
            break;
			
		case 's':
			if ((T_RAIO > 1 && TIPO == 1) || (T_RAIO > 19  && TIPO == 2)) // Limites inferiores para o circulo não exceder o plano limitado
				T_RAIO--;
			break;
	}
	
	desenha();
}
