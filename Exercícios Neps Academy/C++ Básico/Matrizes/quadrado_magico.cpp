#include <iostream>

using namespace std;

int main(){
	int n, matrix[10][10];
	
	cin>>n;
	
	for (int i=0; i < n; i++)
		for (int j=0; j<n; j++)
			cin>>matrix[i][j];
	
	int sum=0;	
	for (int j=0; j<n; j++)
		sum+=matrix[0][j];
	
	for (int i =0; i<n; i++){
	
		int columSum=0, rowSum=0;
		
		for (int j=0;  j<n; j++){
			rowSum+=matrix[i][j];
			columSum+=matrix[j][i];
		}
		
		if (rowSum!= sum or columSum!=sum){
			cout <<-1;
			return 0;
		}
	}

	int diagonalSum1=0, diagonalSum2=0;
	for (int i=0;i<n;i++){
		diagonalSum1+=matrix[i][i];
		diagonalSum2+=matrix[n-1-i][i];
	}
	
	if (diagonalSum1!=sum or diagonalSum2!=sum){
		cout<<-1;
		return 0;
	}
	
	cout<<sum;
	return 0;
}
