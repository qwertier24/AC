#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int up[1001][1001],right[1001][1001],left[1001][1001];
inline int max(int a,int b)
{
	return a>b?a:b;
}
inline int min(int a,int b)
{
	return a<b?a:b;
}
int getnum()
{
	char t;
	while(true)
	{
		t=getchar();
		if(t=='F' || t=='R')
			break;
	}
	if(t=='R')return 0;
	else return 1;
}
int m,n,g[1001][1001];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int ans=0;
		scanf("%d%d",&m,&n);
		memset(left,0,sizeof(left));
		memset(right,0,sizeof(right));
		memset(up,0,sizeof(up));
		for (int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
			{
				g[i][j]=getnum();
				//printf("%d %d %d\n",i,j,g[i][j]);
			}
		for (int i=1; i<=m; i++)
		{
			int lo=0;
			for(int j=1; j<=n; j++)
			{
				if(g[i][j])
				{
					up[i][j]=i==up[i-1][j]+1;
					left[i][j]=max(left[i-1][j],lo+1);
					//printf("%d %d %d\n",i,j,left[i][j]);
				}
				else
					lo=j;
			}
		}
		for (int i=1; i<=m; i++)
		{
			int ro=n+1;
			for(int j=n; j>=1; j--)
			{
				if(g[i][j])
				{
					right[i][j]=i==1?ro-1:min(right[i-1][j],ro-1);
					//printf("%d %d %d\n",i,j,right[i][j]);
				}
				else
				{
					ro=j;
					right[i][j]=n;
				}
			}
		}
		printf("%d %d %d\n",left[5][5],right[5][5],up[5][5]);
		for (int i=1; i<=m; i++)
		{
			for (int j=1; j<=n; j++)
			{
				ans=max(ans,(right[i][j]-left[i][j]+1) * up[i][j]);
			}
		}
		printf("%d\n",ans*3);
	}
	return 0;
}
