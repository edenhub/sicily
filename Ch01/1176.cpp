#include <iostream>
#include <memory.h>
#define N 1000

using namespace std;

int data[N];

int max(int first,int second){
	return (first > second) ? first : second;
}

/*
用递归的方法，写出取数的结构
结束条件：剩下一个数
循环条件：轮到B/轮到A，在分支中采用递归描述结果
*/
int maxPoint(int left,int right){
	if(left == right) 
		return -data[left]; //左右相等，轮到B取最后一次，减去
	else if((right - left +1 ) %2 ==1){
		//轮到B取数
		if(data[left] < data[right])
			return maxPoint(left,right-1) - data[right];
		else
			return maxPoint(left+1,right) - data[left];
	}else{
		//轮到A取数
		return max((maxPoint(left+1,right)+data[left]),(maxPoint(left,right-1)+data[right]));
	}
}

int main(){
	int testCaseNum,index=0,result;

	while((cin>>testCaseNum) && (testCaseNum != 0 )){
		memset(data,0,sizeof(data));
		index++;
		for(int i=0;i<testCaseNum;i++)
			cin>>data[i];

		result = maxPoint(0,testCaseNum-1);
		cout<<"In game "<<index<<", the greedy strategy might lose by as many as "<<result<<" points."<<endl;

	}

	return 0;
}