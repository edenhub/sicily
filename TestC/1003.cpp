#include <iostream>
#include <stdio.h>
#include <algorithm>

#define MAX 101

using namespace std;

int dp[MAX][MAX];
char x[MAX],y[MAX];

void cal(int lenA,int lenB){
	int i,j;

	for(int i=0;i<=lenA;i++) dp[i][0] = 0;
	for(int j=0;j<=lenB;j++) dp[0][j] = 0;

	for(int i=1;i<=lenA;i++){
		for(int j=1;j<=lenB;j++){
			if(x[i-1] == y[j-1]){
				dp[i][j] = dp[i-1][j-1] +1;
			}else{
				dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
			}
		}
	} 
}


int main(){
	int lenA,lenB;
	while(scanf("%d %d %s %s",&lenA,&lenB,x,y)!=EOF){
		cal(lenA,lenB);
		cout<<dp[lenA][lenB]<<endl;
	}

	return 0;
}