#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int ans=-1,g[1001][1001],n,g0[1001][1001];
inline int min(int a,int b)
{
	return a<b?a:b;
}
bool count(int x,int y)
{
	return ((g[x-1][y]+g[x][y-1]+g[x][y+1])%2==0);
}
int Step()
{
	int ret=0;
	for(int i=1; i<=n; i++)
		if(g[1][i]!=g0[1][i])
			ret++;
	return ret;
}
void solve(int deep)
{
	int steps=0;
	if(deep==n)
	{
		for (int i=2;i<=n ; i++)
		{
			for (int j=1; j<=n;j++ )
			{
				g[i][j]=g0[i][j];
			}
		}
		for (int i=1;i<=n-1 ; i++)
		{
			for (int j=1; j<=n;j++ )
			{
				if(count(i,j) && g0[i+1][j])
				{
					return;
				}
				else if(!count(i,j) && !g0[i+1][j])
				{
					steps++;
					g[i+1][j]=1;
				}
			}
		}
		for (int i=1; i<=n; i++)
		{
			if(!count(n,i))
				return;
		}
		if(ans==-1)
		{
			ans=steps+Step();
		}
		else
			ans=min(steps+Step(),ans);
	}
	else
	{
		int t=g[1][deep+1];
		solve(deep+1);
		if(!g[1][deep+1])
		{
			g[1][deep+1]++;
			solve(deep+1);
		}
		g[1][deep+1]=t;
	}
}
int main()
{
	int i,j;
	int T;
	scanf("%d",&T);
	for (i=1; i<=T; i++)
	{
		memset(g,0,sizeof(g));
		memset(g0,0,sizeof(g0));
		scanf("%d",&n);
		ans=-1;
		for (j=1; j<=n; j++)
			for(int k=1; k<=n; k++)
			{
				scanf("%d",&g[j][k]);
				g0[j][k]=g[j][k];
			}
		solve(1);
		if(!g[1][1])
		{
			g[1][1]++;
			solve(1);
		}
		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}
/*
Sample Input                             
1
3
0 0 0
0 0 0
0 0 0
1
3
0 0 0
1 0 0
0 0 0
1
3
1 1 1
1 1 1
0 0 0

Output for Sample Input	
Case 1: 0 
Case 2: 3 
Case 3: -1
*/