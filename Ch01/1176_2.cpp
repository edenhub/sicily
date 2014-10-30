#include <iostream>
#include <memory.h>
#define N 1000

using namespace std;

int dp[N][N],data[N];
bool visited[N][N];

int max(int first,int second){
	return (first > second) ? first : second;
}
/*
在原来的结构上加上记忆搜索（用矩阵存储中间结果）
将中间结果存储在矩阵中，每个分支不用立即返回值，而是等分支都判断完后返回
加上visited[N][N]判断是否访问过，直接返回中间值
*/
int maxPoint(int left,int right){
	if(visited[left][right]) return dp[left][right];
	if(left == right) return -data[left];

	if((right - left + 1) % 2 == 1){
		if(data[left] < data[right]){
			dp[left][right] = maxPoint(left,right-1) - data[right];
		}else{
			dp[left][right] = maxPoint(left+1,right) - data[left]; 
		}
	}else{
		dp[left][right] = max((maxPoint(left+1,right)+data[left]),(maxPoint(left,right-1)+data[right]));
	}

	visited[left][right] = true;
	return dp[left][right]; 
}

int main(){
	int testCaseNum,index=0,result;

	while((cin>>testCaseNum) && (testCaseNum != 0 )){
		memset(data,0,sizeof(data));
		memset(dp,0,sizeof(dp));
		memset(visited,0,sizeof(visited));
		index++;
		for(int i=0;i<testCaseNum;i++)
			cin>>data[i];

		result = maxPoint(0,testCaseNum-1);
		cout<<"In game "<<index<<", the greedy strategy might lose by as many as "<<result<<" points."<<endl;

	}

	return 0;
}