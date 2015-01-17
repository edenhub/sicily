#include <iostream>
#include <stack>
#include <stdio.h>

using namespace std;

void isRegular(int num){
	if((num%2) != 0){
		cout<<"NO"<<endl;
		return;
	}
	stack<char> st;
	for(int i=0;i<num;i++){
		char ch;
		cin>>ch;

		if(ch == '(' || ch=='[' || ch=='{'){
			st.push(ch);
		}
		else{
			if(!st.empty()){
				char top = st.top();
			// 	switch(top){
			// 		case '(' : 
			// 			if(ch == ')')
			// 				st.pop();
			// 			break;
			// 		case '[' :
			// 			if(ch==']')
			// 				st.pop();
			// 			break;
			// 		case '{':
			// 			if(ch=='}')
			// 				st.pop();
			// 			break;
			// 	}
				if((top == '[' && ch == ']') ||
				   (top == '{' && ch =='}') ||
				   (top == '(' && ch == ')')
					)
					st.pop();
				else{
					cout<<"NO"<<endl;
					return;
				}
			}else{
				cout<<"NO"<<endl;
				return;
			}
		}
	}

	if(st.empty())
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

int main(){
	int num;

	while(scanf("%d",&num)!=EOF)
		isRegular(num);

	return 0;
}