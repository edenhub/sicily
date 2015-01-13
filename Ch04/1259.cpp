#include <iostream>
#include <memory.h>

#define N 10001
using namespace std;

bool isPrime[N];

// 筛法生成素数列表
void initPrimeList(){
	memset(isPrime,true,sizeof(isPrime));

	isPrime[0] = isPrime[1] = false;
	for(int i=4;i<N;i+=2) 
		isPrime[i] = false;

	for(int i=3;i*i<N;i++){
		if(isPrime[i]){
			for(int j=i*i;j<N;j+=i){
				isPrime[j] = false;
			}
		}
	}
}

// 求连续素数和，注意第一个循环包含n
int calculateResult(int n){
	int res = 0;
	for(int i=2;i<=n;i++){
		if(isPrime[i]){
			int sum=0;
			for(int j=i;sum<=n;j++){
				if(isPrime[j]){
					sum+=j;
					if(sum==n){
						res++;
						break;
					}
				}
			}
		}
	}
	return res;
}

int main(){
	initPrimeList();
	int n;

	while((cin>>n) && (n!=0)){
		cout<<calculateResult(n)<<endl;
	}

	return 0;
}