#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int n,resuming_v,q,kill[101],cost[101],t,d[101][101],ans;
int main()
{
	cost[0]=0;
	kill[0]=1;
	while(scanf("%d%d%d",&n,&resuming_v,&q)&&(n||resuming_v||q))
	{
		memset(d,0,sizeof(d));
		bool found=false;
		ans=10000;
		for(int i=1; i<=n; i++)
			scanf("%d%d",&cost[i],&kill[i]);
		t=99/q+1;
		for(int i=1; i<=t&&!found; i++)
			for(int j=0; j<=100; j++)
			{
				for(int k=0; k<=n; k++)
				{
					if(j+cost[k]<=100)
						d[i][j]=max(d[i][j],d[i-1][max(j+cost[k]-resuming_v,0)]+kill[k]);
					if(j+cost[k]==100)
						d[i][j]=max(d[i][j],d[i-1][j]);
				}
				if(d[i][j]>=100)
				{
					found=true;
					ans=i;
					break;
				}
			}
		if(ans==10000)
			printf("My god\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
