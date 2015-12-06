#include <stdio.h>
#include <cstring>
int addx[4]={-1,0,1,0},addy[4]={0,1,0,-1},g[20][20],d[20][20],vis[20][20];
int Dir(char t)
{
	if(t=='N') return 0;
	else if(t=='E') return 1;
	else if(t=='S') return 2;
	else return 3;
}
int main()
{
	char str[100];
	int n,m,s;
	while(scanf("%d%d%d",&n,&m,&s)&&n)
	{
		for(int i=1; i<=n; i++)
		{
			scanf("%s",str);
			for(int j=0; j<m; j++)
				g[i][j+1]=Dir(str[j]);
		}
		int x=1,y=s;
		d[x][y]=0;
		memset(vis,0,sizeof(vis));
		while(true)
		{
			vis[x][y]=1;
			int xt=x+addx[g[x][y]],yt=y+addy[g[x][y]];
			if(xt<1||xt>n||yt<1||yt>m)
			{
				printf("%d step(s) to exit\n",d[x][y]+1);
				break;
			}
			else if(vis[xt][yt])
			{
				printf("%d step(s) before a loop of %d step(s)\n",d[xt][yt],d[x][y]+1-d[xt][yt]);
				break;
			}
			d[xt][yt]=d[x][y]+1;
			x=xt,y=yt;
		}
	}
	return 0;
}
