#include <stdio.h>
#include <string.h>
int g[50][50];
long long d[50][50][501];
inline int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n,S;
	while(true)
	{
		scanf("%d %d",&n,&S);
		if(!n)return 0;
		memset(d,0,sizeof(d));
		for(int i=1; i<2*n; i++)
			for(int j=1; j<=max(i-n+1,n-i+1); j++)
				scanf("%d",&g[2*n-i][j]);
		for(int i=1; i<=n; i++)
			d[1][i][g[1][i]]=1;
		for(int i=2; i<=n; i++)
			for(int j=1; j<=n-i+1; j++)
				for(int k=g[i][j]; k<=S; k++)
					d[i][j][k]=d[i-1][j][k-g[i][j]]+d[i-1][j+1][k-g[i][j]];
		for(int i=n+1; i<2*n; i++)
			for(int j=1; j<=i-n+1; j++)
				for(int k=g[i][j]; k<=S; k++)
					d[i][j][k]=(j==1?0:d[i-1][j-1][k-g[i][j]]) + (j==i-n+1?0:d[i-1][j][k-g[i][j]]);
		long long ans=0;
		for(int i=1; i<=n; i++)
			ans+=d[2*n-1][i][S];
		printf("%lld\n",ans);
		int p=1;
		while(!d[2*n-1][p][S] && p<=n)p++;
		if(p<=n)
		{
			printf("%d ",p-1);
			S-=g[2*n-1][p];
			for(int i=2*n-2; i>=n; i--)
			{
				if(d[i][p-1][S])
				{
					p--;
					printf("L");
				}
				else
					printf("R");
				S-=g[i][p];
			}
			for(int i=n-1; i>=1; i--)
			{
				if(!d[i][p][S])
				{
					p++;
					printf("R");
				}
				else
					printf("L");
				S-=g[i][p];
			}
		}
		printf("\n");
	//printf("ok\n");
	}
	return 0;
}
/*
6 41
6 7 2 3 6 8
1 8 0 7 1
2 6 5 7
3 1 0
7 6
8
8 8
6 5 3
9 5 9 5
6 4 4 1 3
2 6 9 4 3 8
*/