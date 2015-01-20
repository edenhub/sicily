#include <iostream>
#include <map>

using namespace std;

struct Node{
	int p,left,right;

	Node(){
		p = left = right = 0;
	}

	Node(int ap,int aleft,int aright){
		p = ap;
		left = aleft;
		right = aright;
	}
};

void postOrder(map<int,Node> &tree,int root){
		Node n = tree[root];

		if(n.left!=0)
			postOrder(tree,n.left);
		if(n.right!=0)
			postOrder(tree,n.right);
		cout<<root<" ";
}

void trave(int m){
	map<int,Node> tree;
	for(int i=0;i<m;i++){	
		int id,p,l,r;
		cin>>id>>l>>r;

		tree[id].left = l;
		tree[id].right = r;

		tree[l].p = id;
		tree[r].p = id;
	}

	map<int,Node>::iterator iter;
	int root;

	for(iter=tree.begin();iter!=tree.end();iter++){
		if(iter->second.p == 0){
			root = iter->first;
			break;
		}
	}

	postOrder(tree,root);
	cout<<endl;
}



int main(){
	int num;

	while((cin>>num) && (num!=0))
		trave(num);

	return 0;
}