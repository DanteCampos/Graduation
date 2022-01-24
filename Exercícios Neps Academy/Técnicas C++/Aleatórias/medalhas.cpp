#include <iostream>
using namespace std;
int main(){
    int a,b,c, bronze, silver, gold;
 	cin >>a>>b>>c;
    if (a < b and a<c)
       gold = 1;
    else if (a <b or a<c)
        silver=1;
    else
        bronze=1;
    
     if (b < a and b<c)
        gold = 2;
    else if (b <a or b<c)
       silver = 2;
    else
        bronze = 2;
    
     if (c< a and c<b)
        gold = 3;
    else if (c <a or c<b)
       silver = 3;
    else
        bronze = 3;
    
    cout<<gold<<'\n'<<silver<<'\n'<<bronze;
    return 0;
}
