#include <string>
#include <iostream>
#include <queue>

#define N 40320

using namespace std;

string operatorA(string str){
	char temp;

	for(int i=0;i<=3;i++){
		temp = str[i];
		str[i] = str[i+4];
		str[i+4] = temp;
	}

	return str;
}

string operatorB(string str){
	char tempUp=str[3],tempDown=str[7];

	for(int i=3;i>=1;i--){
		str[i] = str[i-1];
		str[i+4] = str[i+3];
	}

	str[0] = tempUp;
	str[4] = tempDown;

	return str;
}

string operatorC(string str){
	char temp1 = str[1],temp2 = str[2],
		 temp5 = str[5],temp6 = str[6];

	str[1] = temp5;
	str[2] = temp1;
	str[5] = temp6;
	str[6] = temp2;

	return str;
}
int fac[] = {1,1,2,6,24,120,720,5040,40320};
int hash(const string &str){
	int temp,sum=0,n=str.length();

	for(int i=0;i<n;i++){
		temp = 0;
		for(int j=i+1;j<n;j++){
			if((str[j] - '0') < (str[i] - '0')) temp++;
		}

		sum += temp * fac[(n-i-1)]; 
	}

	return sum+1;
}

void search(int stepNum,string &target){
	string currStr="12348765",initStr(currStr),currResult,currOper;
	queue<string> queueStr;
	queue<int> queueStep;
	queue<string> queueResult;
	bool visited[N] = {false};
	queueStr.push(initStr);
	visited[hash(currStr)] = true;
	queueStep.push(0);
	queueResult.push("");
	int stepCount = 0;

	while(stepCount<=stepNum && !queueStr.empty()){
		currStr = queueStr.front();
		stepCount = queueStep.front();
		currResult = queueResult.front();
		queueStr.pop();
		queueStep.pop();
		queueResult.pop();

		if(target == currStr){
			cout<<stepCount<<" "<<currResult<<endl;
			return;
		}else{
			currOper = operatorA(currStr);
			if(!visited[hash(currOper)]){
				queueStr.push(currOper);
				queueStep.push(stepCount+1);
				queueResult.push(currResult+'A');
			}

			currOper = operatorB(currStr);
			if(!visited[hash(currOper)]){
				queueStr.push(currOper);
				queueStep.push(stepCount+1);
				queueResult.push(currResult+'B');
			}

			currOper = operatorC(currStr);
			if(!visited[hash(currOper)]){
				queueStr.push(currOper);
				queueStep.push(stepCount+1);
				queueResult.push(currResult+'C');
			}
		}
	}
	cout<<"-1"<<endl;
}

int main(){
	int stepNum;
	string target("12345678");

	while((cin>>stepNum) && stepNum!=-1){
		for(int i=0;i<8;i++)
			cin>>target[i];
		search(stepNum,target);
	}

	return 0;
}