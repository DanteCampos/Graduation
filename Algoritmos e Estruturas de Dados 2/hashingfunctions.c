#include <math.h>
#include <stdio.h>

int somaFazendoResto (int a, int b){
	int j, c=0;
	for (j=10; a/(j/10) != 0 || b/(j/10) != 0; j*=10){
		c+= ((((a/(j/10))%10)+((b/(j/10))%10))%10)*(j/10);
	}
	return c;
}

int dezElevadoA(int a){
	int i;
	for (i=1; a>0; i*=10) a--;
	return i;
}

void inverteNumero (int *a, int digitosDesejados){
	int b=0, j, i=dezElevadoA(digitosDesejados);
	
	for (j=10; i > 0; j*=10){
		b+= (((*a)/(j/10))%10)*(i/10);
		i/=10;
	}
	
	*a=b;
	return;
}

int hashRestoTam(int chave, int tamanhohash){
	return chave%tamanhohash;
}

int achaProximoPrimo (int a){
	int teto = a, divisor = 2;
	if (a < 4) return a;
	if (a%2 == 0) a++; //a será ímpar
	
	//a é o primo que iremos retornar
	//o divisor estará sempre entre 2 e raiz de a
	//só retorna quando o divisor for maior ou igual a raiz de a e não divida a
	
	//o primo vai crescendo de 2 em 2 pra continuar ímpar
	teto = ((int) ceil(sqrt(a))); //todos os divisores de n menores que n são menores que raiz de n
	for (divisor = 2; divisor <= teto; divisor++){
		if (a%divisor == 0){
			a+=2;
			teto = ((int) sqrt(a));
			divisor = 2;
		}
	}
	
	//chegou aqui só depois de não achar nenhum divisor (entre 2 e raiz de a) de a
	//logo, a é primo
	
	return a;
}

int hashDobra (int chave, int digitosAtuais, int digitosFinais){
	int i, j, a, b, d, dobras, qa, qb;
	
	while (digitosAtuais > digitosFinais){
	
		d = dezElevadoA(digitosAtuais-digitosFinais);//ponto de separação da dobra
		a = chave/d;//lado esquerdo da dobra
		b = chave%d;//lado direito da dobra
		
		inverteNumero (&a, digitosFinais);
		
		qa = digitosFinais;//quantidade de dígitos de a
		qb = digitosAtuais-digitosFinais;//quantidade de digitos de b
		//igualando os dígitos de a e b:
		if (qb > qa) a*=dezElevadoA(qb-qa);
		else b*=dezElevadoA(qa-qb);
		
		chave = somaFazendoResto (a, b); //soma dígito a dígito, fazendo resto por 10
		digitosAtuais-=digitosFinais;
	}
	
	return chave;
}


int main (){
	int digitosfinal, digitosinicial, n,a,b;
	
	printf ("Digitos inicial, Digitos final, chave:\n");
	scanf ("%d %d %d",&digitosinicial, &digitosfinal, &n);
	printf ("HASH: %d",hashDobra(n, digitosinicial, digitosfinal));
	
	return 0;
}
