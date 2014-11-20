#include <iostream>

using namespace std;

int power3(int num){
	return num*num*num;
}

int main(){
	for(int i=100;i<=999;i++){
		int temp = i / 10;
		int a = i % 10;
		int b = temp % 10;
		int c = temp / 10;

		if((power3(a)+power3(b)+power3(c))==i)
			cout<<i<<" ";
	}
}