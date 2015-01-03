#include <iostream>
#include <cstdio>
#include <memory.h>

#define N 1000

using namespace std;

int amount[N],temp[N];


bool allsame(int n){
	for(int i=0;i<n;i++){
		if(amount[i] != amount[(i+1)%n])
			return false;
	}

	return true;
}

void caucl(int n){
	int r = 0;

	for(;!allsame(n);r++){
		for(int i=0;i<n;i++){
			temp[i] = amount[i] = amount[i] /2 ;
		}

		for(int i=0;i<n;i++){
			amount[(i+1)%n] += temp[i];
			amount[(i+1)%n] += amount[(i+1)%n] % 2;
		}
	}

	printf("%d %d\n",r,amount[0]);

}

int main(){

	int t;
	while((cin>>t)&&(t!=0)){
		memset(amount,0,sizeof(amount));
		memset(temp,0,sizeof(temp));

		for(int i=0;i<t;i++)
			cin>>amount[i];

		caucl(t);
	}

	return 0;
}