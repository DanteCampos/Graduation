// Cria e inicializa as variáveis

char c = -20;
int i = -256;
unsigned int ui = 1024;
long l = 128;
unsigned long ul = 2048;
int v[5] = {10,20,30,40,50};
unsigned short us = 111;

void aux(){

  long *ptr;

  i = c;
  ui = i;
  ul = ui;
  us = ul;
  c  = 10 + i - 5;
  i = v[2];
  v[4] = i;
  v[0] = v[3] - v[2] - v[1] + i;
  ptr = &l;
  *ptr = ul;
  l = l * c;
}
