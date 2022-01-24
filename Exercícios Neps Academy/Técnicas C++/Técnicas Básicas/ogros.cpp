#include <iostream>

using namespace std;

int in_zone(int zones[], int size, int score){
	int start=0, end=size-1, middle;
	
	while (start < end){
		middle = (start+end)/2;
		if (score == zones[middle])
			return middle+1;
		else if (score < middle)
			end = middle;
		else
			start = middle;
	}
	
	
}

int main(){
	int n_zones, n_ogres;
	
	cin >>n_zones >>n_ogres;
	
	int prizes[n_zones];
	int zones[n_zones-1];
	
	for (int i=0; i<n_zones-1; i++)
		cin >>zones[i];
	
	for (int i=0; i<n_zones-1; i++)
		cin >>prizes[i];
	
	int ogre_score;
	for (int i=0; i<n_ogres; i++){
		cin>>ogre_score;
		cout<<prizes[in_zone(zones, n_zones-1, ogre_score)]<<' ';
	}
	
	return 0;
}
