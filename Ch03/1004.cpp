#include <iostream>
#include <algorithm>

#define N 21000

const double INF = 1e+15;
const double EPS = 1e-7;

using namespace std;

int dcom(double x,double y){
	if(x - y < -EPS) 
		return -1;
	if(x - y > EPS)
		return 1;

	return 0;
}

double min(double x,double y){
	return dcom(x,y) <=0 ? x : y;
}

double max(double x,double y){
	return dcom(x,y) <=0 ? y : x;
}

struct line{
	double k,b,pstartX,pendX;

	line(){}

	line(double x1,double y1,double x2,double y2){
		if(dcom(x1,x2)==0){
			k = INF;
			b = x1;
			pstartX = min(y1,y2);
			pendX = max(y1,y2);
		}else{
			k = (y2 - y1) / (x2 - x1);
			b = y1 - k*x1;
			pstartX = min(x1,x2);
			pendX = max(x1,x2);
		}
		
	}
};

bool lineCom(line l1,line l2){
	if(dcom(l1.k,l2.k) !=0 ) 
		return dcom(l1.k,l2.k) < 0;
	if(dcom(l1.b,l2.b) != 0)
		return dcom(l1.b,l2.b) < 0;

	return dcom(l1.pstartX,l2.pstartX) < 0;
}

line arr_line[N];

void calculate(int num){
	int cnt = 0;
	sort(arr_line,arr_line+num,lineCom);
	for(int i=1;i<num;i++){
		line lPre = arr_line[i-1];
		line lTail = arr_line[i];

		if(dcom(lPre.k,lTail.k) != 0)
			continue;

		if(dcom(lPre.b,lTail.b) != 0)
			continue;

		if(dcom(lPre.pstartX,lTail.pstartX) <=0 && dcom(lTail.pstartX,lPre.pendX) <=0)
			cnt++;
		else
			continue;
	}

	cout<<(num - cnt)<<endl;
}

int main(){
	int num;
	while((cin >> num) && (num!=0)){
		for(int i = 0;i<num;i++){
			double x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			arr_line[i] = line(x1,y1,x2,y2);
		}
		calculate(num);
	}
	return 0;
}

