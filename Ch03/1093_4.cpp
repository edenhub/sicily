#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#define INF 100000000

using namespace std;

int tag[4][3];

void dumpTag(){
	for(int i=0;i<4;i++)
		cout<<tag[i][0]<<" "<<tag[i][1]<<" "<<tag[i][2]<<endl;
}

void setTag(){
	// cout<<"init"<<endl;
	for(int i=0;i<3;i++){
		int w,r;
		cin>>w;
		// cout<<"w : "<<w<<endl;
		if(w == EOF) exit(0);
		cin>>r;

		tag[i][1] = w;
		tag[i][2] = r;
	}

	int r;
	cin>>r;
	tag[3][1] = 1000;
	tag[3][2] = r;

	tag[0][0] = 0;
	for(int i=1;i<=3;i++){
		tag[i][0] = tag[i-1][1]+1;
	}

	// dumpTag();
}

void getOutput(vector<int>& in){
	int len = in.size();
	for(int j=0;j<len;j++){
		int price = INF;
		int w = in[j];
		int addition = 0;
		for(int i=0;i<4;i++){
			if(tag[i][0] <= w && w <= tag[i][1]){
				int r = w * tag[i][2];
				price = (price > r) ? (r) : (price);
				addition = 0;
			}else if(w < tag[i][0]){
				int r = tag[i][0] * tag[i][2];
				if(price > r){
					addition = tag[i][0] - w;
					price = r;
				}
				// price = (price > tag[i][0] * tag[i][2]) ? (tag[i][0] * tag[i][2]) : (price);
			}
		}
		cout<<"Weight ("<<w<<") has best price $"<<price<<" (add "<<addition<<" pounds)"<<endl;
		// cout<<price<<endl;
	}

}

void getOut(int w){
	int price = INF;
		// int w = in[j];
		int addition = 0;
		for(int i=0;i<4;i++){
			if(tag[i][0] <= w && w <= tag[i][1]){
				int r = w * tag[i][2];
				price = (price > r) ? (r) : (price);
				addition = 0;
			}else if(w < tag[i][0]){
				int r = tag[i][0] * tag[i][2];
				if(price > r){
					addition = tag[i][0] - w;
					price = r;
				}
				// price = (price > tag[i][0] * tag[i][2]) ? (tag[i][0] * tag[i][2]) : (price);
			}
		}
		cout<<"Weight ("<<w<<") has best price $"<<price<<" (add "<<addition<<" pounds)"<<endl;
}


void setInputVector(){
		setTag();
		// vector<int> in;
		// int index = 0;

		while(1){
		int num;
		cin>>num;
		// cout<<num<<"------------"<<endl;
		if(num == 0) break;
		else getOut(num);
		// in.push_back(num);
		}

		// getOutput(in);
}

int main(){

	while(1)
		setInputVector();

	return 0;
}
