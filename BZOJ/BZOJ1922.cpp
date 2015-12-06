#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
#define PROB
#define N 3030
#define M 70070
#define For(i,n) for(int i=1; i<=n; i++)
#define INF (1<<30)
using namespace std;

int le[N],pe[M],ev[M],ed[M],ecnt;
void addEdge(int u,int v,int d){
	ecnt++;
	pe[ecnt]=le[u];
	le[u]=ecnt;
	ev[ecnt]=v;
	ed[ecnt]=d;
}

int n,m,in0[N],cnt[N];
vector<int> adj[N];

int mark[N],dist1[N],dist2[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	For(i,n)in0[i]=1;
	For(i,m){
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		addEdge(u,v,d);
	}
	For(i,n){
		scanf("%d",&cnt[i]);
		For(j,cnt[i]){
			int t;
			scanf("%d",&t);
			adj[t].push_back(i);
			in0[i]=0;
		}
	}
	For(i,n)if(in0[i])
		mark[i]=1;
	For(i,n)dist1[i]=0,dist2[i]=INF;
	dist1[1]=0;
	dist2[1]=0;
	For(loop,n){
		int mind=INF,u;
		For(i,n)if(mark[i] && max(dist1[i],dist2[i])<mind){
			mind=max(dist1[i],dist2[i]);
			u=i;
		}
		for(int i=le[u]; i; i=pe[i])
			dist2[ev[i]]=min(dist2[ev[i]],mind+ed[i]);
			
		mark[u]=0;
		for(int i=0; i<adj[u].size(); i++){
			dist1[adj[u][i]]=max(mind,dist1[adj[u][i]]);
			cnt[adj[u][i]]--;
			if(cnt[adj[u][i]]==0)mark[adj[u][i]]=1;
		}
	}
	printf("%d\n",max(dist1[n],dist2[n]));
	return 0;
}

