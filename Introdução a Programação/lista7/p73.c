#include <stdio.h>
#include <stdlib.h>
#define quantpaises 24
#define tampais 30
#define tamfrase 50

int compara_string (char*a,char*b);

typedef struct natal{
	char *nome;
	char *frase;
}natal;

int main (){
	int i;
	char pais [tampais];
	natal v[quantpaises];
	
	for (i=0;i<quantpaises;i++){
		v[i].nome = (char*) malloc(tampais*sizeof(char));
		v[i].frase = (char*) malloc(tamfrase*sizeof(char));
	}
		
	v[0].nome="brasil";
	v[0].frase = "Feliz Natal!";
			
	v[1].nome= "alemanha";
	v[1].frase = "Frohliche Weihnachten!";

	v[2].nome= "austria";
	v[2].frase = "Frohe Weihnacht!";

	v[3].nome= "coreia";
	v[3].frase = "Chuk Sung Tan!";

	v[4].nome= "espanha";
	v[4].frase = "Feliz Navidad!";

	v[5].nome= "grecia";
	v[5].frase = "Kala Christougena!";

	v[6].nome= "estados-unidos";
	v[6].frase = "Merry Christmas!";

	v[7].nome= "inglaterra";
	v[7].frase = "Merry Christmas!";

	v[8].nome= "australia";
	v[8].frase = "Merry Christmas!";
		
	v[9].nome= "portugal";
	v[9].frase = "Feliz Natal!";

	v[10].nome= "suecia";
	v[10].frase = "God Jul!";

	v[11].nome= "turquia";
	v[11].frase = "Mutlu Noeller";

	v[12].nome= "argentina";
	v[12].frase = "Feliz Navidad!";

	v[13].nome= "chile";
	v[13].frase = "Feliz Navidad!";

	v[14].nome= "mexico";
	v[14].frase = "Feliz Navidad!";

	v[15].nome= "antardida";
	v[15].frase = "Merry Christmas!";

	v[16].nome= "canada";
	v[16].frase = "Merry Christmas!";

	v[17].nome= "irlanda";
	v[17].frase = "Nollaig Shona Dhuit!";

	v[18].nome= "belgica";
	v[18].frase = "Zalig Kerstfeest!";

	v[19].nome= "italia";
	v[19].frase = "Buon Natale!";
				
	v[20].nome= "libia";
	v[20].frase = "Buon Natale!";

	v[21].nome= "siria";
	v[21].frase = "Milad Mubarak!";
				
	v[22].nome= "marrocos";
	v[22].frase = "Milad Mubarak!";
				
	v[23].nome= "japao";
	v[23].frase = "Merii Kurisumasu!";
				
	while (scanf ("%s",pais)!=EOF){		
		for (i=0;i<quantpaises;i++){
			if (compara_string(pais,v[i].nome)==0){
				printf ("%s\n",v[i].frase);
				break;
			}
		}
		if (i==quantpaises) printf ("-- NOT FOUND --\n");
	}
	
	return 0;
}

//retorn 0 para strings iguais, retorna 1 para strings diferentes
int compara_string (char*a,char*b){
	int i;
	for (i=0;a[i]!='\0' && b[i]!='\0';i++){
		if (a[i]!=b[i]) return 1;
	}
	return 0;
}
