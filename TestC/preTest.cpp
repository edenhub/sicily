#include <set>
#include <iostream>
#include <stack>
using namespace std;

int main(){
	set<string> container;

	container.insert("ada");
	cout<<container.size()<<endl;
	container.insert("ada");
	cout<<container.size()<<endl;

	cout<<"-------------"<<endl;

	stack<char> st;
	st.push('a');
	st.push('b');
	cout<<st.size()<<endl;
	st.pop();
	cout<<st.size()<<endl;

	return 0;
}