#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

string dumpResult(int result[],int len){
	int indexNoZero =len;

	for(int i=len-1;i>=0;i--){
		if(result[i]!=0)
			break;
		indexNoZero--;
	}

	string out="";

	for(int i=indexNoZero-1;i>=0;i--){
		out+=result[i]+'0';
	}

	return out;
}

string plusC(string& strA,string& strB){
	if(strA[0] == '0' && strB[0] == '0'){
		cout<<0<<endl;
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

string multipleC(string& strA,string& strB){
	if(strA[0] == '0' || strB[0] == '0'){
		cout<<0<<endl;
		return "0";
	}

	int lenA = strA.length(),lenB = strB.length();
	int totalLen = lenA+lenB+1;
	int result[totalLen];
	memset(result,0,sizeof(result));

	int numA,numB,numTemp;
	
	reverse(strA.begin(),strA.end());
	reverse(strB.begin(),strB.end());

	int indexA,indexB,resultTemp;

	for(int i=0;i<lenA;i++){
		numA = strA[i] - '0';
		indexA = i;
		for(int j=0;j<lenB;j++){
			indexB = indexA + j;
			numB = strB[j] - '0';

			numTemp = numA * numB;
			while(numTemp!=0){
				resultTemp = numTemp%10;

				if(result[indexB] + resultTemp >= 10){
					result[indexB + 1] += 1;
					result[indexB] = result[indexB] + resultTemp - 10;
				}else{
					result[indexB] += resultTemp;
				}
				indexB++;
				numTemp /= 10;
			}
		}
	}

	return dumpResult(result,totalLen);
}

int main(){

	int testCase;
	cin>>testCase;

	for(int i=0;i<testCase;i++){
		int n;
		string v,sum="0";
		cin>>n>>v;
		for(int j=0;j<=n;j++){
			string a,temp=v;
			cin>>a;
			if(a[0]!='0'){

				if(n-j != 0)
					for(int k=n-j;k>1;k--){
						temp = multipleC(temp,v);
				}else{
					temp = "1";
				}
				
				temp = multipleC(temp,a);
				sum = plusC(temp,sum);
			}
		}

		cout<<sum<<endl;
	}
	
	return 0;
}