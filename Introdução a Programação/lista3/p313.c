#include <stdio.h>

int main (){
	
	int a,np,ni,mp,mi;
	
	np=ni=mp=mi=0;
	
	while (1){
	
		scanf ("%d",&a);
	
		if (a==0) break;
	
		if (a%2==0){
	
			mp+=a;
			np++;
		
		}else{
		
			mi+=a;
			ni++;
		
		}

	}
		
	if (np==0) np=1;
	if (ni==0) ni=1;
		
	printf ("MEDIA PAR: %.6lf\n",((double)mp/np));
	printf ("MEDIA IMPAR: %.6lf",((double)mi/ni));
	
	return 0;
}


