#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 利用sort进行排序，同时记录下原来的位置，再用矩阵填满
// 再输出
vector<pair<char,int> > wrapKeys(string& key){
	vector<pair<char,int> > keys;
	for(int i=0;i<key.length();i++)
		keys.push_back(make_pair(key[i],i));

	sort(keys.begin(),keys.end());

	return keys;
}

void entrptyed(vector<pair<char,int> >& keys,string& data){
	int col = keys.size();
	int row = data.length() / col,index = 0;
	char matrix[row][col];

	for(int i=0;i<col;i++){
		int position = keys[i].second;
		for(int j=0;j<row;j++)
			matrix[j][position] = data[index++];
	}

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
			cout<<matrix[i][j];
	}

	cout<<endl;
}


int main(){
	string key,data;

	while((cin>>key) && (key!="THEEND")){
		cin>>data;
		vector<pair<char,int> > keys = wrapKeys(key);
		entrptyed(keys,data);
	}

}