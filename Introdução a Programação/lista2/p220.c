#include <stdio.h>

int main(){

	float renda;
	int familia,escola,cor;

	scanf ("%f %d %d %d",&renda,&familia,&escola,&cor);
	
	if ((escola == 2) && (cor == 4) && ((renda/familia) <= 1405.5)){
		printf ("ALUNO COTISTA (L1)");
	}else if ((escola == 2) && (cor < 4) && ((renda/familia) <= 1405.5)){
		printf ("ALUNO COTISTA (L2)");
	}else if ((escola == 2) && (cor == 4) && ((renda/familia) > 1405.5)){
		printf ("ALUNO COTISTA (L3)");
	}else if ((escola == 2) && (cor < 4) && ((renda/familia)> 1405.5)){
		printf ("ALUNO COTISTA (L4)");
	}else{
		printf ("ALUNO NAO COTISTA");
	}
	
	return 0;
}
