#include <iostream>
#include <cstdio>
#include <math.h>
#include <memory.h>

#define N 14

/**
二分法求方程组解
1.二分结束判定：low+EPS<hight
2.四舍五入表示：%0.5f
3.注意最后是否需要多输出空行 count>1
**/
using namespace std;

const double EPS = 1e-7;

int months[N];
double amounts[N];

double find(int n){
	double low = 0.0,hight = 1.0;
	double mid = 0;
	while(low+EPS < hight){
		mid = (low + hight) / 2;
		double sum = 0.0;
		for(int j=0;j<n;j++){
			sum += amounts[j] *  pow((1+mid),(months[n] -months[j] + 1));
		}

		if(sum < amounts[n]){
			low = mid;
		}else{
			hight = mid;
		}
	}

	return mid;
}

int main(){
	int index=1;

	while(true){
		memset(months,0,sizeof(months));
		memset(amounts,0,sizeof(amounts));
		int num;
		cin>>num;
		if(num == -1) break;
		for(int j=0;j<num+1;j++){
			cin>>months[j];
			cin>>amounts[j];
		}

		double r = find(num);
		if(index>1)
			printf("\n");
		printf("Case %d: %0.5f\n",index,r);
		index++;
	}

	return 0;
}