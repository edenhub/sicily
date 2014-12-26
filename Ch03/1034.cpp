#include <iostream>
#include <vector>
#include <memory.h>

#define N 1024

using namespace std;

// 访问数据，结果是否为树的标记
bool visit[N],ok;
// 每个点有向边的集合
vector<int> edges[N];
// 每个层的宽度
int width[N];
// 最大宽度，最大深度，每个点的入度数
int W,D,in[N];

// 深度优先搜索
// 当前点，当前深度
void dfs(int u,int d){
	if(visit[u]){
		ok = false;
		return;
	}

	visit[u] = true;
	// 如果当前深度大于最大深度，改变
	if(d > D) D = d;
	width[d]++;
	// 如果当前层宽度大于最大宽度，改变
	if(width[d] > W) W = width[d];
	// 对于当前层的每个领接点，进行dfs
	for(int i=0;i<edges[u].size();i++){
		if(!ok) return;
		int v = edges[u][i];
		dfs(v,d+1);
	}
}

void isForset(int nodeNum,int edgeNum){
	ok = true;
	W = D =0;
	if(edgeNum >= nodeNum) ok = false;

	memset(visit,false,sizeof(visit));
	memset(width,0,sizeof(width));
	memset(in,0,sizeof(in));
	memset(edges,0,sizeof(edges));

	for(int i=0;i<edgeNum;i++){
		int a,b;
		cin>>a>>b;
		edges[a].push_back(b);
		in[b]++;
	}

	// 对于入度数为0的点，为树根，判断是否可以遍历，判断是否为树
	for(int i=1;i<=nodeNum;i++){
		if(in[i] == 0)
			dfs(i,0);
	}

	// 若存在未访问过的点，则不是树
	for(int i=1;i<=nodeNum;i++){
		if(!visit[i]){
			ok = false;
			break;
		}
	}

	if(!ok) cout<<"INVALID"<<endl;
	else cout<<D<<" "<<W<<endl;
}

int main(){
	int nodeNum,edgeNum;

	while((cin>>nodeNum>>edgeNum) && (nodeNum != 0))
		isForset(nodeNum,edgeNum);

	return 0;
}