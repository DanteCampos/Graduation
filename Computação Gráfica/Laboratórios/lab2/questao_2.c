// Um programa OpenGL simples que abre uma janela GLUT
// Este código está baseado no Simple.c, exemplo
// disponível no livro "OpenGL SuperBible",
// 2nd Edition, de Richard S. e Wright Jr.

#include <GL/glut.h>
#include <stdlib.h>
// Função callback chamada para fazer o desenho
void Desenha(void){
	//Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);
	//Executa os comandos OpenGL
	glFlush();
}
// Inicializa parâmetros de rendering
void Inicializa (void){
	// Define a cor de fundo da janela de visualização como preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
// Programa Principal
int main(int argc, char** argv){
	glutInit(&argc, argv); // inicializa o glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Programa Zero");
	glutDisplayFunc(Desenha);
	Inicializa();
	glutMainLoop();
}

/*
O programa cria uma janela chamada "Programa Zero" (sem especificar posição ou tamanho),
define a cor da função clear como preto opaco, e então limpa a tela (pela função Desenha).
Não há nem ao menos um comando para fechar o programa, que deve ser finalizado pelo próprio terminal.
Além disso, tive que incluir a biblioteca stdlib para poder compilar o programa,
pois a função main ficava indefinida.
*/
