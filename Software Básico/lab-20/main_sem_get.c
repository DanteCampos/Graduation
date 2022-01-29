#include <stdio.h>

#include <string.h>



#include "node.h"



void init(node_t *node);



int sync = 0;



long getvalue(node_t *node, int i);



long sum(node_t *node)

{

  int i = 0;

  long s = 0;

  while (i < node->used)

    s += getvalue(node, i++);

  return s;

}



void process(node_t *nodes)

{

  init(&nodes[1]);

  init(&nodes[0]);

  printf("sum: %ld\n", sum(&nodes[1]));

}



int main()

{

  node_t nodes[2];

  process(nodes);

  return 0;

}
