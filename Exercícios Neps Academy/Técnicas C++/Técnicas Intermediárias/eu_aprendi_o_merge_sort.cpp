#include <iostream>
#include <vector>

using namespace std;

void merge_sort (vector <int> &vec){
	
	if (vec.size()<2) //vectors with just one element are already sorted
		return;
	
	vector <int> copy1, copy2;
	
	for (int i=0; i<vec.size()/2; i++)
		copy1.push_back(vec[i]);
	for (int i=vec.size()/2; i<vec.size(); i++)
		copy2.push_back(vec[i]);
	
	merge_sort(copy1);
	merge_sort(copy2);
	//at this point we can consider the 2 copys are already sorted
	
	int pos1=0, pos2=0;
	
	for (int i=0; i<vec.size(); i++){
	
		if (pos2 < copy2.size() and pos1 < copy1.size()){
			if (copy2[pos2] < copy1[pos1]){
				vec[i] = copy2[pos2];
				pos2++;
			}else{
				vec[i] = copy1[pos1];
				pos1++;
			}
		}else if (pos1 < copy1.size()){
			vec[i] = copy1[pos1];
			pos1++;
		}else{
			vec[i] = copy2[pos2];
			pos2++;
		}
	}
	
	return;
}

int main(){
	int size, aux;
	cin >>size;
	
	vector<int> vec;
	for (int i=0; i<size; i++){
		cin>>aux;
		vec.push_back(aux);
	}
	
	merge_sort(vec);
	
	for (int i=0; i<size; i++)
		cout<<vec[vec.size()-1-i]<<' ';
	
	return 0;
}
