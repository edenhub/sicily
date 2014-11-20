#include <iostream>
#include <memory.h>

using namespace std;

// 位置结构体
typedef struct position{
	// 0<= x <=4; 1<= y <=6
	int  x,y;

	position(int ax,int ay){
		x = ax;
		y = ay;
	}
}po;

// 移动位置数组
po directions[8]= {
	position(1,-2),position(2,-1),position(2,1),position(1,2),
	position(-1,2),position(-2,1),position(-2,-1),position(-1,-2)
};

// 是否访问过
int visited[30];

// 转化为位置
po toPosition(int num){
	return position(num/6,num%6);
}

// 转化为数字
int toNumber(const po& p){
	return 6*p.x + p.y;
}

// 打印位置
void dumpPosition(const po& p){
	cout<<"("<<p.x<<","<<p.y<<")"<<endl;
}

// 移动位置
po move(const po& src,const po& dir){
	return po(src.x+dir.x,src.y+dir.y);
}

// 判断两个位置是否相同
bool isPositionEqual(const po& src,const po& dest){
	if((src.x == dest.x) && (dest.y == dest.y))
		return true;
	return false;
}

// 判断该位置是否在棋盘内
bool isInTable(const po& p){
	if((0<= p.x && p.x <=4) && (1<= p.y && p.y<=6))
		return true;
	return false;
}

// 周游
void travel(int start){
	memset(visited,0,sizeof(visited));
}

int main(){
	po p(2,3);
	cout<<toNumber(p)<<endl;
	dumpPosition(toPosition(15));

	return 0;
}