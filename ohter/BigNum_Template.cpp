#include <iostream>
#include <memory.h>
#include <algorithm>

#define LA 1000
#define LB 1000

using namespace std;

int result[LA+LB+1];

void plus(string& strA,string& strB){}
void minus(string& strA,string& strB){}
void divide(string& strA,string& strB){}
void mod(string& strA,string& strB){}

void multiple(string& strA,string& strB){
	if(strA[0] == '0' || strB[0] == '0'){
		cout<<0<<endl;
		return;
	}

	memset(result,0,sizeof(result));
	int lenA = strA.length(),lenB = strB.length();

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

	int indexNoZero = LA+LB+1;

	for(int i=LA+LB+1;i>=0;i--){
		if(result[i]!=0)
			break;
		indexNoZero--;
	}
	for(int i=indexNoZero;i>=0;i--)
		cout<<result[i];
	cout<<endl;
}

int main(){
	int testCase;
	string a,b;

	cin>>testCase;

	for(int i=0;i<testCase;i++){
		cin>>a>>b;
		multiple(a,b);
	}
	return 0;
}