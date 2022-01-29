#include <stdio.h>

#include <string.h>



#include "node.h"



void init(node_t *node);



int sync = 0;



long getvalue(node_t *node, int i)

{

  return node->values[i];

}



long sum(node_t *node)

{

  int i = 0;

  long s = 0;

  while (i < node->used)

    s += getvalue(node, i++);

  return s;

}



void process(node_t *nodes);



int main()

{

  node_t nodes[2];

  process(nodes);

  return 0;

}
