#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int d[110][110],cost[110],num[110],n;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d%d",&num[i],&cost[i]);
		d[n][n]=(num[n]+10)*cost[n];
		for(int i=n-1; i>=1; i--)
		{
			d[i][i]=(num[i]+10)*cost[i]+d[i+1][i+1];
			for(int j=i+2; j<=n; j++)    //d[i][i]
				d[i][i]=min(d[i][i],d[i+1][j]+(num[i]+10)*cost[i]);
			for(int j=i+1; j<=n; j++)
				d[i][j]=d[i+1][j]+num[i]*cost[j];
		}
		int ans=1<<30;
		for(int i=1; i<=n; i++)
			ans=min(ans,d[1][i]);
		printf("%d\n",ans);
	}
	return 0;
}
