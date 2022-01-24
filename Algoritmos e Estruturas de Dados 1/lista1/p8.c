#include <stdio.h>
 
int main(){
    int n, a, i, c=0;
    
    scanf("%d", &n);
    
    while(n){
        c = 0;
        scanf("%d", &a);
        
        for(i=1; i<=a; i++){
        
            if(a%i == 0){
                c++;
            }
        }
        
        if(c == 2)printf("S\n");
        else printf("N\n");
        n--;
    }
    return 0;
}
