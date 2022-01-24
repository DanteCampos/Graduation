#include <iostream>

using namespace std;

bool isLetter (char c){
	if ((c>='a' and c<='z') or (c>='A' and c<='Z'))
		return true;
	else
		return false;
}

void upperCase(char &c){
	if (!isLetter(c))
		c = 0;
	else if (c>='a' and c<='z')
		c = c-'a'+'A';
	
	return;
}

void lowerCase(char &c){
	if (!isLetter(c))
		c = 0;
	else if (c>='A' and c<='Z')
		c = c-'A'+'a';
	
	return;
}

string title(string F){
    int i, size = F.size();
    bool firstLetter=true;
    
    for (i=0;i<size;i++){
    	if (!isLetter(F[i]))
    		//is not a letter
    		firstLetter=true;
   		else{
   			//is a letter
   			if (firstLetter){
   				//is in the first letter of the word
   				upperCase(F[i]);
   				firstLetter=false;
   			}else{
   				//is not in the first letter of the word
   				lowerCase(F[i]);
   			}
   		}
   	}
   	
   	return F;
}

int main(){ 
    string F;

    getline(cin, F);

    cout << title(F) << "\n";
}
