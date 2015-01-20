#include <iostream>
#include <set>
#include <stdio.h>

using namespace std;

void cal(int len,int num){
	set<string> s;
	char str[len];
	for(int i=0;i<num;i++){
		scanf("%s",str);
		for(int i=0;i<len;i++){
			if(str[i] == '?'){
				str[i] = '0';
				s.insert(str);
				str[i] = '1';
				s.insert(str);
				break;
			}
		}
		s.insert(str);
	}

	printf("%d\n",s.size());
}

int main(){
	int len,num;

	while(scanf("%d%d",&len,&num) && (len!=0)){
		cal(len,num);
	}

	return 0;
}