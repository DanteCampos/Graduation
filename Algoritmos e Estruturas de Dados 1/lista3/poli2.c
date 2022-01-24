#include <stdio.h>
#include <stdlib.h>

int main (){
	int i,t,n,k,a,maxa,b,maxb,ladroes,l,j;
	char **m;
	
	scanf ("%d",&t);
	
	for (i=0;i<t;i++){
		scanf ("%d %d",&n,&k);
		ladroes=0;
		
		m=(char**) malloc (n*sizeof(char*));
		for (j=0;j<n;j++) m[j] = (char*) malloc (n*sizeof(char));
		
		for (j=0;j<n;j++){
			for (l=0;l<n;l++) scanf ("%*c%c",&m[j][l]);
		}
		
		for (j=0;j<n;j++){
			for (l=0;l<n;l++){
				if (m[j][l]=='D'){
					a=(j-k<0)?0:j-k;
					maxa=(j+k+1>n)?n:j+k+1;
					
					b=(l-k<0)?0:l-k;
					maxb=(l+k+1>n)?n:l+k+1;
					
					while (a<maxa || b<maxb){
						if (a<maxa){
							if (m[a][l]=='L'){
								m[a][l]='X';
								ladroes++;
								break;
							}
						}
						
						if (b<maxb){
							if (m[j][b]=='L'){
								m[j][b]='X';
								ladroes++;
								break;
							}
						}
						
						a++;
						b++;
					}
				}
			}
		}
		
		
		for (j=0;j<n;j++) free(m[j]);
		free(m);
		printf ("%d\n",ladroes);
	}
	return 0;
}
