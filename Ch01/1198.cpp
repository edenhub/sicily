#include <iostream>
#define N 8

using namespace std;

int main(){
	int times;
	cin>>times;
	string results[N];

	for(int i=0;i<times;i++){
		int lineNumbers;
		cin>>lineNumbers;
		string lines[N],temp;

		for(int j=0;j<lineNumbers;j++){
			cin>>lines[j];
			// positions[j] = 0;
		}

		for(int j=0;j<lineNumbers;j++){
			temp = lines[j];
			for(int k=j-1;k>=0;k--){
				if(temp.compare(lines[k])<0){
					lines[k+1] = lines[k];
				}else{
					lines[k+1] = temp;
					break;
				}
			}
		}

		for(int j=0;j<lineNumbers;j++)
			cout<<lines[j];
	}

	return 0;
}