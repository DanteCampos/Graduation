#include <stdio.h>

#include <math.h>



#include "prod.h"



produto_t prods[] = {

  {1, 20.5},

  {2, 23.3},

  {3, 13.8},

  {0,  0.0}

};

double max_prod(produto_t *ptr);



int main()

{

  double m = max_prod(prods);

  printf("Maximo: %f\n", m);

  return 0;

}
