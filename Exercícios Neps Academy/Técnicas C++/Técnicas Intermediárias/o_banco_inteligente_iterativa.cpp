#include <bits/stdc++.h>

#define N_NOTES 6

using namespace std;

int dp[5001][N_NOTES+1][510];

int main(){
	// memset(dp,-1,sizeof dp);
	int value, notes[N_NOTES], note_values[N_NOTES]={2,5,10,20,50,100};
	
	cin >>value;
	
	for (int i=0; i<N_NOTES; i++)
		cin >>notes[i];
	dp[0][0][0]=1;
	for (int i = 0; i < N_NOTES; ++i)
	{
		for (int j = 0; j <= notes[i]; ++j)
		{
			for (int k = 0; k <=value; ++k)
			{	
				if(k+note_values[i]<=5000)
					dp[k+note_values[i]][i][j+1]+= dp[k][i][j];
				dp[k][i+1][0]+=dp[k][i][j];
			}
		}
	}
	cout << dp[value][6][0];
	
	return 0;
}
