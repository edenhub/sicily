#include <iostream>
#include <vector>


#define INF 10000000

using namespace std;

int tag[4][3];

void setTag(){
	for(int i=0;i<3;i++){
		int w,r;
		cin>>w>>r;

		if(w == -1) exit(0);

		tag[i][1] = w;
		tag[i][2] = r;
	}

	int r;
	cin>>r;
	tag[3][1] = r;
	tag[3][0] = 1000;

	tag[0][0] = 0;
	for(int i=1;i<=3;i++){
		tag[i][0] = tag[i-1][1]+1;
	}
}

void getOutput(vector<int>& in){
	int len = in.size();

	for(int i=0;i<len;i++){
		int price = INF;
		int w = in[i];
		for(int j=0;j<4;i++){
			if(tag[i][0] <= w && w <= tag[i][1]){
				price = (price > w * tag[i][2]) ? (w * tag[i][2]) : (price);
			}else if(w < tag[i][0]){
				price = (price > tag[i][0] * tag[i][2]) ? (tag[i][0] * tag[i][2]) : (price);
			}
		}
		cout<<price<<endl;
	}

}

void setInputVector(){
	setTag();
	vector<int> in;
	int index = 0;

	while(1){
		int num;
		cin>>num;
		if(num == 0) break;
		in[index++] = num;
	}
	getOutput(in);

}

int main(){
	
	while(1)
		setInputVector();

	return 0;
}
