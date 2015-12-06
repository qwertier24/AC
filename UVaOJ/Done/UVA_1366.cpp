#include <stdio.h>
#include <string.h>
inline int max(int a,int b)
{
	return a>b?a:b;
}
int cA[501][501],rB[501][501],d[501][501];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)&&n)
	{
		memset(cA,0,sizeof(cA));
		memset(rB,0,sizeof(rB));
		memset(d,0,sizeof(d));
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
			{
				int A;
				scanf("%d",&A);
				cA[i][j]=cA[i][j-1]+A;
			}
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
			{
				int B;
				scanf("%d",&B);
				rB[j][i]=rB[j][i-1]+B;
			}
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				d[i][j]=max(d[i][j-1]+rB[j][i],d[i-1][j]+cA[i][j]);
		printf("%d\n",d[n][m]);
	}
	return 0;
}
