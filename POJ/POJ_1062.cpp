#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#include <iostream>
#include <cstring>
#define INF 1<<28
using namespace std;
int d[101],path[101][101],lv[101],done[101],tlv,blv;
struct EDGE
{
	int u,d;
	bool operator<(const EDGE& rhs)const
	{
		return d>rhs.d;
	}
};
inline bool check(int v)
{
	return (lv[v]>=blv&&lv[v]<=tlv);
}
int main()
{
	int gap,n,ans=INF;
	scanf("%d%d",&gap,&n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			path[i][j]=INF;
	for(int i=1; i<=n; i++)
	{
		int nt;
		scanf("%d%d%d",&path[0][i],&lv[i],&nt);
		for(int j=1; j<=nt; j++)
		{
			int tt,pt;
			scanf("%d%d",&tt,&pt);
			path[tt][i]=min(path[tt][i],pt);
		}
	}
	for(int b=1; b<=n; b++)
	{
		memset(done,0,sizeof(done));
		blv=lv[b];
		tlv=lv[b]+gap;
		for(int i=1; i<=n; i++)
			d[i]=INF;
		d[0]=0;
		priority_queue<EDGE> pq;
		pq.push((EDGE){0,d[0]});
		while(!pq.empty())
		{
			EDGE e=pq.top();
			pq.pop();
			if(done[e.u])
				continue;
			//printf("%d %d\n",e.u,d[e.u]);
			done[e.u]=1;
			for(int v=1; v<=n; v++)
				if(check(v))
				{
					if(d[v]>d[e.u]+path[e.u][v])
					{
						d[v]=d[e.u]+path[e.u][v];
						pq.push((EDGE){v,d[v]});
					}
				}
		}
		//printf("%d %d %d %d\n",b,blv,tlv,d[1]);
		ans=min(ans,d[1]);
	}
	printf("%d\n",ans);
	return 0;
}
