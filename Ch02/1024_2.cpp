#include <stdio.h>
#include <vector>

#define N 10000

using namespace std;

struct Node{
	int to,dis;

	Node(){to = 0;dis=0;}
	Node(int a_to,int a_dis){
		to = a_to; dis = a_dis;
	}
};

vector<Node> isoland[N+1];
int maxLen;

void dfs(int curr,int parent,int length){
	if(length > maxLen){
		maxLen = length;
	}

	for(int i=0;i<isoland[curr].size();i++){
		if(isoland[curr][i].to != parent){
			dfs(isoland[curr][i].to,curr,length+isoland[curr][i].dis);
		}
	}
}

void init(int nodeNums,int capital){
	// memset(isoland,0,sizeof(Node)*(N+1));

	for(int i=1;i<=nodeNums-1;i++){
		int c1,c2,dis;
		scanf("%d %d %d",&c1,&c2,&dis);

		vector<Node>& v1 = isoland[c1];
		vector<Node>& v2 = isoland[c2];
		v1.push_back(Node(c2,dis));
		v2.push_back(Node(c1,dis));
	}
	
	maxLen = 0;
	dfs(capital,0,0);
	printf("%d\n",maxLen);
}

int main(){

	int nodeNums,capital;
	while(scanf("%d %d",&nodeNums,&capital)!=EOF)
		init(nodeNums,capital);

	return 0;
}