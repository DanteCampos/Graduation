#include <stdio.h>
#define X 10
#define Y 320
int main (){
	
	int i,j,a,b,nlogo,nimg,logo[X][X],img[Y][Y];
	
	scanf ("%d",&nlogo);
	
	for (i=0;i<nlogo;i++){
		for (j=0;j<nlogo;j++) scanf ("%d",&logo[i][j]);
	}
	
	scanf ("%d",&nimg);
	
	for (i=0;i<nimg;i++){
		for (j=0;j<nimg;j++) scanf ("%d",&img[i][j]);
	}
	
	for (i=0;i<nimg-nlogo+1;i++){
		for (j=0;j<nimg-nlogo+1;j++){
			for (a=0;a<nlogo;a++){
				for (b=0;b<nlogo;b++){
					if (logo[a][b]!=img[i+a][j+b]) break;
				}
				if (b<nlogo) break;
			}
			if (a==nlogo){
				printf ("sim\n");
				return 0;
			}
		}
	}
	
	printf ("nao\n");
	return 0;
}
