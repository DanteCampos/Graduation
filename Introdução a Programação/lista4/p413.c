    #include <stdio.h>
     
     
    void pbyte (unsigned char pc);
    void print_bytes (const void *end,int n);
     
    int main (){
     
        unsigned char ch;
        unsigned short sh;
        unsigned int nt;
        float fl;
        double dl;
        
        scanf ("%lf",&dl);
        
        ch=sh=nt=fl=dl;
        
        print_bytes (&ch,sizeof(char));
        print_bytes (&sh,sizeof(short));
        print_bytes (&nt,sizeof(int));
        print_bytes (&fl,sizeof(float));
        print_bytes (&dl,sizeof(double));
        
        return 0;
    }
     
    void print_bytes (const void *end,int n){
     
        unsigned int i;
        unsigned char *pc = (unsigned char*)end;
        
        for (i=0;i<n;i++){
            
		printf ("%u",*pc);
            pc++;
            printf (",");
        }
     
        printf ("\n");
     
    }
