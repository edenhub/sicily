#include <stdio.h>
#include <vector>
#include <memory.h>

#define N 10000

using namespace std;

// 查找树中从一个点K开始的最长路径，使用dfs或者bfs找到最长一个点即可
// 1.没有说明输入顺序一定不会变，要冗余，存两条边
// 2.使用dfs时，递归前设置标记，递归后要取消标记

// 使用c1 -> (c2,dis),(c3,dis)...存储数据，需要冗余

struct Node{
	int to,dis;

	Node(int a_to,int a_dis){
		to = a_to; dis = a_dis;
	}
};

vector<Node> isoland[N+1];
bool visited[N];
int maxLen;

void dfs(int curr,int length){
	if(length > maxLen){
		maxLen = length;
	}

	// 递归前设置标记，已经走过
	visited[curr] = true;

	for(int i=0;i<isoland[curr].size();i++){
		int to = isoland[curr][i].to;
		if(visited[to]) continue;

		dfs(to,length+isoland[curr][i].dis);
	}

	// 递归后取消标记，该点还可用
	visited[curr] = false;
}

void init(int nodeNums,int capital){
	memset(isoland,0,sizeof(isoland));

	for(int i=1;i<=nodeNums-1;i++){
		int c1,c2,dis;
		scanf("%d %d %d",&c1,&c2,&dis);

		// 存两个方向
		isoland[c1].push_back(Node(c2,dis));
		isoland[c2].push_back(Node(c1,dis));
	}
	
	memset(visited,false,sizeof(visited));
	maxLen = 0;
	dfs(capital,0);
	printf("%d\n",maxLen);
}

int main(){

	int nodeNums,capital;
	while(scanf("%d %d",&nodeNums,&capital)!=EOF)
		init(nodeNums,capital);

	return 0;
}