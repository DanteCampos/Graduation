#include <stdio.h>

#include <math.h>



#include "prod.h"



double max_prod(produto_t *ptr)

{

  double m = 0.0;

  while (ptr->id) {

    double tmp = floor(ptr->value);

    if (m < tmp)

      m = tmp;

    ptr++;

  }

  return m;

}
