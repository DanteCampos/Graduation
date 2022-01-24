#include <iostream>

using namespace std;

int main(){
	int b,n, bancos[20];
	
	while (true){
		cin>>b>>n;
		if (b==0 and n==0) break;
		
		for (int i=0; i<b; i++) cin>>bancos[i];
		
		while(n--){
			int devedor, credor, valor;
			cin >>devedor >>credor >>valor;
			
			bancos[devedor-1] -= valor;
			bancos[credor-1] += valor;
		}
		
		int i;
		for (i=0; i<b; i++)
			if (bancos[i]<0) break;
		
		if (i == b) cout <<"S"<<endl;
		else cout<<"N"<<endl;
	}
	
	return 0;
}
