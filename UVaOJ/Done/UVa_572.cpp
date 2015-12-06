#include <stdio.h>
#include <string.h>
int n,m;
char g[200][200];
int vis[200][200],addx[3]={0,-1,1},addy[3]={0,-1,1};
void dfs(int x,int y)
{
	//printf("%d %d\n",x,y);
	vis[x][y]=1;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if(addx[i]!=0||addy[j]!=0)
				if(x+addx[i]>=0&&x+addx[i]<n&&y+addy[j]>=0&&y+addy[j]<m&&g[x+addx[i]][y+addy[j]]=='@'&&!vis[x+addx[i]][y+addy[j]])
				{
					//printf("%d %d %d %d\n",x,y,x+addx[i],y+addy[j]);
					dfs(x+addx[i],y+addy[j]);
				}
}
int main()
{
	int ans;
	while(scanf("%d%d",&n,&m)&&n)
	{
		memset(vis,0,sizeof(vis));
		ans=0;
		for(int i=0; i<n; i++)
			scanf("%s",g[i]);
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(!vis[i][j]&&g[i][j]=='@')
				{
					dfs(i,j);
					ans++;
				}
		printf("%d\n",ans);
	}
	return 0;
}
