#include <iostream>
#include <cstring>

using namespace std;


long long function(long long n, long long k, long long m, long long *coef, long long *values){
	if (k<=n || values[k] != -1)
		return values[k];
	
	//here we have to calculate function(k)
	long long  sum=0;
	for (long long i=1; i<=n; i++)
		sum += (coef[i]*function(n, k-i, m, coef, values))%m;
	
	sum%=m;
	return values[k]=sum;
}


int main(){
	long long n,k,m;
	cin >>n >>k >>m;
	
	long long coef[n+1];
	long long values[k+1];
	
	memset (values, -1, sizeof(values));
	
	for(long long i=1; i<=n; i++)
		cin >>coef[i];
	
	for (long long i=1; i<=n; i++)
		cin >>values[i];
	
	cout <<function(n, k, m, coef, values);
	
	/*
	for (long long i=n; i<k; i++){
		long long sum=0;
		for (long long j=0; j<n; j++)
			sum+=(coef[j]*values[i-1-j])%m;
		values[i]=sum;
	}
	
	cout<<values[k-1];
	*/
	
	//DEBUG:
	/*
	cout <<'\n';
	for (int i=0; i<k; i++)
		cout <<values[i]<<' ';
	*/
	
	return 0;
}

