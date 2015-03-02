#include <stdio.h>
#include <iostream>

using namespace std;

int ex_gcd(int a,int b,int *x,int *y){
	if(b==0){
		*x = 1;
		*y = 0;
		return a;
	}else{
		long long tmp = ex_gcd(b,a%b,y,x);
		*y -= (*x)*(a/b);
		return tmp;
	}
}

int modular(int a,int b,int n){
	int x,y,x0,i;
	int k;
	int g=ex_gcd(a,n,&x,&y);
	if(b%g) return 0;

	k = b/g;
	x0 = (k*x)%n;
	int cnt=0;
	for(int i=0;i<=g;i++){
		int res = (x0+i*(n/g))%n;
		if(res>=0) cnt++;
	}
		// printf("%d\n",(x0+i*(n/g))%n);
	return cnt;

}

int main(){
	int a,b,n;

	while(scanf("%d%d%d",&a,&b,&n)!=EOF)
		cout<<modular(a,b,n)<<endl;

	return 0;
}