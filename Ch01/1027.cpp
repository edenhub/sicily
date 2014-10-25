#include <iostream>
#include <map>
#include <string>
using namespace std;
/*
STL自带的map维持着一颗红黑树，本身带有排序功能
*/
int main(){
	int num;

	while((cin>>num) && (num!=0)){
		map<string,string> container,referrence;
		for(int i=0;i<num;i++){
			string id,ip;
			cin>>id>>ip;

			if(container[ip]==""){
				container[ip] = id;
			}else{
				referrence[container[ip]]=id;
			}
		}

		for(map<string,string>::iterator itr = referrence.begin(); itr!=referrence.end();itr++)
			cout<<itr->second<<" is the Majia of "<<itr->first<<endl;
		cout<<endl;
	}

	return 0;
}
