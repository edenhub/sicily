#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Node{
	int id;
	string age;

	Node(){
		id = 0;
		age = "";
	}

	Node(int aId,string aAge){
		id = aId;
		age = aAge;
	}
};

bool binCmp(Node a,Node b){
	return a.id < b.id;
}

int main(){
	vector<Node> v;
	v.push_back(Node(1,"ada"));
	v.push_back(Node(2,"ke"));

	cout<<(*max_element(v.begin(),v.end(),binCmp)).age<<endl;
	cout<<(*min_element(v.begin(),v.end(),binCmp)).age<<endl;
	return 0;
}