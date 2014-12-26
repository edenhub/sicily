#include <iostream>
#include <memory.h>

#define N 1000
using namespace std;



int cal(int str[],int n){
	int cnt = 0;

	while(str[n - 1] % 2 == 0){
		cnt++;

		for(int i=0,temp=0;i<n;i++){
			temp = temp*10+str[i];
			str[i] = temp/2;
			temp%=2;
		}
	}

	return cnt+1;
}

int main(){
	int testCase;
	cin>>testCase;

	for(int i=0;i<testCase;i++){
		string str;
		cin>>str;
		int arr[N],n = str.length();

		for(int j=0;j<n;j++){
			arr[j]  = str[j] - '0';
		}
		cout<<"Case "<<(i+1)<<": "<<cal(arr,n)<<endl;
		if(i<testCase-1)
			cout<<endl;

	}

	return 0;
}