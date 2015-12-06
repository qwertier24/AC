#include <stdio.h>
#include <string.h>
#define MAXN 1001
int SUM[1001],n,g[MAXN][MAXN],f[MAXN][MAXN],d[MAXN][MAXN];
inline int sum(int l,int r)
{
	return SUM[r]-SUM[l-1];
}
inline int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	while(scanf("%d",&n) && n)
	{
		memset(SUM,0,sizeof(SUM));
		memset(d,0,sizeof(d));
		memset(g,0,sizeof(g));
		memset(f,0,sizeof(f));
		for(int i=1; i<=n; i++)
		{
			int t;
			scanf("%d",&t);
			SUM[i]=SUM[i-1]+t;
		}
		for(int length=1; length<=n; length++)
		{
			for(int i=1; i+length-1<=n; i++)
			{
				int j=i+length-1;
				int m=0;
				m=min(m,f[i][j-1]);
				m=min(m,g[i+1][j]);
				d[i][j]=sum(i,j)-m;
				//printf("I:%d J:%d D:%d F[%d][%d]:%d G[%d][%d]:%d\n",i,j,d[i][j],i,j-1,f[i][j-1],i+1,j,g[i+1][j]);
				f[i][j]=min(f[i][j-1],d[i][j]);
				g[i][j]=min(g[i+1][j],d[i][j]);
			}
		}
		printf("%d\n",2*d[1][n]-sum(1,n));
	}
	return 0;
}
