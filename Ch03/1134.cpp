#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
	int a,b;

	node(){a = 0; b = 0;}
	node(int a1,int b1){
		a = a1; b = b1;
	}
};

int n,s;

bool cmp(node first,node second){
	return first.b < second.b;
}

void init(int n,int s){
	
	vector<node> children;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		children.push_back(node(a,b));
	}
	sort(children.begin(),children.end(),cmp);
	bool res = true;
	for(int i=0;i<n;i++){
		if(s < children[i].b){
			res = false;
			break;
		}

		s += children[i].a;
	}

	if(res) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;	
}

int main(){
	int n,s;

	while((cin>>n>>s) && (n!=0))
		init(n,s);
}