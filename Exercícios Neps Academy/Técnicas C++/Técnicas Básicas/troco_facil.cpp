#include <iostream>

using namespace std;

int main(){
	int money_value[6]={1,5,10,25,50,100};
	int change;
	
	cin>>change;
	
	int money_count=0;
	for (int i=6-1; i>=0; i--){
		if (change<=0)
			break;
		money_count += change/money_value[i];
		change -= (change/money_value[i])*money_value[i];
	}
	
	cout<<money_count;
	
	return 0;
}
