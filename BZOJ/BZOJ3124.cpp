#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB
#define N 200010
#define For(i,n) for(int i=1; i<=n; i++)
typedef long long LL;
using namespace std;

int le[N],ev[N<<1],ecnt,pe[N<<1],ed[N<<1];
void addEdge(int u,int v,int d){
	ecnt++;
	pe[ecnt]=le[u];
	le[u]=ecnt;
	ev[ecnt]=v;
	ed[ecnt]=d;
}

int pre[N],vis[N];
LL dist[N];
int q[N],fr,rr;
int bfs(int s){
	fr=rr=0;
	q[fr]=s;
	dist[s]=0;
	vis[s]=1;
	int ret=s;
	while(fr<=rr){
		int &u=q[fr++];
		if(dist[u]>dist[ret])ret=u;
		for(int i=le[u]; i; i=pe[i]){
			int &v=ev[i];
			if(!vis[v]){
				dist[v]=dist[u]+ed[i];
				vis[v]=1;
				pre[v]=u;
				q[++rr]=v;
			}
		}
	}
	return ret;
}

int n;
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	For(i,n-1){
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		addEdge(u,v,d);
		addEdge(v,u,d);
	}
	int L=bfs(1);
	memset(vis,0,sizeof(vis));
	memset(pre,0,sizeof(pre));
	int R=bfs(L);
	memset(vis,0,sizeof(vis));
	printf("%lld\n",dist[R]);
	for(int i=R; i; i=pre[i])
		vis[i]=1;
	for(int i=R; i; i=pre[i]){
		int tmp=dist[i];
		int maxd=dist[bfs(i)];
		dist[i]=tmp;
		if(maxd==dist[R]-dist[i])
			R=i;
		if(maxd==dist[i]-dist[L]){
			L=i;
			pre[i]=0;
		}
	}
	int ans=0;
	for(int i=R; i!=L; i=pre[i])
		ans++;
	printf("%d\n",ans);
	return 0;
}

