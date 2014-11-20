#include <iostream>

using namespace std;

int main(){

	for(int x = 0; x<=33;x++){
		for(int y = 0;y<=50;y++){
			for(int z=9;z<=100;z++){
				if((x+y+z)==100 && (9*x+6*y+z)==300)
					cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
			}
		}
	}
}