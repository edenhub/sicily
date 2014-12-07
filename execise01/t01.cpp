#include <iostream>
#include <math.h>
using namespace std;

void calculate(int a,int b,int c){
	int temp = b*b - 4*a*c;
	double partA = (double)(-b)/(2*a);

	if(temp >0 ){
		double partB = (double)sqrt(temp)/(2*a);
		cout<<(partA - partB)<<endl;
	}else if(temp == 0){
		cout<<partA<<endl;
	}else{
		
	}
}

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	calculate(a,b,c);
}
