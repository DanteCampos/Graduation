#include <iostream>
#include <algorithm>

using namespace std;

struct Country{
	int id;
	int gold=0;
	int silver=0;
	int bronze=0;
};

bool compare_country (Country A, Country B){
	if (A.gold > B.gold)
		return true;
	else if (A.gold < B.gold)
		return false;
	else{
		if (A.silver > B.silver)
			return true;
		else if (A.silver < B.silver)
			return false;
		else{
			if (A.bronze > B.bronze)
				return true;
			else if (A.bronze < B.bronze)
				return false;
			else{
				if (A.id < B.id)
					return true;
				else
					return false;
			}
		}
	}
}

int main(){
	int n,m;
	
	cin >>n>>m;
	
	Country countries[n];
	
	for(int i=0; i<n; i++){
		countries[i].id=i+1;
	}
	
	while(m--){
		int g,s,b;
		cin >>g>>s>>b;
		countries[g-1].gold++;
		countries[s-1].silver++;
		countries[b-1].bronze++;
	}
	
	sort(countries, countries+n, compare_country);
	
	for (int i=0;i<n;i++)
		cout<<countries[i].id<<' ';
	
	return 0;
}
