#include <iostream>

using namespace std;

int pow(int a, int n){
	int result=1;
	for (int i=0; i<n; i++)
		result*=a;
	return result;
}

int Hanoi(int discs){
	if (discs==1)
		return 1;
	else
		return Hanoi(discs-1) + Hanoi(discs-1) + 1;
}


int main (){
	int test=1, n;
	
	while (true){
		cin>>n;
		if (n==0)
			break;
		
		cout<<"Teste "<<test<<endl;
			
		cout<<(pow(2,n)-1)<<endl<<endl;
		
		test++;
	}
	
	return 0;
}
