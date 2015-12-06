#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int cost[30][30],n,vis[1<<20];
int cost_sum(int S)
{
	//printf("%d %d\n",S);
	int ret=0;
	for(int i=0; i<n; i++)
		if((S>>i)&1)
			for(int j=0; j<n; j++)
				if(!((S>>j)&1))
					ret+=cost[i][j];
	return ret;
}
int main()
{
	int ans=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d",&cost[i][j]);
	for(int i=1; i<(1<<n); i++)
	{
		if(vis[(1<<n-1)^i])continue;
		vis[i]=1;
		ans=max(ans,cost_sum(i));
	}
	printf("%d\n",ans);
	return 0;
}
