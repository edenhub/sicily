#include <iostream>
#include <stdio.h>
#include <memory.h>

#define N 110
using namespace std;

int num[N][N][N];
int edge[N][N];
int n,m,l,q;

int solve(int &A,int &B){
	memset(num,0,sizeof(num));
	num[0][A][A] = 1;
	for(int k=1;k<=l;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(edge[j][i])
				num[k][A][i] += num[k-1][A][j];
			}
		}
	}

	return num[l][A][B];
}


int main(){
	// while((scanf("%d",&n)) && n!= EOF){
		scanf("%d%d%d",&n,&m,&l);
		// cin>>m>>l;
		memset(edge,0,sizeof(edge));

		for(int i=0;i<m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			// cin>>x>>y;
			edge[x-1][y-1]=1;
		}

		scanf("%d",&q);
		// cin>>q;

		for(int i=0;i<q;i++){
			int A,B;
			scanf("%d%d",&A,&B);
			// cin>>A>>B;
			A = A -1;
			B = B -1;
			printf("%d\n",solve(A,B));
			// cout<<solve(A-1,B-1)<<endl;
		}
	// }

	return 0;
}