#include <stdlib.h>

#include <string.h>



#include "node.h"



extern int sync;



void init(node_t *node)

{

  node_t tmp[2] = {

    {5, {1,2,3,1,1}, 3},

    {5, {4,5,6,7,1}, 4}

  };



  memcpy(node, &tmp[sync], sizeof(node_t));



  sync = (sync+1) % 2;

}
