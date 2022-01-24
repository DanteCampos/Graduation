#include <stdio.h>
#include <stdlib.h>

void ajeitaunidade (char**res, int n, int j);

int main (){
	
	int n,m,i,j;
	char *a=NULL,*b=NULL,**res=NULL;
	
	scanf ("%d %d",&n,&m);
	
	a = (char*) malloc (n*sizeof(char));
	b = (char*) malloc (m*sizeof(char));
	res = (char**) malloc ((n+1)*sizeof(char));
	for (i=0;i<n;i++) res[i] = (char*) malloc ((n+m)*sizeof(char));
	
	scanf ("%*c%s %s",a,b);
	
	for (i=0;i<n;i++) a[i] -= '0';
	for (i=0;i<m;i++) b[i] -= '0';
	for (i=0;i<n+1;i++){
		for (j=0;j<n+m;j++) res[i][j]=0;
	}
	
	for (i=n-1;i>=0;i--){
		for (j=m-1;j>=0;j--){
			res[i][j+n]=a[i]*b[j]%10;
			res[i][j+n-1]=a[i]*b[j]/10;
		}
	}
	
	for (j=0;j<n+m;j++){
		for (i=0;i<n;i++){
			res[n][j] += res[i][j];
			ajeitaunidade (res,n,j);
		}
	}
	
	for (j=0;j<n+m;j++) res[n][j] +='0';
	
	printf ("%s",res[n]);
	
	free(a);
	free(b);
	for (i=0;i<n+1;i++) free(res[i]);
	free(res);
	
	return 0;
}

void ajeitaunidade (char**res, int n, int j){
	if (res[n][j]<10) return;
	else{
		res[n][j-1] += res[n][j]/10;
		res[n][j] = res[n][j]%10;
		ajeitaunidade (res,n,(j-1));
	}
	return;
}
