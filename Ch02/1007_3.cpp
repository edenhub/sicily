#include <iostream>

using namespace std;

// 注意题目表述，左右交替
// 使用一个矩阵存储字符，再输出即可
void encrypted(int col,string& message){
	int rows = message.length()/col;
	char matrix[rows][col];
	int index = 0;

	for(int j=0;j<rows;j++){
		if(j%2 == 0){
			for(int i = 0;i<col;i++){
				matrix[j][i] = message[index];
				index++;
			} 
		}else{
			for(int i=col-1;i>=0;i--){
				matrix[j][i] = message[index];
				index++;
			}
		}

	}

	for(int i=0;i<col;i++){
		for(int j=0;j<rows;j++)
			cout<<matrix[j][i];
	}
	cout<<endl;
}

int main(){
	int col;
	string input;

	while((cin>>col) && (col!=0)){
		cin>>input;
		encrypted(col,input);
	}

	return 0;
}