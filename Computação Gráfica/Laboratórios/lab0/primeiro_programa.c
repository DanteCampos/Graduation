// PrimeiroPrograma.c - Isabel H. Manssour
// Um programa OpenGL simples que abre uma janela GLUT
// Este código está baseado no Simple.c, exemplo disponível no livro
// "OpenGL SuperBible", 2nd Edition, de Richard S. e Wright Jr.
#include <GL/glut.h> //ALTEREI DE gl PARA GL
// Função callback chamada para fazer o desenho
void Desenha(void)
{
// Limpa a janela de visualização com a cor de fundo especificada
glClear(GL_COLOR_BUFFER_BIT);
// Executa os comandos OpenGL
glFlush();
}
// Inicializa parâmetros de rendering
void Inicializa (void)
{
// Define a cor de fundo da janela de visualização como preta
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
// Programa Principal
void main(int n_args, char** args) //ADICIONEI O CABEÇALHO DA MAIN PARA USO DA glutInit
{
glutInit(&n_args, args); //ADICIONADA PARA EXECUÇÃO DO glutCreateWindow
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutCreateWindow("Primeiro Programa");
glutDisplayFunc(Desenha);
Inicializa();
glutMainLoop();
}
