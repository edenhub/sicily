#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <map>

#define N 10000

using namespace std;

bool visited[N];

struct edge{
	int c1,c2,dis;

	edge(){
		c1 = 0; c2 = 0; dis = 0;
	}

	edge(int a_c1,int a_c2,int a_dis){
		c1 = a_c1; c2 = a_c2; dis = a_dis;
	}
};

void dfs(map<int,edge>& loads,map<int,vector<int> >& nodes,int max,int parent){
	visited[parent] = true;

}

void bfs(map<int,edge>& loads,map<int,vector<int> >& nodes,int capital){
	memset(visited,false,sizeof(visited));

	visited[capital] = true;

	queue<int> q;
	int curr,max=0;
	q.push(capital);

	while(!q.empty()){
		curr = q.front(); q.pop();
		vector<int>& neibgs = nodes[curr];
		visited[curr] = true;
		// cout<<curr<<" ";  

		for(int i=0;i<neibgs.size();i++){
			int n = neibgs[i],c2 = loads[n].c2;

			if(!visited[c2]){

				q.push(c2);
			}
		}
	}

	cout<<endl<<max<<endl;


}

void init(int nodeNums,int capital){
	map<int,edge> loads;
	map<int,vector<int> > nodes;

	for(int i=1;i<=nodeNums-1;i++){
		int c1,c2,dis;
		cin>>c1>>c2>>dis;
		loads[i].c1 = c1; loads[i].c2 = c2; loads[i].dis = dis;
		vector<int>& vC1 = nodes[c1]; vC1.push_back(i);
		vector<int>& vC2 = nodes[c2]; vC2.push_back(i);
	}

	bfs(loads,nodes,capital);
}
 

int main(){
	init(7,1);

	return 0;
}