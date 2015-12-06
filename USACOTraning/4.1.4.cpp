/*
ID: mayukun3
PROG: fence6
LANG: C++
*/
#include <stdio.h>
#include <map>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;
map<pair<int,int>,int> mp;
int pn=0,visiting[110]={0},visited[110]={0},ans=1<<30,dt[110]={0};
struct road
{
	int v,d;
};
vector<road> adj[201];
void dfs(int u,int dist,int f)
{
	//printf("%d %d\n",u,dist);
	visiting[u]=1;
	dt[u]=dist;
	for(int i=0; i<adj[u].size(); i++)
		if(adj[u][i].v!=f)
		{
			int v=adj[u][i].v,d=adj[u][i].d;
			if(visiting[v])
			{
				ans=min(ans,dt[u]-dt[v]+d);
				continue;
			}
			dfs(v,dist+d,u);
		}
	visiting[u]=0;
}

int main()
{
	freopen("fence6.in","r",stdin);
	freopen("fence6.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		int lp,rp,length,ln,rn,t[10],f;
		scanf("%d%d%d%d",&f,&length,&ln,&rn);
		bool done=false;
		for(int j=1; j<=ln; j++)
			scanf("%d",&t[j]);
		if(!mp.count(make_pair(f,t[1])))
		{
			++pn;
			for(int j=1; j<=ln; j++)
			{
				mp[make_pair(f,t[j])]=pn;
				mp[make_pair(t[j],f)]=pn;
				for(int k=1; k<=ln; k++)
					if(k!=j)
						mp[make_pair(t[j],t[k])]=pn;
			}
		}
		lp=mp[make_pair(f,t[1])];
		for(int j=1; j<=rn; j++)
			scanf("%d",&t[j]);
		if(!mp.count(make_pair(f,t[1])))
		{
			++pn;
			for(int j=1; j<=rn; j++)
			{
				mp[make_pair(f,t[j])]=pn;
				mp[make_pair(t[j],f)]=pn;
				for(int k=1; k<=rn; k++)
					if(k!=j)
						mp[make_pair(t[j],t[k])]=pn;
			}
		}
		rp=mp[make_pair(f,t[1])];
		adj[lp].push_back((road){rp,length});
		adj[rp].push_back((road){lp,length});
	}
	for(int i=1; i<=pn; i++)
		dfs(i,0,0);
	printf("%d\n",ans);
}
