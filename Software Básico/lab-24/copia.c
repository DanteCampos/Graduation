#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define TAM 128


// Protótipo das funções
int     myopen(const char *pathname, int flags, int size);
ssize_t myread(int fd, void *buf);
ssize_t mywrite(int fd, const void *buf, size_t count);
int     myclose(int fd);

//----------------------------------------------------------------------------

// int tamBufferAberto;

/*
int myopen(const char *pathname, int flags, int buffersize)
{
  tamBufferAberto = buffersize;
  return open(pathname, flags);
}
*/

/*
ssize_t myread(int fd, void *buf)
{
  return read(fd, buf, tamBufferAberto);
}
*/

/*
ssize_t mywrite(int fd, const void *buf, size_t count)
{
  return write(fd, buf, count);
}
*/

/*
int myclose(int fd)
{
  return close(fd);
}
*/

//----------------------------------------------------------------------------

int main (int argc, char** argv)
{
  int  fd;
  char buf[TAM];
  ssize_t len;
  
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <nome_arquivo>\n", argv[0]);
    return 1;
  }
  
  fd = myopen(argv[1], O_RDONLY, TAM);
  if (fd < 0) {
    perror("[ERRO] Falha na abertura do arquivo: ");
    return 1;
  }

  while ( (len = myread(fd, buf)) > 0) {
    if ( (mywrite(STDOUT_FILENO, buf, len) != len) ) {
      perror("[ERRO] Falha na escrita do arquivo: ");
      return 1;
    }
  }

  myclose (fd);

  return 0;
}  

