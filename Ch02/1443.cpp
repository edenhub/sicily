#include <iostream>
#include <map>
#include <queue>

using namespace std;

// 直接模拟队列操作，使用map存储对应位置和他的优先级
// 再用队列存储位置，队列模拟操作，每次出队后加1,并将map中的优先级设为-1

// 判断所给的位置是否为最大值
bool isMax(map<int,int>& container,int position){
	int priority = container[position];

	map<int,int>::iterator iter;
	for(iter = container.begin();iter!=container.end();iter++){
		if(priority < iter->second)
			return false;
	}

	return true;
}

void myTimes(int jobNum,int position){
	// first为position,second为priority
	map<int,int> container;
	queue<int> jobs;
	int pot,curr,count=0;

	for(int i=0;i<jobNum;i++){
		cin>>pot;
		container.insert(make_pair(i,pot));
		jobs.push(i);
	}

	while(!jobs.empty()){
		curr = jobs.front();
		jobs.pop();
		// 如果当前位置有最大优先级，则输出，并进行修改
		if(isMax(container,curr)){
			container[curr] = -1;
			count++;
			if(curr == position){
				cout<<count<<endl;
				return;
			}
		}else{
			jobs.push(curr);
		}
	}

}

int main(){
	int testCase,jobNum,position;
	cin>>testCase;

	for(int i=0;i<testCase;i++){
		cin>>jobNum>>position;
		myTimes(jobNum,position);
	}

	return 0;
}