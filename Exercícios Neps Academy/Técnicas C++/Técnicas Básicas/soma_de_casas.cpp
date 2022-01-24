#include <iostream>

using namespace std;

int main(){
	int n;
	cin >>n;
	
	int houses[n];
	for (int i=0; i<n; i++)
		cin >>houses[i];
	
	int sum;
	cin >>sum;
	
	int i,j;
	for (i=0; i<n-1; i++){ //binary search the complement of each number
		int start = i+1;
		int end = n-1;
		
		while (start<=end){
			j=(start+end)/2;
			
			if (houses[i]+houses[j] == sum) //found the numbers i and j that sums the "sum"
				break;
			else if (sum-houses[i] < houses[j]) //complement is in left zone
				end=j-1;
			else
				start=j+1; //complement is in right zone 
		}
		
		if (houses[i]+houses[j] == sum){
			cout <<houses[i] <<' ' <<houses[j];
			return 0;
		}
		
	}
	
	
	return 0;
}
