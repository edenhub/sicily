#include <algorithm>
#include <iostream>

using namespace std;

// 最大公约数: __gcd(a,b)
// 最小公倍数：a / __gcd(a,b) * b
int main(){

	cout<<__gcd(12,18)<<endl;
	cout<<(12/__gcd(12,18) *18)<<endl;

	return 0;
}