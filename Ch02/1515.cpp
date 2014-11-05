#include <iostream>
#include <queue>
#include <memory.h>

#define VN 40320

using namespace std;

typedef struct G{
	int data[8];
	string opChain;
}Graph;

int fac[]={1,1,2,6,24,120,720,5040,40320,362880};
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

Graph oper(Graph parent,char op){
	Graph child;
	switch(op){
		case 'A' : {
			for(int i=0;i<2;i++){
				child.data[i] = parent.data[i+2];
				child.data[i+4] = parent.data[i+6];
			}
			for(int i=2;i<4;i++){
				child.data[i] = parent.data[i-2];
				child.data[i+4] = parent.data[i+2];
			}
			child.opChain = parent.opChain+'A';
			break;
		}

		case 'B' : {
			for(int i=0;i<3;i++){
				child.data[i] = parent.data[i+1];
				child.data[i+4] = parent.data[i+5];
			}
			child.data[3] = parent.data[0];
			child.data[7] = parent.data[4];
			child.opChain = parent.opChain+'B';
			break;
		}

		case 'C' : {
			child = parent;
			child.data[1] = parent.data[2];
			child.data[2] = parent.data[6];
			child.data[5] = parent.data[1];
			child.data[6] = parent.data[5];
			child.opChain = parent.opChain+'C';
			break;
		}
	}

	return child;
}

bool compareGraph(Graph &src,Graph &desc){
	for(int i=0;i<8;i++)
		if(src.data[i] != desc.data[i])
			return false;

	return true;
}

void search(Graph &target,int stepNum){

	queue<Graph> queueG;
	bool visited[VN];
	memset(visited,false,sizeof(visited));
	Graph front;
	int currStep=0;

	Graph init = {{1,2,3,4,5,6,7,8},""};
	queueG.push(init);
	visited[cantor(init,8)] = true;

	while(currStep <= stepNum && !queueG.empty()){
		front = queueG.front(); queueG.pop();
		currStep = front.opChain.length();

		if(compareGraph(target,front)){
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