#include <stdio.h>

#include <string.h>



typedef int (*FuncPtr)(int);



unsigned char codigo[] = {

    0xf3, 0x0f, 0x1e, 0xfa,
    0x55,
    0x48, 0x89, 0xe5,
    0x48, 0x83, 0xec, 0x10,
    0x89, 0x7d, 0xfc,
    0x8b, 0x45, 0xfc,
    0x89, 0xc7,
    0xe8, 0x00, 0x00, 0x00, 0x00,
    0xc9,
    0xc3

};



int sum(int v) {

  return v+2;

}



int mul(int v) {

  return 2*v;

}



int main()

{

   int i;

   FuncPtr f;



   //---------------------------------------
	// Alterar "calc" para chamar a função "sum"
	//codigo[21] é o começo dos 4 bytes de endereço relativo em little endian

   	int deslocamento = (int) ((long)&sum - (long)&codigo[25]);
   	memcpy (&codigo[21], &deslocamento, sizeof(int));


   //---------------------------------------



   // Chama a função "calc"

   f = (FuncPtr)codigo;

   i = f(10);

   printf("%d\n", i);



   //---------------------------------------



   // Alterar "calc" para chamar a função "mul"
	//codigo[21] é o começo dos 4 bytes de endereço relativo em little endian

   	deslocamento = (int) ((long)&mul - (long)&codigo[25]);
   	memcpy (&codigo[21], &deslocamento, sizeof(int));


   //---------------------------------------



   // Chama a função "calc"

   f = (FuncPtr)codigo;

   i = f(10);

   printf("%d\n", i);



   return 0;

}
