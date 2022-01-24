#include <iostream>

using namespace std;

int max(int a, int b){
	if (a > b)
		return a;
	else
		return b;
}

int min(int a, int b){
	if (a < b)
		return a;
	else
		return b;
}

int main(){
	int n_dives, tape_length;
	cin >>n_dives >>tape_length;
	
	long int actual_dive, last_dive, sum_dives;
	
	cin>>actual_dive;
	sum_dives = last_dive = min(actual_dive, (tape_length - actual_dive));
	
	for (int i=1; i<n_dives; i++){
		
		cin >> actual_dive;
			
		//There's two solutions, we pick the smaller
		if (min(actual_dive, (tape_length - actual_dive)) >= last_dive)
			actual_dive = min(actual_dive, (tape_length - actual_dive));
			
		//There's one solution, we pick it
		else if (max(actual_dive, (tape_length - actual_dive)) >= last_dive)
			actual_dive = max(actual_dive, (tape_length - actual_dive));
		
		//There's no solution, we flag it
		else
			sum_dives = -1;
		
		//passing to the foward iteration
		if (sum_dives != -1) //if there's no solution, just stop adding
			sum_dives += actual_dive;
		last_dive = actual_dive;
	}
	
	cout<<sum_dives<<endl;
	
	return 0;
}
