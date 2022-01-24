#include <iostream>

using namespace std;

bool isVowel(char func)
{
 
  if(func =='a')
           return 1;
  if(func =='e')
           return 1;
  if(func =='i')
           return 1;
  if(func =='o')
           return 1;
  if(func =='u')
           return 1;
  if(func =='A')
           return 1;
  if(func =='E')
           return 1;
  if(func =='I')
           return 1;
  if(func =='O')
           return 1;
  if(func =='U')
           return 1;
  else
          return 0;
}

int main(){
	string riso;
	cin>>riso;
	
	bool flag=true;
	
	int comeco=0, fim=riso.size()-1;
	while(true){
		if (comeco>=fim)
			break;
			
		if (!isVowel(riso[comeco]))
			comeco++;
		if (!isVowel(riso[fim]))
			fim--;
		
		if (isVowel(riso[comeco]) and isVowel(riso[fim])){
			if (riso[comeco]==riso[fim]){
				comeco++;
				fim--;
			}
			else{
				flag=false;
				break;
			}
		}
	}
	
	if (flag)
		cout<<"S";
	else
		cout<<"N";
	
	return 0;
}
