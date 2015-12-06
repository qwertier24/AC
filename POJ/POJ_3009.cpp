#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#define INF 1<<20
using namespace std;
int g[50][50],vis[50][50],addx[4]={-1,0,1,0},addy[4]={0,1,0,-1},n,m,ans;
bool check(int x,int y)
{
	if(x>=1&&x<=n&&y>=1&&y<=m)
		return true;
	else
		return false;
}
void dfs(int x,int y,int deep)
{
	if(g[x][y]==3)
	{
		ans=min(ans,deep);
		//printf("  %d\n",deep);
		return;
	}
	if(deep==10)
		return;
	//printf("%d %d %d\n",x,y,deep);
	for(int i=0; i<4; i++)
	{
		int xt=x,yt=y;
		while(check(xt,yt)&&(g[xt][yt]==0||vis[xt][yt]))
			xt+=addx[i],yt+=addy[i];
		if(check(xt,yt))
		{
			if(g[xt][yt]==1&&(xt-addx[i]!=x||yt-addy[i]!=y))
			{
				vis[xt][yt]=1;
				dfs(xt-addx[i],yt-addy[i],deep+1);
				vis[xt][yt]=0;
			}
			else if(g[xt][yt]==3)
				dfs(xt,yt,deep+1);
		}
	}
	/*
	while(xt>=1&&(g[xt][yt]==0||vis[xt][yt]))
		xt--;
	if(xt>=1)
	{
		vis[xt][yt]=1;
		dfs(xt+1,yt,deep+1);
		vis[xt][yt]=0;
	}
	xt=x,yt=y;
	while(xt<=n&&(g[xt][yt]==0||vis[xt][yt]))
		xt++;
	if(xt<=n)
	{
		vis[xt][yt]=1;
		dfs(xt-1,yt,deep+1);
		vis[xt][yt]=0;
	}
	xt=x,yt=y;
	while(yt>=1&&(g[xt][yt]==0||vis[xt][yt]))
		yt--;
	if(yt>=1)
	{
		vis[xt][yt]=1;
		dfs(xt,yt+1,deep+1);
		vis[xt][yt]=0;
	}
	xt=x,yt=y;
	while(yt<=m&&(g[xt][yt]==0||vis[xt][yt]))
		yt++;
	if(yt<=m)
	{
		vis[xt][yt]=1;
		dfs(xt,yt-1,deep+1);
		vis[xt][yt]=0;
	}
	*/
}
int main()
{
	while(scanf("%d%d",&m,&n)&&m)
	{
		ans=INF;
		memset(vis,0,sizeof(vis));
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				scanf("%d",&g[i][j]);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				if(g[i][j]==2)
				{
					vis[i][j]=1;
					dfs(i,j,0);
				}
		printf("%d\n",ans==INF?-1:ans);
	}
	return 0;
}
