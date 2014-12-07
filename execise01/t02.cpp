#include <iostream>

using namespace std;

char up(char ch){
	if(ch>=97 && ch<=122){
		return (ch - 32);
	}else{
		return ch;
	}
}

int main(){
	return 0;
}