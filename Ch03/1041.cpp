#include <iostream>
#include <memory.h>
#include <algorithm>

#define N 20
using namespace std;

struct position{
	int x,y;

	position(){
		x = y =0;
	}

	position(int a_x,int a_y){
		x = a_x;
		y = a_y;
	}
};

position box[N];

void dumpBox(int n,int index){
	cout<<"Data set "<<index<<" ends with boxes at locations ";
	for(int i=0;i<n;i++){
		if(i !=0)
			cout<<" ";
		cout<<"("<<box[i].x<<","<<box[i].y<<")";
	}
	cout<<"."<<endl;
}

int maxRowStep(int width,int height,int n){
	int max = 0;

	for(int i=0;i<width;i++){
		int num = 0;
		for(int j = 0;j<n;j++){
			if(box[j].x == i)
				num++;
		}

		if(num > max) max = num;
	}
	return height - max;

}

int maxColStep(int width,int height,int n){
	int max = 0;
	for(int i=0;i<height;i++){
		int num=0;
		for(int j=0;j<n;j++){
			if(box[j].y == i)
				num++;
		}

		if(num > max) max = num;
	}

	return width - max;
}

bool cmpRight(position a,position b){
	if(a.x != b.x)
		return a.x < b.x;
	else
		return a.y < b.y;
}

bool cmpLeft(position a,position b){
	if(a.x != b.x)
		return a.x < b.x;
	else
		return a.y > b.y;
}

bool cmpUp(position a,position b){
	if(a.y!=b.y)
		return a.y < b.y;
	else
		return a.x > b.x;
}

bool cmpDown(position a,position b){
	if(a.y!=b.y)
		return a.y<b.y;
	else
		return a.x < b.x;
}

void moveRight(int off,int n,int width,int height){
	// int maxColOff = maxColStep(width,height,n);
	// off = min(maxColOff,off);
	int maxRowOff = maxRowStep(width,height,n);
	off = min(maxRowOff,off);
	sort(box,box+n,cmpRight);
	int x=-1,y;
	for(int i=0;i<n;i++){
		if(box[i].x != x){
			x = box[i].x;
			y = off;
		}else{
			y++;
		}

		if(box[i].y < y){
			box[i].y = y;
		}
	}
}

void moveLeft(int off,int n,int width,int height){
	// int maxColOff = maxColStep(width,height,n);
	// off = min(maxColOff,off);
	int maxRowOff = maxRowStep(width,height,n);
	off = min(maxRowOff,off);
	sort(box,box+n,cmpLeft);
	int x=-1,y;
	for(int i=0;i<n;i++){
		if(box[i].x != x){
			x = box[i].x;
			y = width - off -1;
		}else{
			y--;
		}

		if(box[i].y > y){
			box[i].y = y;
		}
	}
}

void moveDown(int off,int n,int width,int height){
	// int maxRowOff = maxRowStep(width,height,n);
	// off = min(maxRowOff,off);
	int maxColOff = maxColStep(width,height,n);
	off = min(maxColOff,off);
	sort(box,box+n,cmpDown);
	int y=-1,x;
	for(int i=0;i<n;i++){
		if(box[i].y != y){
			y = box[i].y;
			x = off;
		}else{
			x++;
		}

		if(box[i].x < x){
			box[i].x = x;
		}
	}
}

void moveUp(int off,int n,int width,int height){
	// int maxRowOff = maxRowStep(width,height,n);
	// off = min(maxRowOff,off);
	int maxColOff = maxColStep(width,height,n);
	off = min(maxColOff,off);
	sort(box,box+n,cmpUp);
	int y=-1,x;
	for(int i=0;i<n;i++){
		if(box[i].y != y){
			y = box[i].y;
			x = height - off -1;
		}else{
			x--;
		}

		if(box[i].x > x){
			box[i].x = x;
		}
	}
}

void init(int width,int height,int index){
	memset(box,0,sizeof(box));
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>box[i].y>>box[i].x;
	}
	// int maxRowOff = maxRowStep(width,height,n);
	// int maxColOff = maxColStep(width,height,n);
	string op;
	int off;
	while((cin>>op) && (op!="done")){
		cin>>off;
		if(op == "right"){
			// off = min(maxColOff,off);
			moveRight(off,n,width,height);
		}else if(op == "left"){
			// off = min(maxColOff,off);
			moveLeft(off,n,width,height);
		}else if(op == "down"){
			// off = min(maxRowOff,off);
			moveDown(off,n,width,height);
		}else if(op == "up"){
			// off = min(maxRowOff,off);
			moveUp(off,n,width,height);
		}
	}
	dumpBox(n,index);
}

int main(){
	int width,height,index=0;
	while((cin>>height>>width) && (height!=0))
		init(width,height,++index);
	return 0;
}