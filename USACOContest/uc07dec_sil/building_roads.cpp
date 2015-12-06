#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
int G[1010][1010]={0},g[1010][1010],vis[1010]={0},blk_cnt=0,inside[1010],n,m,pa[1010];
double dist[1010][1010];
struct Farm{
	double x,y;
}f[1010];
struct Edge{
	int u,v;
	double d;
	bool operator<(const Edge& rhs)const{
		return d<rhs.d;
	}
};
vector<Edge> edges,es;
double get_dist(Farm& a,Farm& b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void dfs(int u){
	vis[u]=1;
	inside[u]=blk_cnt;
	for(int i=1; i<=n; i++)
		if(g[u][i]&&!vis[i])
			dfs(i);
}
int findset(int u){
	if(pa[u]!=u)
		pa[u]=findset(pa[u]);
	return pa[u];
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		cin>>f[i].x>>f[i].y;
	for(int i=1; i<=m; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1;
	}
	for(int i=1; i<=n; i++)
		if(!vis[i]){
			blk_cnt++;
			pa[blk_cnt]=blk_cnt;
			dfs(i);
		}
	for(int i=1; i<=n; i++)
		for(int j=1; j<i; j++)
			if(inside[i]!=inside[j])
				edges.push_back((Edge){i,j,get_dist(f[i],f[j])});
	sort(edges.begin(),edges.end());
	for(int i=0; i<edges.size(); i++){
		int u=edges[i].u,v=edges[i].v;
		double d=edges[i].d;
		if(!G[inside[u]][inside[v]]&&inside[u]!=inside[v]){
			//printf("%d %d %lf\n",u,v,get_dist(f[u],f[v]));
			g[inside[u]][inside[v]]=1;
			es.push_back((Edge){inside[u],inside[v],d});
		}
	}
	double ans=0;
	for(int i=0; i<es.size(); i++)
		if(findset(es[i].u)!=findset(es[i].v)){
			pa[pa[es[i].u]]=pa[es[i].v];
			//printf("%lf %lf\n",ans+es[i].d,es[i].d);
			ans+=es[i].d;
		}
	//printf("%lf\n",ans);
	cout<<fixed<<setprecision(2)<<ans;
	return 0;
}
