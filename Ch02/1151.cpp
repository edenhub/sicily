#include <iostream>
#include <queue>
#include <memory.h>

// 8!=4320，所有的魔板排列只有这么多
#define VN 40320
// 用数组存储检查过的魔板状态，进行剪枝
using namespace std;

// 用int数组表示魔板的状态，同时存储得到该状态所需的操作
typedef struct G{
	int data[8];
	string opChain;
}Graph;

// 阶乘数组
int fac[]={1,1,2,6,24,120,720,5040,40320,362880};
// 求康拓展开
// X=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[i]*(i-1)!+...+a[2]*1!+a[1]*0!
// 其中，a为整数，并且0<=a[i]<i(1<=i<=n)
int cantor(Graph& g,int n){
	int temp,sum=0;

	for(int i=0;i<n;i++){
		temp = 0;
		for(int j=i+1;j<n;j++){
			if(g.data[j] < g.data[i]) temp++;
		}

		sum += fac[n-i-1] * temp;
	}

	return sum+1;
}

// 对魔板施加操作
Graph oper(Graph parent,char op){
	Graph child;
	switch(op){
		case 'A' : {
			for(int i=0;i<4;i++){
				child.data[i] = parent.data[i+4];
				child.data[i+4] = parent.data[i];
			}
			child.opChain = parent.opChain+'A';
			break;
		}

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

// bdf搜索
void search(Graph &target,int stepNum){
	queue<Graph> queueG;
	bool visited[VN];
	memset(visited,false,sizeof(visited));
	Graph front;
	int currStep=0;

	Graph init = {{1,2,3,4,8,7,6,5},""};
	queueG.push(init);
	visited[cantor(init,8)] = true;

	while(currStep <= stepNum && !queueG.empty()){
		front = queueG.front(); queueG.pop();
		currStep = front.opChain.length();

		if(compareGraph(target,front)){
			// 判断该状态是否走过
			cout<<currStep<< " "<<front.opChain<<endl;
			return;
		}else{
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