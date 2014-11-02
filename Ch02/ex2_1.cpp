#include <iostream>

using namespace std;
/*
将数组设计到128，减少中间操作
*/
int main(){
	int sum[128]={0};
	char ch;
	while((cin>>ch) && (ch!='?'))
		sum[ch]++;

	for(char i='a';i<='z';i++)
		cout<<i<<" : "<<sum[i]<<endl;

	return 0;
}