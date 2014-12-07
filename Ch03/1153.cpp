#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

/** 
将位置向量表示出来，可以根据一个点的位置和位置向量判断一个点是否合适
主要思想：从一个点出发，找出一条可行的遍历路径，使用深搜
需要进行剪枝，对每个点的出度进行排序，优先搜索出度小的可行点
具体操作是计算并存储子节点出度，再对子节点按照出度排序，
由低到高进行遍历，特别注意子节点的存储空间要在DFS函数中动态申请，否则会出错。
**/

// 用于标记棋盘，判断是否走过
bool flag[8][8];
// 用于打印路径
int cicle[64];
// 移动向量
int directions[8][2] = {-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2,-2,-1};
// 判断一个点是否在棋盘内
bool isInTable(int x,int y){
	if((0<=x && x <=7) && (0<=y && y<=7))
		return true;
	return false;
}
// 判断一个点是否可以合理且未走过
bool isAbleOutput(int x,int y){
	if( isInTable(x,y) && !flag[x][y])
		return true;
	return false;
}
// 计算一个点可行的出度
int cauculateOutput(int x,int y){
	int outNum = 0;

	for(int i=0;i<8;i++){
		if (isAbleOutput((x+directions[i][0]),(y+directions[i][1])))
			outNum++;
	}

	return outNum;
}
// 结构体，用于表示位置
struct position
{
	// {x:横坐标;y:纵坐标;outNum:出度数}
	int x,y,outNum;

	// 默认出度为0
	position(){
		x = 0;
		y = 0;
		outNum = 0;
	}

	// 根据一个点计算出度
	position(int ax,int ay){
		x = ax;
		y = ay;
		outNum = cauculateOutput(ax,ay);
	}
};

// 比较两个点的出度大小，用于根据出度排序
bool cmp(position a,position b){
	return a.outNum < b.outNum;
}
// 将位置转为对应的数字
int positionToNum(position& po){
	return 8*po.x + po.y + 1;
}
// 将数字转为对应的位置
position numToPosition(int num){
	num = num -1;
	return position(num/8,num%8);
}
// 深搜求可行路径
// cicleIndex为走过的点的次数
bool dfs(position po,int cicleIndex){
	// 将初始位置添上
	cicle[cicleIndex] = positionToNum(po);
	// 标记初始位置走过
	flag[po.x][po.y] = true;
	// 如果全部走过则退出
	if(cicleIndex == 63)
		return true;
	// 用于存储出度的点，排序
	vector<position> outList;
	// 计算当前点的可行出度数，入队
	for(int i=0;i<8;i++){
		position p((po.x+directions[i][0]),(po.y+directions[i][1]));
		if(isAbleOutput(p.x,p.y))
			outList.push_back(p);
	}
	// 出度数进行排序
	sort(outList.begin(),outList.end(),cmp);
	// 根据出度数从小到大进行深搜，若符合则进行标记
	for(int i=0;i<outList.size();i++){
		if(dfs(outList[i],cicleIndex+1)) return true;
	}
	// 若未找到，则经过的位置取消标记
	flag[po.x][po.y] = false;
	return false;
}
// 输出结果
void displayCicle(){
	for(int i=0;i<64;i++)
		cout<<cicle[i]<<" ";
	cout<<endl;
}
// 主方法
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