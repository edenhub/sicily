#include <iostream>
#include <stack>
#define N 100000

using namespace std;
/* 
考察stack的应用，同括号匹配
*/
int main(){
	int cicle[2*N+1],num,meal,femeal;

	while((cin>>num) && (num!=0)){
		stack<int> s;
		for(int i=1;i<=num;i++){
			cin>>meal>>femeal;
			cicle[meal] = i;
			cicle[femeal] = i;
		}
		for(int i=1;i<=2*num;i++){
			if(!s.empty()&&cicle[i] == s.top())
				s.pop();
			else
				s.push(cicle[i]);
		}

		if(s.empty())
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}

	return 0;
}
