#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void  maxPrice(int num){
	vector<int> prices;
	for(int i=0;i<num;i++){
		// cin>>prices[i];
		int p;
		cin>>p;
		prices.push_back(p);
	}

	sort(prices.begin(),prices.end());

	int max = 0;
	for(int i=prices.size()-3;i>=0; i-=3){
		max += prices[i];
	}

	cout<<max<<endl;
}

int main(){

	int testCase;
	cin>>testCase;

	for(int i=0;i<testCase;i++){
		int num;
		cin>>num;
		maxPrice(num);
	}

	return 0;
}