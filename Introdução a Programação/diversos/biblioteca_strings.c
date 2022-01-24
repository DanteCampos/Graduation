    #include <stdio.h>
     
    int size_str (char *str);
     
    int le_str(char*s){
        
        int i;
     
        scanf ("%[^\n]%*c",s);
        for (i=0;s[i]!='\0';i++);
        
        return i;
    }
     
    int str_cpy(char*a,char*c){
        
        int i;
        
        for (i=0;a[i]!='\0';i++) c[i]=a[i];
        
        return i;
    }
     
    int find_str (char*str,char*s){
        int i,j,tamanhostr,tamanhos,x;
        
        tamanhos = size_str (s);
        x=size_str (str)-tamanhos+1;
        
        for (i=0;i<x;i++){
            for (j=0;j<tamanhos;j++){
                if (str[i]!=s[j]) break;
            }
            
            if (j==tamanhos) return i;
        }
        
        if (i==x) return -1;
    }
     
    int size_str (char *str){
        
        int i;
        
        for (i=0;str[i]!='\n';i++);
        
        return i;
    }
     
    void upper_str (char*str){
        int i;
        
        for (i=0;str[i]!='\0';i++){
            if (str[i]>='a'&&str[i]<='z') str[i]-=('a'-'A');
        }
    }
     
    void low_str (char*str){
        int i;
        
        for (i=0;str[i]!='\0';i++){
            if (str[i]>='A'&&str[i]<='Z') str[i]+=('a'-'A');
        }
    }
     
    int str2int (char*str){
        int i,pot=1,x=0;
     
        for (i=0;str[i]!='\0';i++){
            if (str[i]>='0'&&str[i]<='9') pot*=10;
        }
        
        pot/=10;
        
        if (str[0]=='-')i=1;
        else i=0;
        
        for (i;str[i]!='\0';i++){
            x+=(str[i]-'0')*pot;
            pot/=10;
        }
        
        if (str[0]=='-')x=-x;
        
        return x;
    }
     
    double str2double (char*str){
        double x=0,pot=0.1;
        int i;
        
        if (str[0]=='-') i=1;
	else i=0;
        
        for (i;str[i]!='.'&&str[i]!='\0';i++) pot*=10;
        
        for (i=0;str[i]!='\0';i++){
            if (str[i]=='.'||str[i]=='-') continue;
            x+=(str[i]-'0')*pot;
            pot/=10;
        }
        
        if (str[0]=='-')x=-x;
        
        return x;
    }
     
    void set_str (char*str, int N, char c){
        int i;
        
        for (i=0;i<N;i++) str[i]=c;
    }
