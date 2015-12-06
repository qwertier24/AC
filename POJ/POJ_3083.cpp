#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3
using namespace std;
int addx[4]={0,-1,0,1},addy[4]={-1,0,1,0},n,m,g[50][50],vis[50*50],d[50*50],s,e;
int match(char t)
{
	if(t=='#')
		return -1;
	else if(t=='.')
		return 0;
	else if(t=='S')
		return 1;
	else
		return 2;
}
bool check(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]!=-1)
		return true;
	else
		return false;
}
int dfs(int x,int y,int dir,int opt)
{
	if(g[x][y]==2)
		return 1;
	if(g[x+addx[((dir+opt)%4+4)%4]][y+addy[((dir+opt)%4+4)%4]]!=-1)
		dir=((dir+opt)%4+4)%4;
	else if(g[x+addx[dir]][y+addy[dir]]==-1&&check(x+addx[((dir-opt)%4+4)%4],y+addy[((dir-opt)%4+4)%4]))
		dir=((dir-opt)%4+4)%4;
	else if(g[x+addx[dir]][y+addy[dir]]==-1)
		dir=(dir+2)%4;
	//printf("%d %d %d %d\n",x,y,dir,opt);
	return dfs(x+addx[dir],y+addy[dir],dir,opt)+1;
}
int bfs(int p0)
{
	memset(vis,0,sizeof(vis));
	d[p0]=1;
	vis[p0]=1;
	queue<int> q;
	q.push(p0);
	while(!q.empty())
	{
		int p=q.front();
		if(p==e)
			break;
		q.pop();
		int x=p/m,y=p%m;
		for(int i=0; i<4; i++)
			if(check(x+addx[i],y+addy[i])&&!vis[(x+addx[i])*m+y+addy[i]])
			{
				vis[(x+addx[i])*m+y+addy[i]]=1;
				q.push((x+addx[i])*m+y+addy[i]);
				d[(x+addx[i])*m+y+addy[i]]=d[p]+1;
			}
	}
	return d[e];
}
int main()
{
	//freopen("prob.out","w",stdout);
	int T;
	char str[59];
	scanf("%d",&T);
	while(T--)
	{
		memset(g,-1,sizeof(g));
		scanf("%d%d",&m,&n);
		for(int i=0; i<n; i++)
		{
			scanf("%s",str);
			for(int j=0; j<m; j++)
			{
				g[i][j]=match(str[j]);
				if(g[i][j]==1)
					s=i*m+j;
				else if(g[i][j]==2)
					e=i*m+j;
			}
		}
		//printf("OK");
		printf("%d %d %d\n",dfs(s/m,s%m,LEFT,-1),dfs(s/m,s%m,RIGHT,1),bfs(s));
	}
	return 0;
}
