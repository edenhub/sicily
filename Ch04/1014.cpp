#include <iostream>

using namespace std;

int sum_base(int n,int base){
	int sum=0;

	for(;n>0;n/=base){
		sum += n % base;
	}

	return sum;
}

bool check(int n){
	return sum_base(n,10) == sum_base(n,12) && sum_base(n,12) == sum_base(n,16);
}
int main(){
	for(int i=2992;i<=9999;i++){
		if(check(i))
			cout<<i<<endl;
	}

	return 0;
}