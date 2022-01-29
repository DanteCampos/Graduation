short v1[2] = {1, 2};

long  v2[3] = {1, 2, 3};



void sum(short *a1, int p1, long *a2, int p2);



void aux(short *a1, int p1) {

  int i;

  for (i = 2; i >= 0; i--)

    sum(a1, p1, v2, i);

}



int main() {

  int i = 0;

  while (i < 2) {

    aux(v1, i);

    i++;

  }

  return 0;

}
