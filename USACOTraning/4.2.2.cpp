/*
ID: mayukun3
PROG: ditch
LANG: C++
*/
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#define INF 1<<30
using namespace std;
int S=1,T,m,n;
struct Edge
{
	int u,v,cap,flow;
};
vector<Edge> edges;
vector<int> G[400];
int vis[210],d[210],cur[210];
void AddEdge(int from,int to,int cap)
{
	edges.push_back((Edge){from,to,cap,0});
	edges.push_back((Edge){to,from,0,0});
	G[from].push_back(edges.size()-2);
	G[to].push_back(edges.size()-1);
}
int bfs()
{
	queue<int> q;
	memset(vis,0,sizeof(vis));
	q.push(S);
	d[S]=0;
	vis[S]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		//printf("%d %d\n",u,d[u]);
		for(int i=0; i<G[u].size(); i++)
		{
			Edge e=edges[G[u][i]];
			if(!vis[e.v]&&e.cap>e.flow)
			{
				q.push(e.v);
				vis[e.v]=1;
				d[e.v]=d[u]+1;
			}
		}
	}
	return vis[T];
}
int dfs(int u,int a)
{
	int flow=0,f;
	if(u==T||a==0)
		return a;
	for(int& i=cur[u]; i<G[u].size(); i++)
	{
		Edge& e=edges[G[u][i]];
		if(d[e.v]==d[u]+1&&(f=dfs(e.v,min(e.cap-e.flow,a)))>0)
		{
			flow+=f;
			//printf("%d %d %d\n",u,edges[G[u][i]].v,f);
			edges[G[u][i]].flow+=f;
			edges[1^G[u][i]].flow-=f;
			a-=f;
			if(a==0)
				break;
		}
	}
	return flow;
}
int max_flow()
{
	int ret=0;
	while(bfs())
	{
		memset(cur,0,sizeof(cur));
		ret+=dfs(S,INF);
		//printf("%d\n",ret);
	}
	return ret;
}
int main()
{
	//freopen("ditch.in","r",stdin);freopen("ditch.out","w",stdout);
    scanf("%d%d",&m,&n);
	//printf("%d",m);
	T=n;
	for(int i=1; i<=m; i++)
	{
		int from,to,cap;
		scanf("%d%d%d",&from,&to,&cap);
		if(from!=to)
		AddEdge(from,to,cap);
		//printf("%d %d\n",G[from].size(),G[to].size());
	}
	printf("%d\n",max_flow());
}
