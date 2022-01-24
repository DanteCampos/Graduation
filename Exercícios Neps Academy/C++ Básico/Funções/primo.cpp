#include <iostream>
#include <cmath>

using namespace std;

bool eh_primo(int x){
	if (x<2)
		return false;
	int limit = sqrt(x)+1;
	
	for (int d=2; d<limit; d++){
		if (x%d == 0)
			return false;
	}
	
	return true;
}

int main(){
    int x;

    cin>>x;

    if(eh_primo(x)){
        cout << "S" << "\n";
    }else{
        cout << "N" << "\n";
    }
}
