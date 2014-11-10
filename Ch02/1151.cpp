#include <iostream>
#include <queue>
#include <memory.h>

// 8!=4320，所有的魔板排列只有这么多
// 用数组存储检查过的魔板状态，进行剪枝
#define VN 40320
using namespace std;

// 用int数组表示魔板的状态，同时存储得到该状态所需的操作
typedef struct G{
	int data[8]; //用于存储魔板
	string opChain;//用于纪录每步的操作
}Graph;

// 阶乘数组,用于求康拓展开
int fac[]={1,1,2,6,24,120,720,5040,40320,362880};
// 求康拓展开
// X=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[i]*(i-1)!+...+a[2]*1!+a[1]*0!
// 其中，a为整数，并且0<=a[i]<i(1<=i<=n)
int cantor(Graph& g,int n){
	// temp为每个位的系数；sum为最后的康拓展开数
	int temp,sum=0;
	

	for(int i=0;i<n;i++){
		temp = 0;
		for(int j=i+1;j<n;j++){
			// 康拓展开的每个位的系数为该阶后面小于该位的个数
			if(g.data[j] < g.data[i]) temp++;
		}

		sum += fac[n-i-1] * temp;
	}

	return sum+1;
}

// 对魔板施加操作，接收源魔板和操作符，返回对应的魔板
Graph oper(Graph parent,char op){
	Graph child;
	switch(op){
		// A操作
		case 'A' : {
			for(int i=0;i<4;i++){
				child.data[i] = parent.data[i+4];
				child.data[i+4] = parent.data[i];
			}
			child.opChain = parent.opChain+'A';
			break;
		}
		// B操作
		case 'B' : {
			for(int i=3;i>=1;i--){
				child.data[i] = parent.data[i-1];
				child.data[i+4] = parent.data[i+3];
			}
			child.data[0] = parent.data[3];
			child.data[4] = parent.data[7];
			child.opChain = parent.opChain+'B';
			break;
		}
		// C操作
		case 'C' : {
			child = parent;
			child.data[1] = parent.data[5];
			child.data[2] = parent.data[1];
			child.data[5] = parent.data[6];
			child.data[6] = parent.data[2];
			child.opChain = parent.opChain+'C';
			break;
		}
	}

	return child;
}

// 比较魔板是否相同
bool compareGraph(Graph &src,Graph &desc){
	for(int i=0;i<8;i++)
		if(src.data[i] != desc.data[i])
			return false;

	return true;
}

// bfs搜索，接收目标状态和步数，输出结果
void search(Graph &target,int stepNum){
	// 魔板队列，用户存储魔板的中间状态
	queue<Graph> queueG;
	// 访问数据，用于纪录魔板是否访问过
	bool visited[VN];
	// 数组初始化
	memset(visited,false,sizeof(visited));
	// 队头指针
	Graph front;
	// 当前的步数
	int currStep=0;
	// 魔板的初始态
	Graph init = {{1,2,3,4,8,7,6,5},""};
	// 将魔板的初始状态压入队列
	queueG.push(init);
	// 用康拓展开求魔板对应的整数，标记为访问过
	visited[cantor(init,8)] = true;

	// 求是否存在目标态
	while(currStep <= stepNum && !queueG.empty()){
		// 出队
		front = queueG.front(); queueG.pop();
		// 求当前的层数
		currStep = front.opChain.length();
		// 如果符合目标态，则输出，返回结束
		if(compareGraph(target,front)){	
			// 判断该状态是否走过
			cout<<currStep<< " "<<front.opChain<<endl;
			return;
		}else{
			// 否则对当前的状态施加A、B、C操作，
			// 如果施加后的状态未访问过，则入队
			for(char ch = 'A';ch <= 'C';ch++){
				Graph child = oper(front,ch);
				int location = cantor(child,8);
				if(!visited[location]){
					visited[location] = true;
					queueG.push(child);
				}
			}
		}
	}
	// 没有符合的操作则返回-1
	cout<<"-1"<<endl;
}

int main(){
	int stepNum;
	Graph target;

	while((cin>>stepNum) && stepNum!=-1){
		for(int i=0;i<8;i++)
			cin>>target.data[i];
		search(target,stepNum);
	}
	return 0;
}