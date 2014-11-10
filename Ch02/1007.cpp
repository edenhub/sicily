#include <iostrem>

using namespace std;


void encrypted(int col,string& message){
	int height = message.length / col;

	for(int j=0;j<col;j++){
		for(int i=0;i<height;i++)
			cout<<message[i+j*5];
	}
}

int main(){
	string str = "toioynnkpheleaigshareconhtomesnlewx";

	encrypted(5,str);

	return 0;
}