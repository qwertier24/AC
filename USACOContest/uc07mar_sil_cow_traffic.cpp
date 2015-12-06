#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <cstring>
#define For(i,b,e) for(int (i)=(b); (i)<=(e); (i)++)
using namespace std;
vector<int> adj[5010],rev_adj[5010];
int d1[50010],d2[50010],sum[5010]={0};
int n,m;
struct Edge{
	int u,v,d;
}edges[50010];
int dfs1(int u){
//	printf("%d\n",u);
	if(sum[u])return sum[u];
	for(int i=0; i<rev_adj[u].size(); ++i){
		int e=rev_adj[u][i];
		d1[e]+=dfs1(edges[e].u);
		sum[u]+=d1[e];
	}
	if(rev_adj[u].size()==0)
		sum[u]=1;
	return sum[u];
}
int dfs2(int u){
	//printf("%d\n",u);
	if(sum[u])return sum[u];
	for(int i=0; i<adj[u].size(); ++i){
		int e=adj[u][i];
		d2[e]=dfs2(edges[e].v);
		sum[u]+=d2[e];
	}
	if(u==n)
		sum[u]=1;
	return sum[u];
}
int main(){
	freopen("prob.in","r",stdin);
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int f,t;
		scanf("%d%d",&f,&t);
		edges[i].u=f;
		edges[i].v=t;
		adj[f].push_back(i);
		rev_adj[t].push_back(i);
	}
	//printf("%d",adj[n].size());
	dfs1(n);
	memset(sum,0,sizeof(sum));
	for(int i=1; i<=n; i++)
		dfs2(i);
	int ans=0;
	For(i,1,m){
		//printf("%d %d %d %d\n",edges[i].u,edges[i].v,d1[i],d2[i]);
		ans=max(ans,d1[i]*d2[i]);
	}
	printf("%d",ans);
	return 0;
}

