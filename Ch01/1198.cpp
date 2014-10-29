#include <iostream>

#define N 8

using namespace std;
/*
判断条件为compare的内容
*/
bool compare(string &a,string &b){
	return a+b <= b+a;
}

void exchange(string &a,string &b){
	string temp = a;
	a = b;
	b = temp;
}

int partition(string subStrings[],int p,int r){
	string pivot = subStrings[r];
	int i = p-1;
	
	//i纪录了当前小于pivot的位置，且之前的数都小于pivot
	//当出现小于pivot的数时，将i之前的数交换跟当前的数交换便可以保持i的作用
	//最后将pivot的放到i前面，使得pivot起到隔离的作用
	//放回pivot的位置

	for(int j=p;j<r;j++){
		if(compare(subStrings[j],pivot)){
			i++;
			exchange(subStrings[i],subStrings[j]);
		}
	}

	exchange(subStrings[i+1],subStrings[r]);

	return i+1;
}

void quicksort(string subStrings[],int p,int r){
	if(p<r){
		int q = partition(subStrings,p,r);
		quicksort(subStrings,p,q-1);
		quicksort(subStrings,q+1,r);
	}
}

int main(){
	int testCases,subStringsNumber;
	string subStrings[N],temp;

	cin>>testCases;

	for(int i=0;i<testCases;i++){
		cin>>subStringsNumber;

		for(int j=0;j<subStringsNumber;j++)
			cin>>subStrings[j];

		quicksort(subStrings,0,subStringsNumber-1);

		for(int j=0;j<subStringsNumber;j++)
			cout<<subStrings[j];
		cout<<endl;
	}

	return 0;
}