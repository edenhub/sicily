#include <iostream>
#include <map>

using namespace std;
// 没有说明那个是root，需要增加parent标记，然后去查找

struct node{
	int parent,left,right;
	char content;

	node(){
		parent = 0;left = 0;right = 0;
		content = '\0';
	}

	node(int l,int r,char c){
		parent = 0;
		left = l;
		right = r;
		content = c;
	}
};

// void dumpMap(map<int,node>& container){
// 	map<int,node>::iterator iter;

// 	for(iter=container.begin();iter!=container.end();iter++){
// 		cout<<iter->first<<" "<<iter->second.content<<" "<<iter->second.left<<" "<<iter->second.right<<endl;
// 	}
// }

// 先序遍历树
void preOrder(map<int,node>& container,int id){
	
	// if(id != 0){
		node n = container[id];
		cout<<n.content;

		if(n.left!=0)
			preOrder(container,n.left);
		if(n.right!=0)
			preOrder(container,n.right);
	// }
}

void listOrder(int nodeNum){
	map<int,node> container;
	int rootId;
	for(int in=0;in<nodeNum;in++){
		int i,l,r;
		char c;
		cin>>i>>c>>l>>r;

		// 可以直接 cin>>container[i].left

		container[i].left = l;
		container[i].right = r;
		container[i].content = c;

		container[container[i].left].parent = i;
		container[container[i].right].parent = i;
	}

	map<int,node>::iterator iter;

	// 查找根节点
	for(iter = container.begin();iter!=container.end();iter++){
		if(iter->second.parent == 0){
			rootId = iter->first;
			break;
		}
	}

	preOrder(container,rootId);
	cout<<endl;
}

int main(){

	int nodeNum;

	while((cin>>nodeNum) && (nodeNum!=-1))
		listOrder(nodeNum);

	return 0;
}