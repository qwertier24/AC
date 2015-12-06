#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int m,n,vis[310][310]={0},addx[4]={0,-1,0,1},addy[4]={1,0,-1,0},g[310][310];
int ans=0;
struct BLOCK
{
	int x,y,h;
	bool operator<(const BLOCK& rhs)const
	{
		return h>rhs.h;
	}
};
priority_queue<BLOCK> pq;
bool check(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=m&&!vis[x][y];
}
void dfs(int x,int y,int max_h)
{
	int t=ans;
	ans+=max_h-g[x][y];
	//printf(" %d %d %d %d\n",x,y,max_h,ans-t);
	pq.push((BLOCK){x,y,g[x][y]});
	g[x][y]=max_h;
	vis[x][y]=1;
	for(int i=0; i<4; i++)
	{
		if(check(x+addx[i],y+addy[i]))
		{
			int xt=x+addx[i],yt=y+addy[i];
			if(g[xt][yt]<=max_h)
				dfs(xt,yt,max_h);
			else
				pq.push((BLOCK){xt,yt,g[xt][yt]});
		}
	}
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d",&g[i][j]);
	for(int i=1; i<=n; i++)
	{
		pq.push((BLOCK){i,1,g[i][1]});
		pq.push((BLOCK){i,m,g[i][m]});
	}
	for(int i=1; i<=m; i++)
	{
		pq.push((BLOCK){1,i,g[1][i]});
		pq.push((BLOCK){n,i,g[n][i]});
	}
	while(!pq.empty())
	{
		BLOCK low=pq.top();
		pq.pop();
		if(!vis[low.x][low.y])
			dfs(low.x,low.y,low.h);
	}
	printf("%d\n",ans);
	return 0;
}
