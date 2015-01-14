#include <iostream>

using namespace std;


bool isPrime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0)
			return false;
	}

	return true;
}

int cal(int n){
	int leftPrime,rightPrime;

	for(leftPrime=n;!isPrime(leftPrime);leftPrime--){}
	if(leftPrime <= 1)
		return 0;
	for(rightPrime=n;!isPrime(rightPrime);rightPrime++){}
	if(rightPrime > 1299709)
		return 0;

	return rightPrime - leftPrime;
}

int main(){
	int n;

	while((cin>>n) && (n!=0))
		cout<<cal(n)<<endl;

	return 0;
}