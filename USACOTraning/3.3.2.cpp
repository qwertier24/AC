/*
ID: mayukun3
PROG: fence
LANG: C++
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> ans,adj[501];
int g[501][501]={0},m,n;
void dfs(int u)
{
	ans.push_back(u);
	for(int i=0;i<adj[u].size(); i++)
		if(g[adj[u][i]][u])
		{
			g[adj[u][i]][u]--;
			g[u][adj[u][i]]--;
			dfs(adj[u][i]);
		}
}
bool cmp(const int& a,const int& b)
{
	return a<b;
}
int main()
{
	freopen("fence.in","r",stdin);freopen("fence.out","w",stdout);
	scanf("%d",&m);
	for(int i=1; i<=m; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		g[u][v]++;
		g[v][u]++;
	}
	int s=1;
	for(int i=1; i<=500; i++)
		sort(adj[i].begin(),adj[i].end(),cmp);
	for(int i=1; i<=500; i++)
		if(adj[i].size()%2)
		{
			s=i;
			break;
		}
	dfs(s);
	for(int i=0; i<ans.size(); i++)
		printf("%d\n",ans[i]);
	/*
	for(int i=ans.size()-1; i>=0; i--)
		printf("%d\n",ans[i]);
	*/
	return 0;
}