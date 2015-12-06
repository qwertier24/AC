#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#define PROB "tractor"
using namespace std;
int vis[1010][1010]={0},dist[1010][1010]={0},addx[4]={0,0,-1,1},addy[4]={-1,1,0,0},g[1010][1010];
queue<int> qx,qy;
bool check(int x,int y){
	return x>=0&&y>=0&&x<=1001&&y<=1001&&!vis[x][y];
}
void dfs(int x0,int y0,int d){
	//printf("%d %d\n",x0,y0);
	queue<int> qxt,qyt;
	qxt.push(x0);
	qyt.push(y0);
	while(qxt.size()){
		int x=qxt.front(),y=qyt.front();
		//printf("%d %d\n",x,y);
		qxt.pop();
		qyt.pop();
		dist[x][y]=d;
		vis[x][y]=1;
		qx.push(x);
		qy.push(y);
		for(int i=0; i<4; i++)
			if(check(x+addx[i],y+addy[i])&&!g[x][y]){
				qxt.push(x+addx[i]);
				qyt.push(y+addy[i]);
				vis[x+addx[i]][y+addy[i]]=1;
			}
	}
}
int bfs(int x0,int y0){
	dfs(x0,y0,0);
	while(!qx.empty()){
		int x=qx.front(),y=qy.front();
		if(x==1&&y==1)return dist[x][y];
		qx.pop();
		qy.pop();
		//printf("%d %d\n",x,y);
		for(int i=0; i<4; i++)
			if(check(x+addx[i],y+addy[i])){
				dfs(x+addx[i],y+addy[i],dist[x][y]+1);
			}
	}
}
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	int n,x0,y0,x,y;
	scanf("%d%d%d",&n,&x0,&y0);
	for(int i=1; i<=n; i++){
		scanf("%d%d",&x,&y);
		g[x][y]=1;
	}
	printf("%d",bfs(x0,y0));
	return 0;
}

