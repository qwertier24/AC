#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int bp,addx[4]={0,0,-1,1},addy[4]={1,-1,0,0},vis[2000000]={0},dist[2000000],g[1010][1010]={0},cnt=0;
bool check(int x,int y){
	return x>=0&&y>=0&&x<1001&&y<1001&&!vis[x*1001+y]&&!g[x][y];
}
int bfs(int p0){
	queue<int> q;
	q.push(p0);
	vis[p0]=1;
	dist[p0]=0;
	while(!q.empty()){
		int p=q.front();
		q.pop();
		int x=p/1001,y=p%1001;
		//printf("%d %d %d\n",x,y,dist[p]);
		for(int i=0; i<4; i++){
			int xt=x+addx[i],yt=y+addy[i];
			if(check(xt,yt)){
				int pt=xt*1001+yt;
				q.push(pt);
				vis[pt]=1;
				dist[pt]=dist[p]+1;
				if(pt==bp){
					//printf("%d %d\n",pt,dist[pt]);
					return dist[pt];
				}
			}
		}
		cnt++;
	}
	return 1;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
	//freopen("prob.out","w",stdout);
#endif
	int xt,yt,n;
	scanf("%d%d%d",&xt,&yt,&n);
	xt+=500,yt+=500;
	bp=xt*1001+yt;
	for(int i=1; i<=n; i++){
		scanf("%d%d",&xt,&yt);
		xt+=500,yt+=500;
		g[xt][yt]=1;
	}
	printf("%d",bfs(500*1001+500));
	return 0;
}
