#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
#include <iostream>
#define INF 0xfffffffffffffffl
using namespace std;
struct PAIR
{
	int a,b;
	bool operator<(const PAIR& rhs)const
	{
		return a<rhs.a||(a==rhs.a&&b<rhs.b);
	}
};
struct HeapNode
{
	int u;
	long long d;
	bool operator<(const HeapNode& rhs)const
	{
		return d>rhs.d;
	}
};
vector<int> adj[100001];
int done[100001]={0},last_step[100001]={0};
long long d[100001];
map<PAIR,int> mp;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++)
	{
		int f,t,wt;
		scanf("%d%d%d",&f,&t,&wt);
		if(!mp.count((PAIR){f,t}))
		{
			adj[f].push_back(t);
			adj[t].push_back(f);
			mp[(PAIR){f,t}]=wt;
			mp[(PAIR){t,f}]=wt;
		}
		else
			mp[(PAIR){f,t}]=mp[(PAIR){t,f}]=min(mp[(PAIR){f,t}],wt);
	}
	priority_queue<HeapNode> pq;
	for(int i=2; i<=n; i++)
		d[i]=INF;
	d[1]=0;
	last_step[1]=1;
	pq.push((HeapNode){1,0});
	while(!pq.empty())
	{
		int u=pq.top().u;
		pq.pop();
		if(u==n)
			break;
		if(done[u])
			continue;
		done[u]=1;
		for(int i=0; i<adj[u].size(); i++)
		{
			int v=adj[u][i];
			if(d[v]>d[u]+mp[(PAIR){u,v}])
			{
				d[v]=d[u]+mp[(PAIR){u,v}];
				pq.push((HeapNode){v,d[v]});
				last_step[v]=u;
			}
		}
	}
	if(last_step[n]==0)
	{
		printf("-1");
	}
	else
	{
		int cur=n;
		vector<int> ans;
		ans.push_back(cur);
		while(last_step[cur]!=cur)
		{
			cur=last_step[cur];
			ans.push_back(cur);
		}
		for(int i=ans.size()-1; i>=0; i--)
			printf("%d ",ans[i]);
	}
	return 0;
}