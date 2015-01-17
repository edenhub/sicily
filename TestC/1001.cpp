#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void findL(int len,int i){
	int x,y,z;

	vector<vector<int> > resSet;

	for(x=0;x<len;x++){
		for(y=x;y<len;y++){
			z=len-x-y;

			if(1<=x && x*x + y*y == z*z){
				vector<int> res;

				res.push_back(x);
				res.push_back(y);
				res.push_back(z);

				sort(res.begin(),res.end());
				resSet.push_back(res);
				cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;				
			}
		}
	}

}

int main(){
	int num;
	cin>>num;

	for(int i=0;i<num;i++){
		int n;
		cin>>n;

		findL(n,i);
		cout<<endl;
	}
	return 0;
}