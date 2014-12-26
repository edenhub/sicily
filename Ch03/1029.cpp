#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>

#define N 1000

using namespace std;

string dA[N];

string dumpResult(int result[],int len){
	int indexNoZero =len;

	// for(int i=0;i<len;i++)
	// 	cout<<result[i];
	// cout<<endl;

	for(int i=len-1;i>=0;i--){
		if(result[i]!=0)
			break;
		indexNoZero--;
	}

	stringstream res;

	for(int i=indexNoZero-1;i>=0;i--)
		res<<result[i];
		// cout<<result[i];
	// cout<<endl;
	return res.str();
}

string plusC(string& strA,string& strB){
	if(strA[0] == '0' && strB[0] == '0'){
		// cout<<0<<endl;
		return "0";
	}
	int lenA = strA.length(),lenB = strB.length();
	int maxLen = lenA<=lenB ? lenB : lenA;

	int tempResult=0;

	int bigA[maxLen],bigB[maxLen],result[2*maxLen];
	memset(bigA,0,sizeof(bigA));
	memset(bigB,0,sizeof(bigB));
	memset(result,0,sizeof(result));

	for(int i=0;i<lenA;i++){
		bigA[i] = strA[lenA-i-1] - '0';
	}

	for(int i=0;i<lenB;i++){
		bigB[i] = strB[lenB-i-1] - '0';
	}

	for(int i=0;i<lenA || i<lenB;i++){
		tempResult = bigA[i] + bigB[i];
		if(result[i] + tempResult >= 10){
			result[i] = result[i] + tempResult - 10;
			result[i+1] += 1;
		}else{
			result[i] += tempResult;
		}
	}

	return dumpResult(result,2*maxLen);
}

int main(){

	int m,d;
	
	while((cin>>m>>d)&&(m!=0 && d!=0)){
		dA[0] = "1";
		for(int i=1;i<=d;i++){
			if(i<m){
				dA[i] = plusC(dA[i-1],dA[0]);
			}else{
				dA[i] = plusC(dA[i-1],dA[i-m]); 
			}
		}
		cout<<dA[d]<<endl;
	}

	return 0;
}