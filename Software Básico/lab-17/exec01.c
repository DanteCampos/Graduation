#include <stdio.h>



#define BLUE 1

#define RED  2



struct Circle {

   int  x;

   int  y;

   char filled;

   long color;

};



struct Circle c1;



int main() {

  c1.x = 10;

  c1.y = 2 * c1.x;

  c1.filled = 1;

  if (c1.y > 30)

    c1.color = RED;

  else

    c1.color = BLUE;

  printf("color: %ld, filled: %d\n", c1.color, (int)c1.filled);

  return 0;

}
