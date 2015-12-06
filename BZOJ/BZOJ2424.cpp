#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

namespace nf{
#define N 110
#define M 500
#define INF (1<<30)
	int le[N],pe[M],ev[M],data[M],ecnt;
	int cost[M];
	void addEdge(int u,int v,int cap,int fe){
		pe[ecnt]=le[u];
		le[u]=ecnt;
		ev[ecnt]=v;
		data[ecnt]=cap;
		cost[ecnt]=fe;
		ecnt++;
		
		pe[ecnt]=le[v];
		le[v]=ecnt;
		ev[ecnt]=u;
		data[ecnt]=0;
		cost[ecnt]=-fe;
		ecnt++;
	}
	
	int S,T;
	void init(int s,int t){
		S=s,T=t;
		memset(le,-1,sizeof(le));
	}
	
	int dist[N];
	int q[N+10],inq[N],fr,rr,pre[N];
	int c,f;
	bool spfa(){
		memset(dist,0x3f,sizeof(dist));
		memset(inq,0,sizeof(inq));
		fr=rr=0;
		q[rr++]=S;
		dist[S]=0;
		inq[S]=1;
		while(fr!=rr){
			int u=q[fr++];
			inq[u]=0;
			if(fr==N)fr=0;
			for(int i=le[u]; i!=-1; i=pe[i])if(data[i]){
				int &v=ev[i];
				if(dist[v]-dist[u]>cost[i]){
					dist[v]=dist[u]+cost[i];
					pre[v]=i;
					if(!inq[v]){
						inq[v]=1;
						q[rr++]=v;
						if(rr==N)rr=0;
					}
				}
			}
		}
		if(dist[T]>=(1<<29))return false;
		
		int u=T,ft=INF;
		while(u!=S){
			ft=min(ft,data[pre[u]]);
			u=ev[pre[u]^1];
		}
		u=T;
		f+=ft;
		c+=ft*dist[T];
		while(u!=S){
			data[pre[u]]-=ft;
			data[pre[u]^1]+=ft;
			u=ev[pre[u]^1];
		}
		return true;
	}
	void mcmf(){
		c=f=0;
		while(spfa()); 
	}
}
using namespace nf;

int n,m,sz,fee[N],dem[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&sz);
	init(n,n+1);
	for(int i=0; i<n; i++){
		scanf("%d",&dem[i]);
		addEdge(i,T,dem[i],0);
	}
	for(int i=0; i<n; i++){
		scanf("%d",&fee[i]);
		addEdge(S,i,INF,fee[i]);
		if(i<n-1)
			addEdge(i,i+1,sz,m);
	}
	mcmf();
	printf("%d\n",c);
	return 0;
}

