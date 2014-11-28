#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

void calculate(string& a,int b){

	if(a[0] == '0' || b == 0 ){
		cout<<0<<endl;
		return ;
	}

	int lenA = a.length(),lenRes = lenA+6;
	int result[lenRes];
	int temp,tempCal,tempAdd,indexRes;

	memset(result,0,sizeof(result));
	reverse(a.begin(),a.end());

	for(int i=0;i<lenA;i++){
		temp = a[i] - '0';
		tempCal = temp * b;

		indexRes = i;

		while(tempCal!=0){
			tempAdd = tempCal % 10;
			if(tempAdd + result[indexRes] >= 10){
				result[indexRes] = tempAdd + result[indexRes] - 10;
				result[indexRes+1] += 1;
			}else{
				result[indexRes] += tempAdd;
			}

			indexRes++;
			tempCal /= 10;
		}
	}

	// for(int i=0;i<lenRes;i++){
	// 	cout<<result[i];
	// }
	// cout<<endl;

	int indexNoZero = lenRes;
	for(int i=lenRes-1;i>=0;i--){
		indexNoZero--;
		if(result[i]!=0){
			break;
		}
	}
	// cout<<indexNoZero<<endl;
	for(int i=indexNoZero;i>=0;i--)
		cout<<result[i];
	cout<<endl;

}

int main(){
	int testCase;
	cin>>testCase;
	string a;
	int b;

	for(int i=0;i<testCase;i++){
		cin>>a>>b;
		calculate(a,b);
	}
	return 0;
}