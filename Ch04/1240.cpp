#include <iostream>
#include <math.h>
using namespace std;

// 秒表没有4，从4后面的数都要减1，相当于9进制
// 不知道为什么一定要先判断大于4
int toOdim(string str){
	int len = str.length();
	int res = 0;
	for(int i=len-1;i>=0;i--){
		int item = str[i] - '0';

		if(item>4) item--;
		res += item*pow(9,len-i-1);
	}

	return res;
}

int main(){

	string str;

	while((cin>>str) && (str[0] != '0')){
		cout<<str<<": "<<toOdim(str)<<endl;
	}

	return 0;
}