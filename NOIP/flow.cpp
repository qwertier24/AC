#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <cstring>
#define l first
#define r second
#define Rep(i,n) for(int i=0; i<n; i++)
#define For(i,b,e) for(int i=b; i<=e; i++)
#define PROB "flow"
using namespace std;
struct P{
	int x,y;
	P(int a,int b){
		x=a,y=b;
	}
};
typedef pair<int,int> Interval;
int addx[4]={0,0,-1,1},addy[4]={1,-1,0,0},vis[510][510]={0},n,m,g[510][510],cur,by;
Interval interval[510];
bool check(int x,int y){
	return x>=0&&x<n&&y>=0&&y<m&&!vis[x][y];
}
void dfs(int x,int y){
	vis[x][y]=1;
//	printf("%d %d %d\n",x,y,by);
	Rep(i,4){
		int xt=x+addx[i],yt=y+addy[i]; 
		if(check(xt,yt)&&g[xt][yt]>g[x][y]){
			//printf("  %d %d\n",xt,yt);
			if(vis[xt][yt])
				continue;
			dfs(xt,yt);
		}
	}
	if(x==0){
		if(cur)
			interval[y].r=by;
		else
			interval[y].l=by;
	}
}
void bfs(int x0,int y0){
	queue<P> q;
	q.push(P(x0,y0));
	vis[x0][y0]=1;
	while(!q.empty()){
		P p=q.front();
		q.pop();
		int x=p.x,y=p.y;
		Rep(i,4)
			if(check(x+addx[i],y+addy[i])&&g[x+addx[i]][y+addy[i]]<g[x][y]){
				P t(x+addx[i],y+addy[i]);
				vis[t.x][t.y]=1;
				q.push(t);
			}
	}
}
int can(){
	Rep(i,m)
		bfs(0,i);
	int ret=0;
	Rep(i,m)
		if(vis[n-1][i])
			ret++;
	return ret;
}
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d%d",&n,&m);
	Rep(i,n)
		Rep(j,m)
			scanf("%d",&g[i][j]);
	int t=can();
	if(t<m)
		printf("0\n%d",m-t);
	else{
		memset(vis,0,sizeof(vis));
		Rep(i,m)
			if(!vis[n-1][i]){
				cur=0;
				by=i;
				dfs(n-1,i);
			}
		memset(vis,0,sizeof(vis));
		for(int i=m-1; i>=0; i--)
			if(!vis[n-1][i]){
				cur=1;
				by=i;
				dfs(n-1,i);
			}
		sort(interval,interval+m);
		cur=0;
		int p=0,ans=0;
		while(cur<m){
			int t=0;
			while(p<m&&interval[p].l<=cur)
				t=max(t,interval[p].r),p++;
			cur=t+1;
			ans++;
		}
		printf("1\n%d",ans);
	}
	return 0;
}

