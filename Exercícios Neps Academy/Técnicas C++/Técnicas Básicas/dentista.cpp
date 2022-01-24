#include <iostream>
#include <algorithm>

using namespace std;

struct Patient{
	int start;
	int end;
};

bool compare_patients(Patient A, Patient B){
	return A.end<B.end;
}

int main(){
	int n_patients;
	cin>>n_patients;
	
	Patient patients[n_patients];
	for (int i=0; i< n_patients; i++)
		cin>>patients[i].start >>patients[i].end;

	sort(patients, patients+n_patients, compare_patients);
	
	int time = patients[0].start;
	int count = 0;
	for (int i = 0; i < n_patients; i++){
		if (time > patients[i].start)
			continue;
		else{
			time = patients[i].end;
			count++;
		}
	}
	
	cout <<count;
	
	return 0;
}
