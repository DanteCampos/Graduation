#include <iostream>

using namespace std;

int main(){
	int n,matrix[1000][1000], rowSum[1000], columnSum[1000];
	cin>>n;
	
	for (int i=0; i<n; i++){
		rowSum[i]=0;
		columnSum[i]=0;
	}
	
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>matrix[i][j];
			rowSum[i]+=matrix[i][j];
			columnSum[j]+=matrix[i][j];
		}
	}
	
	int max=0;

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			int sum = rowSum[i]+columnSum[j]-(2*matrix[i][j]);
			if (sum>max) max=sum;
		}
	}
	
	cout<<max;
	
	return 0;
}
