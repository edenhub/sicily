#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

bool flag[5][6];
int cicle[30];

int directions[8][2] = {-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2,-2,-1};

bool isInTable(int x,int y){
	if((0<=x && x <=4) && (0<=y && y<=5))
		return true;
	return false;
}

bool isAbleOutput(int x,int y){
	if( isInTable(x,y) && !flag[x][y])
		return true;
	return false;
}

int cauculateOutput(int x,int y){
	int outNum = 0;

	for(int i=0;i<8;i++){
		if (isAbleOutput((x+directions[i][0]),(y+directions[i][1])))
			outNum++;
	}

	return outNum;
}

struct position
{
	int x,y,outNum;

	position(){
		x = 0;
		y = 0;
		outNum = 0;
	}

	position(int ax,int ay){
		x = ax;
		y = ay;
		outNum = cauculateOutput(ax,ay);
	}
};

bool cmp(position a,position b){
	return a.outNum < b.outNum;
}

int positionToNum(position& po){
	return 6*po.x + po.y + 1;
}

position numToPosition(int num){
	num = num -1;
	return position(num/6,num%6);
}

bool dfs(position po,int cicleIndex){
	// cout<<"here1"<<endl;
	cicle[cicleIndex] = positionToNum(po);
	flag[po.x][po.y] = true;
	if(cicleIndex == 29)
		return true;

	vector<position> outList;
	for(int i=0;i<8;i++){
		position p((po.x+directions[i][0]),(po.y+directions[i][1]));
		if(isAbleOutput(p.x,p.y))
			outList.push_back(p);
	}

	sort(outList.begin(),outList.end(),cmp);

	for(int i=0;i<outList.size();i++){
		if(dfs(outList[i],cicleIndex+1)) return true;
	}

	flag[po.x][po.y] = false;
	return false;
}

void displayCicle(){
	for(int i=0;i<30;i++)
		cout<<cicle[i]<<" ";
	cout<<endl;
}

int main(){
	int num;
	while((cin>>num) && (num!=-1)){
		memset(flag,false,sizeof(flag));
		position start = numToPosition(num);
		dfs(start,0);
		displayCicle();
	}

	return 0;
}