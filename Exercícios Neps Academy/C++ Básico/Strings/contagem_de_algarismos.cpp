#include <iostream>

using namespace std;

int main(){
	
	int n,numbers[10];
	
	cin>>n;
	cin.ignore();
	
	for(int i=0; i<10; i++)
		numbers[i]=0;
	

	
	while(n--){
		
		string line;
		getline(cin, line);
		
		for(int i=0; i<line.size();i++)
			if(line[i]>='0' and line[i]<='9')
				numbers[line[i]-'0']++;
	}
	
	for (int i=0;i<10;i++)
		cout<<i<<" - "<<numbers[i]<<endl;
	
	return 0;
}
