#include <iostream>
#include <algorithm>
#define N 101

using namespace std;

// 对于每组给定的数据，枚举ABCDE的全排列
// 将每个排列跟给定的数据进行计算，找出最小的值为答案

// 用于存放ABCDE的位置
int posSrc[128],posDes[128];
// 用于存放输入的字符串
string repo[N];

// 计算距离
int dis(string& src,string& des){
	int count=0;
	// int posSrc[128],posDes[128];
	// 将字符转为对应的数字
	for(int i=0;i<5;i++){
		posSrc[src[i]] = i;
		posDes[des[i]] = i;
	}

	// 对于两个两同的位置，如果两者的差值乘积小于0，则两者存在不同的排序
	for(char i = 'A';i<='E';i++){
		for(char j='A';j<='E';j++){
			if((posSrc[i] - posSrc[j]) * (posDes[i] - posDes[j]) <0 )
				count++;
		}
	}

	// 将src和des的结果减半
	return count/2;
}

// 计算
void find(int n){
	// string repo[N];
	for(int i=0;i<n;i++){
		cin>>repo[i];
	}
	string init = "ABCDE",ans;
	int temp,sum = 0;

	// 求ABCDE的每个全排列
	do{
		// 求每次的距离和
		temp = 0;
		for(int i=0;i<n;i++){
			temp += dis(init,repo[i]);
		}

		// 将小值赋予sum
		if(sum == 0 || sum > temp ){ 
				sum = temp;
				ans = init;
		}
	}while(next_permutation(init.begin(),init.end()));

	cout<<ans<<" is the median ranking with value "<<sum<<"."<<endl;
}

int main(){
	int lineNum;

	while((cin>>lineNum) && (lineNum!=0)){
		find(lineNum);
	}
	
	return 0;
}