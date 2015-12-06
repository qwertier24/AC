#include<stdio.h>
#include<string.h>
#define N 110
#define M 2010

int n;

int le[N],pe[M],ed[M],ev[M],ecnt;
void addEdge(int u,int v,int d){
	ecnt++;
	pe[ecnt]=le[u];
	le[u]=ecnt;
	ev[ecnt]=v;
	ed[ecnt]=d;
}

int cnt[N+10],inq[N],q[N],fr,rr,dist[N];
bool check(){
	memset(dist,0,sizeof(dist));
	memset(cnt,0,sizeof(cnt));
	memset(inq,0,sizeof(inq));
	fr=rr=0;
	for(int i=0; i<=n; i++)q[rr++]=i,inq[i]=1;
	while(fr!=rr){
		int u=q[fr++];
		inq[u]=0;
		//printf("%d %d\n",u,dist[u]);
		if(fr==N)fr=0;
		for(int i=le[u]; i; i=pe[i]){
			int &v=ev[i];
			if(dist[v]<dist[u]+ed[i]){
				dist[v]=dist[u]+ed[i];
				if(++cnt[v]>n)return false;
				if(!inq[v]){
					inq[v]=1;
					q[rr++]=v;
					if(rr==N)rr=0;
				}
			}
		}
	}
	return true;
}
int T,m;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		memset(le,0,sizeof(le));
		ecnt=0;
		scanf("%d%d",&n,&m);
		while(m--){
			int u,v,d;
			scanf("%d%d%d",&v,&u,&d);
			addEdge(u,v-1,-d);
			addEdge(v-1,u,d);
		}
		printf("%s\n",check()?"true":"false");
	}
	return 0;
}
