#include <iostream>
#include <memory.h>

#define N 8

using namespace std;

int result[N+1][N+1];

void bio(int n,int k){
	if(k==0 || k == n)
		result[n][k] = 1;
	else
		result[n][k] = result[n-1][k-1] + result[n-1][k];
}

int mini(int i,int j){
	return (i<j)?i:j;
}

int Bio(int n,int k){
	memset(result,0,sizeof(result));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=mini(i,k);j++)
			bio(i,j);
	}

	return result[n][k];
}

int main(){
	for(int i=0;i<=N;i++){
		cout<<Bio(N,i)<<endl;
	}

	return 0;
}