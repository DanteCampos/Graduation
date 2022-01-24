#include <stdio.h>

int main (){
	
	int n,i,j,nmais=0,imais=0,imaisrel=0,nmaisrel=0;
	
	scanf ("%d",&n);
	
	int v[n];
	
	for (i=0;i<n;i++) scanf ("%d",&v[i]);
	
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			if (v[i]==v[j]){
				nmaisrel=v[i];
				imaisrel++;
			}
		}
		if (imaisrel>imais){
			nmais=nmaisrel;
			imais=imaisrel;
		}else if (imaisrel==imais){
			if (nmaisrel<nmais) nmais=nmaisrel;
		}
		
		imaisrel=0;
	}
	
	printf ("%d\n",nmais);
	printf ("%d\n",imais);
	
	return 0;
}
