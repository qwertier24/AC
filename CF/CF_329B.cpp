#include <stdio.h>
#include <queue>
#include <stdlib.h>
#include <ctype.h>
#define INF 1<<30
using namespace std;
int vis[1010*1010]={0},addx[4]={-1,0,1,0},addy[4]={0,1,0,-1},d[1010*1010],m,n;
char g[1010][1010];
bool check(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m&&!vis[x*m+y]&&g[x][y]!='T')
		return true;
	else
		return false;
}
int bfs(int p0)
{
	int ans=0;
	queue<int> q;
	q.push(p0);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			d[i*m+j]=INF;
	d[p0]=0;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		//printf("%d %d %d\n",p/m,p%m,d[p]);
		int x=p/m,y=p%m;
		for(int i=0; i<4; i++)
			if(check(x+addx[i],y+addy[i]))
			{
				int pt=(x+addx[i])*m+y+addy[i];
				vis[pt]=1;
				d[pt]=d[p]+1;
				q.push(pt);
			}
	}
	int min_d;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(g[i][j]=='S')
				min_d=d[i*m+j];
	//printf("\n");
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(isdigit(g[i][j])&&d[i*m+j]<=min_d)
			{
				//printf("%d %d %d\n",i,j,g[i][j]-'0');
				ans+=g[i][j]-'0';
			}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)
		scanf("%s",g[i]);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(g[i][j]=='E')
			{
				//printf("%d %d\n",i,j);
				printf("%d",bfs(i*m+j));
			}
	return 0;
}
