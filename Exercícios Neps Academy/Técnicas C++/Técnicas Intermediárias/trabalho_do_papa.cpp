/* Author: Marcio T. I. Oshiro */

#include <stdio.h>
#include <stdlib.h>

#define INF 2147483647
#define MAX_N 10001

typedef struct {
  int p; /* peso */
  int f; /* força */
} caixa;

/* Função de comparação para o qsort */
int comp(const void *a, const void *b) {
  caixa *x = (caixa*)a;
  caixa *y = (caixa*)b;
  
  if (x->f < y->f) {
    return -1;
  } else if (x->f > y->f) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int inst, i, j, k, n, min, cont;
  caixa t[MAX_N];
  /*
   * m[i][j] é o menor peso de uma pilha com i caixas cujas caixas
   * estão todas em {1, ..., j} e a última caixa é a caixa j, mas como
   * para preencher a tabela é preciso apenas a linha anterior, a tabela
   * tem apenas duas linhas. Se m[i][j] == -1, não existe tal pilha.
   */
  int m[2][MAX_N];
  
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d %d", &j, &k);
      t[i].p = j;
      t[i].f = k;
    }
    
    /* É possivel provar que sempre existe uma solução ótima onde a força das
     * caixas está ordenada.
     */
    qsort(t, n, sizeof(t[0]), comp);

    cont = 0;
    /* Verifica existência de uma pilha de altura 1. */
    for (i = 0; i < n; i++) {
      if (t[i].f >= t[i].p) {
	m[0][i] = t[i].p;
      } else {
	m[0][i] = -1;
	cont++; /* conta quantos -1 aparecem na tabela */
      }
    }
    if (cont < n) {
      /* Verifica existência de uma pilha de altura maior que 1. */
      for (i = 1; i < n; i++) {
	cont = 0;
	for (j = 0; j < n; j++) {
	  /* (i + 1) % 2 == (i - 1) % 2 para i > 0 */
	  if (m[(i + 1) % 2][j] == -1 || i > j) {
	    m[i % 2][j] = -1;
	    cont++;
	  } else {
	    min = INF;
	    /* 
	     * Procura a pilha de altura i com menor peso tal que a caixa
	     * j a suporte.
	     */
	    for (k = i - 1; k < j; k++) {
	      if (m[(i + 1) % 2][k] > -1 && t[j].f >= t[j].p + m[(i + 1) % 2][k]
		  && m[(i + 1) % 2][k] < min) {
		min = m[(i + 1) % 2][k];
	      }
	    }
	    if (min == INF) {
	      m[i % 2][j] = -1;
	      cont++;
	    } else {
	      m[i % 2][j] = min + t[j].p;
	    }
	  }
	}
	if (cont == n) break;
      }  
      printf("%d\n", i);
    } else {
      printf("0\n");
    }
  return 0;
}
