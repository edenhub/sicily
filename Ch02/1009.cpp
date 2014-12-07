#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// 求给定p小于梅森素数的数的因式分解

// 小于63的梅森素数
int Mn[9] = {11,23,29,37,41,43,47,53,59};

// 平时判断是否为素数
bool isPrime(int x){
	for(int i=2;i*i<=x;i+=2){
		if(x % i == 0)
			return false;
	}

	return true;
}

// 因式分解
void expli(int p){
	long long num = (1LL << p) - 1,n = num;
	// long long num = pow(2,p) - 1,n = num;
	// 同一个因子可能出现多次
	vector<pair<long long ,int> > ans;
	int temp;

	// 每个因子必定为素数，用找素数的主题求因子
	for(long long i=3;i*i<=num;i++){
		temp = 0;

		while(num%i==0){
			num /= i;
			temp++;
		}

		if(temp!=0){
			ans.push_back(make_pair(i,temp));
		}
	}
	// 如果最后没有除尽，则把剩余的加进去
	if(num>1) ans.push_back(make_pair(num,1));

	for(int i=0;i<ans.size();i++){
		if(i != 0) cout<<" * ";
		for(int j=0;j<ans[i].second;j++){
			if(j != 0) cout<<" * ";
			cout<<ans[i].first;
		}
	}

	cout<<" = "<<n<<" = ( 2 ^ "<<p<<" ) - 1"<<endl;
}

void cal(int n){
	for(int i=0;i<9;i++){
		if(Mn[i] < n){
			expli(Mn[i]);
		}
	}
}

int main(){
	// 直接获取输入，不用操作文件
	int p;
	cin>>p;
	cal(p);

	return 0;
}