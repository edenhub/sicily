#include <iostream>
#include <math.h>

using namespace std;

int cal(int year){
	int bit_len = 4<<(year-1960)/10;

	int n=1;
	double sum=0;

	for(int i=1;;i++){
		sum+=log(i);
		if(sum/log(2) > bit_len)
			break;
		n = i;
	}

	return n;
}

int main(){
	int year;

	while((cin>>year) && (year!=0)){
		cout<<cal(year)<<endl;
	}

	return 0;
}