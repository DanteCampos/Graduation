#include <iostream>
#include <algorithm>

using namespace std;

struct Driver{
	int id;
	int score=0;
};

void make_score (Driver drivers[], int score_system[], int races[][100], int n_races, int n_drivers, int n_positions){
	for (int i=0; i<n_races; i++){
		for (int j=0; j<n_drivers; j++){
			
			int driver_j_position = races[i][j];
			
			if (driver_j_position<=n_positions)
				drivers[j].score += score_system[driver_j_position-1];
		}
	}
	
	return;
}

bool compare_drivers(Driver A, Driver B){
	if (A.score > B.score)
		return true;
	else if (A.score < B.score)
		return false;
	else{
		if (A.id < B.id)
			return true;
		else
			return false;
	}
}

int main(){
	
	while(true){
		int g,p;
		cin>>g>>p;
		
		if (g==0 and p==0)
			break;

		int races[g][100];
		
		for (int i=0;i<g;i++)
			for(int j=0; j<p; j++)
				cin>>races[i][j];
		
		int systems;
		cin>>systems;
		
		while(systems--){
			int n_positions;
			cin>>n_positions;
			
			int score_system[n_positions];
			for (int i=0; i<n_positions; i++)
				cin >>score_system[i];
			
			Driver drivers[p];
			for (int i=0; i<p; i++)
				drivers[i].id=i+1;
			
			make_score (drivers, score_system, races, g, p, n_positions);
			
			sort(drivers, drivers+p, compare_drivers);
			
			int first_score = drivers[0].score;
			for (int i=0; i<p and drivers[i].score == first_score; i++)
				cout<<drivers[i].id<<' ';
			
			cout<<endl;
				
		}
	}
	
	return 0;
}
