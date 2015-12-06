#include<stdio.h>
#define M 200010
#define N 100010

int n,m;

int le[N],ev[M],ed[M],pe[M],ecnt;
void addEdge(int u,int v,int d){
	ecnt++;
	pe[ecnt]=le[u];
	le[u]=ecnt;
	ev[ecnt]=v;
	ed[ecnt]=d;
}

int fr,rr,q[N+10],cnt[N],inq[N];
long long dist[N];
long long spfa(){
	for(int i=1; i<=n; i++){q[rr++]=i;cnt[i]=1;inq[i]=1;}
	while(fr!=rr){
		int u=q[fr++];
		if(fr==N)fr=0;
		inq[u]=0;
		for(int i=le[u]; i; i=pe[i]){
			int &v=ev[i];
			if(dist[v]<dist[u]+ed[i]){
				dist[v]=dist[u]+ed[i];
				if(!inq[v]){
					if(++cnt[v]>n)return -1;
					inq[v]=1;
					q[rr++]=v;
					if(rr==N)rr=0;
				}
			}
		}
	}
	long long ret=0;
	for(int i=1; i<=n; i++)
		ret+=dist[i];
	return ret+n;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	while(m--){
		int x,u,v;
		scanf("%d%d%d",&x,&u,&v);
		switch(x){
		case 1:
			addEdge(u,v,0);
			addEdge(v,u,0);
			break;
		case 2:
			addEdge(u,v,1);
			break;
		case 3:
			addEdge(v,u,0);
			break;
		case 4:
			addEdge(v,u,1);
			break;
		case 5:
			addEdge(u,v,0);
			break;
		}
	}
	printf("%lld\n",spfa());
	return 0;
}
