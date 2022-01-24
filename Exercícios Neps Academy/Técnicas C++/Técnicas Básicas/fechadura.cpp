#include <iostream>
#include <algorithm>

using namespace std;

int action (int *locks, int primary_position, int secondary_position, int height){
	int moves, signal;
	
	if (locks[primary_position] > height)
		signal=-1;
	else
		signal = 1;
		
	moves = (-signal)*locks[primary_position] + (signal)*height;
	locks[primary_position] = height;
	locks[secondary_position] += (signal)*moves;
	
	return moves;
}

int main (){
	int n_locks, height;
	cin>>n_locks >>height;
	
	//reading the locks
	int locks[n_locks];
	for (int i =0; i<n_locks; i++)
		cin>>locks[i];
	
	//moving the extremes first, then the middles after
	int moves=0;
	for (int i =0; i<n_locks/2; i++){
		moves += action(locks, i, i+1, height);
		moves += action(locks, n_locks-i-1, n_locks-i-2, height);
	}
	
	/*
	//printing the locks now
	cout <<"THE LOCKS NOW:"<<endl;
	for (int i=0; i<n_locks; i++)
		cout <<locks[i]<<' ';
	cout<<endl;
	
	cout<<"MOVES: ";
	*/
	
	cout<<moves;
	
	return 0;
}
