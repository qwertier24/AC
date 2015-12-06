#include <stdio.h>
#include <queue>
#include <cstring>
#define INF 1<<30
using namespace std;
int vis[50][50][50],d[50][50][50],h,n,m,addx[6]={-1,1,0,0,0,0},addy[6]={0,0,-1,1,0,0},addz[6]={0,0,0,0,-1,1};
char g[50][50][50];
bool check(int x,int y,int z)
{
	if(x>=1&&x<=h&&y>=1&&y<=n&&z>=1&&z<=m&&!vis[x][y][z]&&g[x][y][z]!='#')
		return true;
	else
		return false;
}
void bfs(int x0,int y0,int z0)
{
	queue<int> qx,qy,qz;
	qx.push(x0);
	qy.push(y0);
	qz.push(z0);
	d[x0][y0][z0]=0;
	memset(vis,0,sizeof(vis));
	while(!qx.empty())
	{
		int x=qx.front(),y=qy.front(),z=qz.front();
		qx.pop(),qy.pop(),qz.pop();
		for(int i=0; i<6; i++)
		{
			if(check(x+addx[i],y+addy[i],z+addz[i]))
			{
				vis[x+addx[i]][y+addy[i]][z+addz[i]]=1;
				d[x+addx[i]][y+addy[i]][z+addz[i]]=d[x][y][z]+1;
				qx.push(x+addx[i]);
				qy.push(y+addy[i]);
				qz.push(z+addz[i]);
			}
		}
	}
}
int main()
{
	char s[100];
	while(scanf("%d%d%d",&h,&n,&m)&&n)
	{
	for(int i=1; i<=h; i++)
		for(int j=1; j<=n; j++)
		{
			scanf("%s",s);
			for(int k=0; k<m; k++)
			{
				g[i][j][k+1]=s[k];
				d[i][j][k+1]=INF;
			}
		}
	for(int i=1; i<=h; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=m; k++)
				if(g[i][j][k]=='S')
					bfs(i,j,k);
	for(int i=1; i<=h; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=m; k++)
				if(g[i][j][k]=='E')
				{
					if(d[i][j][k]!=INF)
						printf("Escaped in %d minute(s).\n",d[i][j][k]);
					else
						printf("Trapped!\n");
				}
	}
	return 0;
}