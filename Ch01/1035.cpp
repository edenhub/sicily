#include <iostream>

#define N 30

using namespace std;

bool compare(char first,char second){
	bool res = false;
	switch(first){
		case 'A' : second=='T'?res = true:res = false; break;
		case 'T' : second =='A'?res = true:res = false;break;
		case 'G': second == 'C'?res = true:res = false;break;
		case 'C': second == 'G'?res = true:res = false;break;
	}

	return res;
}

bool compareStr(string first,string second){
	int lenF = first.length();
	int lenS = first.length();

	if(lenF != lenS)
		return false;

	for(int i=0;i<lenF;i++)
		if(!compare(first[i],second[i]))
			return false;

	return true;
}

int main(){
	int T,n,sum;
	cin>>T;
	string lines[N];
	bool tags[N];

	for(int i=0;i<T;i++){
		cin>>n;
		sum = 0;
		for(int j=0;j<n;j++){
			cin>>lines[j];
			tags[j] = false;
		}

		for(int j=0;j<n;j++){
			if(!tags[j]){
				for(int k=j+1;k<n;k++){
					if(!tags[k]){
						if(compareStr(lines[j],lines[k])){
							sum++;
							tags[j] = true;
							tags[k] = true;
							break;
						}
					}
				}
			}
		}

		cout<<sum<<endl;
	}

	return 0;
}