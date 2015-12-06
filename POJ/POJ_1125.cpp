#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#define INF 1<<28
using namespace std;
int n;
struct Edge
{
	int u,d;
	bool operator<(const Edge& rhs)const
	{
		return d>rhs.d;
	}
};
vector<int> adj[101],path[101];
int DIJK(int s)
{
	int done[101]={0},d[101];
	for(int i=1; i<=n; i++)
		d[i]=INF;
	d[s]=0;
	priority_queue<Edge> pq;
	pq.push((Edge){s,0});
	while(!pq.empty())
	{
		Edge e=pq.top();
		pq.pop();
		if(done[e.u])continue;
		done[e.u]=1;
		for(int i=0; i<adj[e.u].size(); i++)
		{
			int v=adj[e.u][i];
			if(d[v]>d[e.u]+path[e.u][i])
			{
				d[v]=d[e.u]+path[e.u][i];
				pq.push((Edge){v,d[v]});
			}
		}
	}
	int ret=0;
	for(int i=1; i<=n; i++)
		if(i!=s)
			ret=max(ret,d[i]);
	return ret;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		int min_depth=INF,s_p;
		for(int i=1; i<=n; i++)
		{
			adj[i].clear();
			path[i].clear();
			int nt;
			scanf("%d",&nt);
			for(int j=1; j<=nt; j++)
			{
				int t,d;
				scanf("%d%d",&t,&d);
				adj[i].push_back(t);
				path[i].push_back(d);
			}
		}
		for(int i=1; i<=n; i++)
		{
			int depth=DIJK(i);
			if(min_depth>depth)
			{
				min_depth=depth;
				s_p=i;
			}
		}
		printf("%d %d\n",s_p,min_depth);
	}
	return 0;
}
