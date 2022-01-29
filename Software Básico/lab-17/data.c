#include <stdio.h>        // não traduzir para Assembly

#include "data.h"         // não traduzir para Assembly



void show(struct data *d) {

  int i;

  long *ptr = d->elems;

  for (i = 0; i < d->len; i++) {

    printf("%ld\n", ptr[i]);

  }

}
