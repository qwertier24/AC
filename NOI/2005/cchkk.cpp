#include<stdio.h>
#include<string.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;
#define N 1010

int deg[N],le[N],ev[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v){
	ecnt++;
	deg[u]++;
	pe[ecnt]=le[u];
	le[u]=ecnt;
	ev[ecnt]=v;
}

int nxt[N][N];
int q[N],fr,rr,dist[N];
void bfs(int s){
	fr=0,rr=-1;
	q[++rr]=s;
	memset(dist,-1,sizeof(dist));
	dist[s]=0;
	nxt[s][s]=s;
	while(fr<=rr){
		int &u=q[fr++];
		for(int i=le[u]; i; i=pe[i]){
			int &v=ev[i];
			if(dist[v]==-1){
				dist[v]=dist[u]+1;
				nxt[s][v]=u;
				q[++rr]=v;
			}
			if(dist[v]==dist[u]+1 && nxt[s][v]>u)
				nxt[s][v]=u;
		}
	}
}

double d[N][N];
double dp(int u,int v){
	if(d[u][v]!=-1.0)return d[u][v];
	if(u==v)return d[u][v]=0.0;
	if(nxt[u][nxt[u][v]]==u)return d[u][v]=1.0;
	d[u][v]=0;
	for(int i=le[u]; i; i=pe[i]){
		int &ut=ev[i];
		d[u][v]+=dp(ut,nxt[u][nxt[u][v]]);
	}
	d[u][v]+=dp(u,nxt[u][nxt[u][v]]);
	d[u][v]/=(deg[u]+1);
	d[u][v]++;
	return d[u][v];
}

int n,m,u0,v0;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	scanf("%d%d",&u0,&v0);
	REP(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	REP(i,1,n)bfs(i);
	REP(i,1,n)REP(j,1,n)d[i][j]=-1.0;
	printf("%.3f",dp(v0,u0));
	return 0;
}

