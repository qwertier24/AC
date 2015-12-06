#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
#define N 3010
#define M 10010

int le[N],ev[M],pe[M],ecnt;
double e_dist[M],ed[M];
void addEdge(int u,int v,double d){
	ecnt++;
	pe[ecnt]=le[u];
	le[u]=ecnt;
	ed[ecnt]=d;
	ev[ecnt]=v;
}

int n,m;

int s,flag,vis[N];
double dist[N];
void dfs2(int u){
	vis[u]=1;
	for(int i=le[u]; i; i=pe[i])
		if(dist[ev[i]]>dist[u]+e_dist[i]){
			if(!vis[ev[i]]){
				dist[ev[i]]=dist[u]+e_dist[i];
				dfs2(ev[i]);
			}else flag=1;
			if(flag)break;
		}
	vis[u]=0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v;
		double d;
		scanf("%d%d%lf",&u,&v,&d);
		addEdge(u,v,d);
	}
	double lo=-1e7,hi=1e7;
	while(hi-lo>1e-10){
		double mi=(lo+hi)/2;
		flag=0;
		memset(dist,0,sizeof(dist));
		for(int i=1; i<=ecnt; i++)
			e_dist[i]=ed[i]-mi;
		for(int i=1; i<=n; i++){
			dfs2(i);
			if(flag)break;
		}
		if(flag)hi=mi;
		else lo=mi;
	}
	printf("%.8f\n",lo);
	return 0;
}

