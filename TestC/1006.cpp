#include <iostream>
#include <map>
#include <set>
#include <memory.h>

#define N 200

using namespace std;

bool visited[N];	

void dfs(map<int,set<int> > &graph,int i){
		if(!visited[i]){
			visited[i] = true;
			set<int>::iterator iter;
			set<int> childs = graph[i];
			for(iter = childs.begin(); iter!= childs.end();iter++){
				dfs(graph,*iter);
			}

		}
}

int main(){
	int n,m;

	while((cin>>n>>m) && (n!=0)){
		map<int,set<int> > graph;
		memset(visited,false,sizeof(visited));
		for(int i=0;i<m;i++){
			int from,to;
			cin>>from>>to;
			graph[from].insert(to);
			graph[to].insert(from);
		}

		int cnt=0;
		for(int i=0;i<n;i++){
			if(!visited[i]){
				cnt++;
				dfs(graph,i);
			}
			
		}

		cout<<cnt-1<<endl;
	}

	return 0;
}