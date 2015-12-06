#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<map>
#include<string>
#include<string.h>
#include<stdlib.h>
#include <vector>
#define INF 1<<30
using namespace std;
int a[5001],b[5001],d[5001][5001]={0};
char dir[5001][5001];
int ans[5010];
inline int dist(int i,int j)
{
	return abs(a[i]-b[j]);
}
int main()
{
	int n,m;
	//freopen("prob.txt","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		for(int i=1; i<=m; i++)
			scanf("%d",&b[i]);
		for(int i=1; i<=n; i++)
			d[i][0]=INF;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
			{
				if(d[i-1][j-1]<d[i-1][j])
				{
					dir[i][j]=-1;
					d[i][j]=d[i-1][j-1]+dist(i,j);
				}
				else
				{
					dir[i][j]=0;
					d[i][j]=d[i-1][j]+dist(i,j);
				}
			}
		printf("%d\n",d[n][m]);
		int p=m;
		for(int i=n; i>=1; i--)
		{
			ans[i]=p;
			p+=dir[i][p];
		}
		printf("%d",ans[1]);
		for(int i=2; i<=n; i++)
			printf(" %d",ans[i]);
		printf("\n");
	}
	//while(1);
	return 0;
}
