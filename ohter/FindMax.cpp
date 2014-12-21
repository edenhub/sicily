#include <stdio.h>
#include <stdlib.h>

#define N 100

int array[N],rMax,rMin;

void MaxMin(int front,int end,int Max,int Min){
	if(front == end){
		Max = array[end];
		Min = array[front];
	}else{
		int Max1,Max2,Min1,Min2,m;
		m = (end - front) /2 + front;
		MaxMin(front,m,Max1,Min1);
		MaxMin(m,end,Max2,Min2);

		Max = Max1 > Max2 ? Max1 : Max2;
		Min = Min1 > Min2 ? Min2 : Min1;
	}
}

int main(){

	return 0;
}