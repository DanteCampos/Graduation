
#include <stdio.h>
#include <math.h>

int main (){
	
	int n,h,c1,c2;
	
	scanf ("%d",&n);
	
	
	for (h=2;h<=n;h++){
		for (c1=1;c1<h;c1++){
		
			c2=c1;
			
			for (c2=c1;((c2<h)&&(c2>=c1));c2++){
				
				if (h == sqrt (c1*c1+c2*c2)) printf ("hipotenusa = %d, catetos %d e %d", h, c1, c2);
				if (h == sqrt (c1*c1+c2*c2)) printf ("\n");
			}
		}
	}
	return 0;
}




	
	
	
