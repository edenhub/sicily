#include <string>
#include <iostream>
#include <queue>

using namespace std;

/*
4步以内，3^4只有81中可能，直接暴力破解
用广度优先，第一个符合的就是结果
以魔板的状态为元素进队列进行操作
如果当前的魔板同目标值相同，直接返回，
否则进行3种操作后进队，知道步数达到要求为止
*/
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

void search(int stepNum,string &target){
	string initStr("12348765"),currStr,currResult;
	queue<string> queueStr;
	queue<int> queueStep;
	queue<string> queueResult;
	queueStr.push(initStr);
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
			queueStr.push(operatorA(currStr));
			queueStep.push(stepCount+1);
			queueResult.push(currResult+'A');
			queueStr.push(operatorB(currStr));
			queueStep.push(stepCount+1);
			queueResult.push(currResult+'B');
			queueStr.push(operatorC(currStr));
			queueStep.push(stepCount+1);
			queueResult.push(currResult+'C');
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