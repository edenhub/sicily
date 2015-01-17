#include <iostream>
#include <stack>
#include <stdio.h>

using namespace std;

bool isRegular(int num){
	stack<char> st;

	for(int i=0;i<num;i++){
		char ch;
		cin>>ch;

		if(ch == '(' || ch=='[' || ch=='{'){
			st.push(ch);
		}else{
			if(!st.empty()){
				char top = st.top();

				if((top == '[' && ch == ']') ||
				   (top == '{' && ch =='}') ||
				   (top == '(' && ch == ')')
					){
					st.pop();
			}else{
					st.push(ch);
				}
			}else{
					st.push(ch);
			}
		}
	}

	if(st.empty())
		return true;
	else
		return false;
}

int main(){
	int num;

	while(scanf("%d",&num)!=EOF)
		if(isRegular(num))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	return 0;
}