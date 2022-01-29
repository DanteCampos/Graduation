void filli(int *v, int cols, int k);

void fills(short *v, int cols, int k);



int calc()

{

   int i = 0;  // usar registrador

   int j = 4;  // usar registrador

   int sum;

   int vet1[5];

   short vet2[5];



   filli(vet1, 5, i);

   fills(vet2, 5, j);



   sum = 0;

   for ( ; i < 5; i++, j--) {

     sum += vet1[i] + vet2[j];

   }



   return sum;

}
