#include <iostream>
#include <string.h>
#define M 400
#define N 100
using namespace std;
/*
由于位数过长，int型不能表示
大数取模
*/

int main(){

	int T;
	cin>>T;
	int result[N];

	for(int t=0;t<T;t++){
		int n;
		cin>>n;
		
		int baseNum[N];
		for(int i=0;i<n;i++)
			cin>>baseNum[i];

		char veryLongIntChar[M];
		int veryLongInt[M];
		cin>>veryLongIntChar;
		int len=strlen(veryLongIntChar);
		for(int i=0;i<len;i++)
			veryLongInt[i] = veryLongIntChar[i] - '0';

		for(int i=0;i<n;i++){
			int d = 0;

			for(int j=0;j<len;j++)
			//模拟大数取模过程：当前的余数×10+下一位的数再模除数，值作为下一次的模		
			//转为long long防止溢出
				d = ((long long)d * 10 + veryLongInt[j]) % baseNum[i];

			result[i] = d;
		}

		cout<<"(";
		int u=0;
		for(;u<n-1;u++)
			cout<<result[u]<<",";
		cout<<result[u]<<")"<<endl;
	}

	return 0;
}
