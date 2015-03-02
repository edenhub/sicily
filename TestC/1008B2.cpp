#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

struct state{
	int data[9];
	// int action;
	int father;
	int count;
};

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

int fac[] = {1,1,2,6,24,120,720,5040,40320,362880};

int cantor(state& s,int n){
	int temp,sum=0;

	for(int i=0;i<n;i++){
		temp = 0;
		for(int j=i+1;j<n;j++){
			if(s.data[j] < s.data[i]) temp++;
		}
		sum += fac[n-i-1] * temp;
	}

	return sum+1;
}

bool next_state(state s,int po,int action,state& news){
	int x = po / 3;
	int y = po % 3;

	int newx = x + dx[action];
	int newy = y + dy[action];
	int newz = newx*3+newy;

	if(newx>=0 && newx<3 && newy >=0 && newy<3){
		news = s;
		news.data[newz] = 0;
		news.data[po] = s.data[newz];

		return true;
	}

	return false;
}

bool stateCmp(state& first,state& second){
	for(int i=0;i<9;i++){
		if(first.data[i] != second.data[i]){
			return false;
		}
	}

	return true;
}

void printState(state& s){
	for(int i=0;i<9;i++)
		cout<<s.data[i];
	cout<<endl;
}

bool visited[40321];

void bfs(state init,state target){
	queue<state> qu;
	memset(visited,false,sizeof(visited));

	qu.push(init);

	while(!qu.empty()){
		state curr = qu.front(); qu.pop();
		visited[cantor(curr,9)] = true;
		if(stateCmp(target,curr)){
			cout<<curr.count<<endl;
			return;
		}
		for(int po=0;po<9;po++){
			if(curr.data[po] == 0){
				for(int action=0;action<4;action++){
					state news;
					if(next_state(curr,po,action,news)){
						int hash = cantor(news,9);
						if(!visited[hash]){
							news.father = hash;
							news.count++;
							qu.push(news);
	
						}
					}
				}
			}
		}
	}
	cout<<"null"<<endl;

}



int main(){
	state init={{1,2,3,4,5,6,7,8,0},-1,0};
	int testCase;
	cin>>testCase;

	for(int i=0;i<testCase;i++){
		state target={{0},0,0};
		for(int j=0;j<9;j++){
			cin>>target.data[j];
		}
		// printState(target);
		bfs(init,target);
		
	}

	return 0;
}