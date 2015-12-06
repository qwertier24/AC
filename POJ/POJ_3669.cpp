#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#define INF 1<<30
const int n=309,m=309;
using namespace std;
int t[320][320];
int addx[4]={-1,0,1,0},addy[4]={0,1,0,-1},d[320*320],vis[320*320];
queue<int> q;
bool check(int x,int y,int dist)
{
	if(!vis[x*m+y]&&x>=0&&x<n&&y>=0&&y<m&&dist<t[x][y])
		return true;
	else
		return false;
}
int bfs(int p)
{
	d[p]=0;
	memset(vis,0,sizeof(vis));
	vis[p]=1;
	bool flag=false;
	int ret;
	q.push(p);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		int x=u/m,y=u%m;
		//printf("  %d %d %d %d\n",x,y,d[u],t[x][y]);
		if(t[x][y]==INF)
		{
			//printf("%d %d %d\n",x,y,t[x][y]);
			flag=true;
			ret=d[u];
			break;
		}
		for(int i=0; i<4; i++)
			if(check(x+addx[i],y+addy[i],d[u]+1))
			{
				int v=(x+addx[i])*m+y+addy[i];
				vis[v]=1;
				d[v]=d[u]+1;
				q.push(v);
			}
	}
	if(flag)
		return ret;
	else
		return -1;
}
int main()
{
	int k;
	scanf("%d",&k);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			t[i][j]=INF;
	for(int i=1; i<=k; i++)
	{
		int x,y,T;
		scanf("%d%d%d",&x,&y,&T);
		t[x][y]=min(T,t[x][y]);
		for(int i=0; i<4; i++)
			if(x+addx[i]>=0&&y+addy[i]>=0)
			t[x+addx[i]][y+addy[i]]=min(t[x+addx[i]][y+addy[i]],T);
	}
	printf("%d\n",bfs(0));
	return 0;
}
