#include <iostream>
#include <set>
#include <stdio.h>

#define N 3000

using namespace std;

set<string> s;
void dfs(string str,int index,int length){
	// cout<<"-"<<str<<endl;
	if(index == length){
		s.insert(str);
		// cout<<str<<endl;
		return;
	}else{
		if(str[index] == '?'){
			str[index] = '0';
			dfs(str,index+1,length);

			str[index] = '1';
			dfs(str,index+1,length);
		}else{
			dfs(str,index+1,length);
		}
	}
}



int main(){
	int len,num;
	string list[N];
	while(scanf("%d%d",&len,&num) && (len!=0)){
		for(int i=0;i<num;i++){
			string str;
			cin>>str;
			list[i] = str;
		}
		for(int i=0;i<num;i++)
			dfs(list[i],0,len);
		cout<<s.size()<<endl;
		s.clear();
	}

	return 0;
}