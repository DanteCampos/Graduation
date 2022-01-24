#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

//Defines para facilitar a escrita e seleção de cores
#define DESENHA_COM_COR_VERMELHA glColor3f (1.0, 0.0, 0.0);
#define DESENHA_COM_COR_VERDE glColor3f (0.0, 1.0, 0.0);
#define DESENHA_COM_COR_AZUL glColor3f (0.0, 0.0, 1.0);
#define DESENHA_COM_COR_PRETA glColor3f (0.0, 0.0, 0.0);
#define DESENHA_COM_COR_BRANCA glColor3f (1.0, 1.0, 1.0);
#define DESENHA_COM_COR_AMARELA glColor3f (1.0, 1.0, 0.0);


int opcao;
GLdouble translated_x, rotated_x;

 	
void Perspectiva_direcaoX(GLdouble angulo,GLdouble propocao, GLdouble Dproximo, GLdouble Dlonge)
{   
    // angulo     - Define o angulo de visão na direção de X
    // propocao   - propoção da visualização
    // Dproximo   - A distancia até o plano mais proximo (D)
    // Dlonge     - A distancia até o plano mais longe (Zp)

   GLdouble altura_em_x, xmin, ymin, largura_em_y;
   GLdouble PI = 3.1415926535897932384626433832795;
   
   GLdouble m[4][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // Calcula a distance entre a posicao 0 no plano x ate seu topo com base no angulo e o plano mais proximo (Dproximo)
    // como a funcao tan funciona em radianos, fiz (angulo / 2) / 180*PI
   altura_em_x =  tan( (angulo / 2) / 180*PI) * Dproximo;
   xmin = -altura_em_x;
   
   // calcula a distancia no plano y
   ymin = xmin / propocao;
   largura_em_y = altura_em_x / propocao;
    
   // configurando a mascara na matrix na direção de X
   m[0][0] = (2.0 * Dproximo) / (altura_em_x - xmin);
   m[1][1] = (2.0 * Dproximo) / (largura_em_y - ymin);
   m[2][2] = -(Dlonge + Dproximo) / (Dlonge - Dproximo);
   m[0][2] = (altura_em_x + xmin) / (altura_em_x - xmin);
   m[1][2] = (largura_em_y + ymin) / (largura_em_y - ymin);
   m[3][2] = -1.0;
   m[2][3] = -(2.0 * Dlonge * Dproximo) / (Dlonge - Dproximo);
   
   // fazendo a multiplicação de matrix e adicionado ao opengl
   glMultMatrixd(*m); 
}
void Ortogonal( GLdouble coordenada_esquerda, GLdouble coordenada_direita, GLdouble coordenada_base, GLdouble coordenada_topo, GLdouble Dproximo, GLdouble Dlonge) 
{ 
    // coordenada_esquerda e coordenada_direita sao as coordenadas para o corte do plano vertical
    // cordenada_base e cordenada_topo sao as coordenadas para o corte do plano horizontal
    // Dproximo   - A distancia até o plano mais proximo (D)
    // Dlonge     - A distancia até o plano mais longe (Zp)

    GLdouble m[4][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // configurando a mascara na matrix na direção de Y
    m[0][0] = 2 / (coordenada_direita - coordenada_esquerda); 
    m[1][1] = 2 / (coordenada_topo - coordenada_base); 
    m[2][2] = -2 / (Dlonge - Dproximo);  
    m[3][0] = -(coordenada_direita + coordenada_esquerda) / (coordenada_direita - coordenada_esquerda); 
    m[3][1] = -(coordenada_topo + coordenada_base) / (coordenada_topo - coordenada_base); 
    m[3][2] = -(Dlonge + Dproximo) / (Dlonge - Dproximo); 
    m[3][3] = 1; 
} 

void inicializa() 
{   
   opcao = 1;
   translated_x = 0;
   rotated_x = 0;
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void desenha(void)
{
   glClear (GL_COLOR_BUFFER_BIT);

   DESENHA_COM_COR_BRANCA

   glLoadIdentity ();             // limpa a matrix

   // prepara para exibir uma projecao em perspetiva caso opcao seja 0
   if(opcao) gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

   glRotatef(rotated_x,0.0,0.0,1.0);
   glTranslatef(translated_x,0.0,0.0);
   
   if(!opcao) 
        glScalef (0.5, 0.5, 0.5);   

   glutWireCube (1.0); // renderiza um cubo

   glFlush ();
}

void remodelar (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();

   if (opcao)
        Perspectiva_direcaoX(15.0, 1.0, 2, 40);
   else
        Ortogonal(-1.5, 1.5, -1.5, 1.0, -2, 1.5);

   glMatrixMode (GL_MODELVIEW);
}

//Função chamada quando alguma tecla é pressionada
void keyboard(unsigned char key, int x, int y){

	switch (key) {
		case 27: // tecla ESC (encerra o programa)
		exit(0);
		break;
        
        // 1 para mudar para Ortogonal e 0 para perspetiva
		case 'q':
            opcao = 1;
            break;
		case 'e':
			opcao = 0;
			break;

        // `q` e `a` muda a visao para direita e esquerda
        case 'w':
            translated_x += 0.1;
            break;
		case 's':
			translated_x -= 0.1;
			break;
        
        // `e` e `d` muda a rotacao para direita e esquerda
        case 'd':
            rotated_x += 2;
            if (rotated_x >= 360)
            	rotated_x = 0;
            break;
		case 'a':
			rotated_x -= 2;
			if (rotated_x <= -360)
				rotated_x = 0;
			break;
        
	}
	
	remodelar(800, 800);
    desenha(); 
    
}



int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (800, 800); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   inicializa();
   glutDisplayFunc(desenha); 
   glutReshapeFunc(remodelar);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
