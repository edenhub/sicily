// Problem#: 1152
// Submission#: 1774802
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool flag[5][6];
int ans[30];
int dir[8][2] = {-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2,-2,-1};

inline bool judge(int x, int y){
    return x>=0 && x<5 && y>=0 && y <6 && !flag[x][y];
}

inline int degree(int a, int b){
    int re = 0;
    int x,y;
    for(int i = 0;i < 8;i++){  
        x = a + dir[i][0];  
        y = b + dir[i][1];  
        if(judge(x,y)) re++;  
    }  
    return re;
}

struct node{
    int x,y,c;
    node(){
    x = y = c = -1;
    }
    node(int a, int b){
    x = a;
    y = b;
    c = degree(a,b);
    }
};


inline bool cmp(node a, node b){
    return a.c<b.c;
}

inline node find(int n){
    node re;
    int x = (n-1) / 6;
    int y = (n-1) % 6;
    re = node(x,y);
    return re;
}

inline node calcu(node a,int c){
    node re;
    int x = a.x + dir[c][0];
    int y = a.y + dir[c][1];
    re = node(x,y);
    return re;
}

bool dfs(node a, int c){
    node t;
    vector<node> buffer;
    flag[a.x][a.y] = true;
    ans[c] = 6*a.x + a.y + 1;
    if( c == 29 ) return true;
    for( int i=0 ; i<8 ; i++ ){
    t = calcu(a,i);
    if(judge(t.x,t.y)) buffer.push_back(t);
    }
    sort(buffer.begin(),buffer.end(),cmp);
    for( int i=0 ; i<buffer.size() ; i++ )
    if( dfs(buffer[i],c+1) ) return true;
    flag[a.x][a.y] = false;
    return false;
}

int main(){
    int n;
    while( cin>>n && n>0 ){
    memset(flag,0,sizeof(flag));
    node s = find(n);
    dfs(s,0);
    cout << n;
    for( int i=1 ; i<30 ; i++ )
        cout << " " << ans[i];
    cout << endl;
    }
    return 0;
}