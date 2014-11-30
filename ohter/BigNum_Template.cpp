#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

void dumpResult(int result[],int len){
	int indexNoZero =len;

	// for(int i=0;i<len;i++)
	// 	cout<<result[i];
	// cout<<endl;

	for(int i=len-1;i>=0;i--){
		if(result[i]!=0)
			break;
		indexNoZero--;
	}

	for(int i=indexNoZero-1;i>=0;i--)
		cout<<result[i];
	cout<<endl;
}

void dumpResultForMinus(int result[],int len,bool isNegative){
	if(isNegative){
		cout<<"-";
	}

	dumpResult(result,len);
}

void plusC(string& strA,string& strB){
	if(strA[0] == '0' && strB[0] == '0'){
		cout<<0<<endl;
		return;
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

	dumpResult(result,2*maxLen);
}

void minusPlace(int result[],int start){
	if(result[start]==0){
		result[start+1] -= 1;
		minusPlace(result,start+1);
	}
}

void minusCMain(string& first,string& second,bool isNegative){
	int lenA = first.length(),lenB = second.length();
	int bigA[lenA],bigB[lenA],result[lenA];

	int numA,numB,tempResult = 0;

	memset(bigA,0,sizeof(bigA));
	memset(bigB,0,sizeof(bigB));
	memset(result,0,sizeof(result));


	for(int i=0;i<lenA;i++){
		bigA[i] = first[lenA-i-1] - '0';
	}

	for(int i=0;i<lenB;i++){
		bigB[i] = second[lenB-i-1] - '0';
	}

	for(int i=0;i<lenA || i<lenB ;i++){
		numA = bigA[i];
		numB = bigB[i];
		if(numA < numB){
			bigA[i+1] -= 1;
			minusPlace(result,i+1);
			result[i] = numA+10 - numB;
		}else{
			result[i] = numA - numB;
		}
	}

	dumpResultForMinus(result,lenA,isNegative);

}

void minusC(string& strA,string& strB){
	int lenA = strA.length(),lenB = strB.length();

	if(lenA < lenB){
		minusCMain(strB,strA,true);
	}else if(lenA > lenB){
		minusCMain(strA,strB,false);
	}else{
		int count = 0;
		for(int i=lenA-1;i>=0;i--){
			if((strA[i] - strB[i]) > 0)
				minusCMain(strA,strB,false);
			else if((strA[i] - strB[i]) < 0)
				minusCMain(strB,strA,true);
			else
				count++;
		}
		if(count == lenA)
			cout<<0<<endl;
	}
}
void divideC(string& strA,string& strB){}
void modC(string& strA,string& strB){}
void powerC(string& strA,string& strB){}

void multipleC(string& strA,string& strB){
	if(strA[0] == '0' || strB[0] == '0'){
		cout<<0<<endl;
		return;
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

	dumpResult(result,totalLen);
}

int main(){
	int testCase;
	string a,b;

	cin>>testCase;

	for(int i=0;i<testCase;i++){
		cin>>a>>b;
		multipleC(a,b);
	}
	return 0;
}