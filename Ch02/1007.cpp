#include <iostream>

using namespace std;


void encrypted(int col,string& message){
	int rows = message.length()/col;
	cout<<rows<<" : "<<col<<endl;
	char matrix[rows][col];
	int index = 0;

	for(int j=0;j<rows;j++){
		if(j%2 == 0){
			for(int i = 0;j<col;j++){
				index++;
				cout<<message[index];
				matrix[i][j] = message[index];
			} 
		}else{
			for(int i=col-1;i>=0;i--){
				index++;
				cout<<message[index];
				matrix[i][j] = message[index++];
			}
		}
	}

	for(int i=0;i<col;i++)
		for(int j=0;j<rows;j++)
			cout<<matrix[j][i];

	cout<<endl;
}

int main(){
	string str = "toioynnkpheleaigshareconhtomesnlewx";

	encrypted(5,str);

	return 0;
}