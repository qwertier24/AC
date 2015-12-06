#include<stdio.h>
#include<string.h>
#include<algorithm>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;
#define N 710

int le[N],ev[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v){
	ecnt++;
	pe[ecnt]=le[u];
	le[u]=ecnt;
	ev[ecnt]=v;
}

namespace nf{
	int le[30],ev[900],cost[900],pe[900],data[900],ecnt;
	void addEdge(int u,int v,int c){
		pe[ecnt]=le[u];
		le[u]=ecnt;
		cost[ecnt]=c;
		data[ecnt]=1;
		ev[ecnt]=v;
		ecnt++;
		
		pe[ecnt]=le[v];
		le[v]=ecnt;
		cost[ecnt]=-c;
		data[ecnt]=0;
		ev[ecnt]=u;
		ecnt++;
	}
	
	int S,T,sz;
	
	int ret;
	int dist[30],pre[30],inq[30],fr,rr,q[30];
	bool spfa(){
		memset(dist,0x7f,sizeof(dist));
		fr=rr=0;
		q[rr++]=S;
		inq[S]=1;
		dist[S]=0;
		while(fr!=rr){
			int u=q[fr++];inq[u]=0;
			if(fr==30)fr=0;
			for(int i=le[u]; i!=-1; i=pe[i]){
				if(!data[i])continue;
				int &v=ev[i];
				if(dist[v]>dist[u]+cost[i]){
					dist[v]=dist[u]+cost[i];
					pre[v]=i;
					if(!inq[v]){
						inq[v]=1;
						q[rr++]=v;
						if(rr==30)rr=0;
					}
				}
			}
		}
		if(dist[T]>=(1<<30))return false;
		ret+=dist[T];
		int u=T;
		while(u!=S){
			data[pre[u]]--;
			data[1^pre[u]]++;
			u=ev[1^pre[u]];
		}
		return true;
	}
	int solve(){
		ret=0;
		int cnt=0;
		while(spfa()){
			cnt++;
			if(cnt>sz)std::exit(-1);
		}
		return cnt==sz?ret:-1;
	}
	void init(int SZ){
		memset(le,-1,sizeof(le));
		ecnt=0;
		sz=SZ;
		S=0,T=SZ*2+1;
	}
}

int n,a[N],b[N];
int son1[N][20],son2[N][20],d[N][N];
void dp(int u1,int u2,int fa1,int fa2){
	son1[u1][0]=son2[u2][0]=0;
	for(int i=le[u1]; i; i=pe[i]){
		int &v=ev[i];
		if(v!=fa1)son1[u1][++son1[u1][0]]=v;
	}
	for(int i=le[u2]; i; i=pe[i]){
		int &v=ev[i];
		if(v!=fa2)son2[u2][++son2[u2][0]]=v;
	}
	if(son1[u1][0]!=son2[u2][0])return;
	REP(i,1,son1[u1][0])REP(j,1,son2[u2][0]){
		int &v1=son1[u1][i],&v2=son2[u2][j];
		dp(v1,v2,u1,u2);
	}
	nf::init(son1[u1][0]);
	REP(i,1,son1[u1][0])REP(j,1,son2[u2][0]){
		int &v1=son1[u1][i],&v2=son2[u2][j];
		if(d[v1][v2]!=-1)
			nf::addEdge(i,j+son1[u1][0],d[v1][v2]);
	}
	REP(i,1,son1[u1][0])nf::addEdge(nf::S,i,0);
	REP(i,1,son2[u2][0])nf::addEdge(son1[u1][0]+i,nf::T,0);
	int t=nf::solve();
	if(t!=-1)d[u1][u2]=t+(a[u1]!=b[u2]);
}

int rt[10],q[N],fr,rr,dist[N],pre[N];
int bfs(int s){
	fr=0,rr=-1;
	q[++rr]=s;
	memset(dist,-1,sizeof(dist));
	dist[s]=0;
	pre[s]=0;
	while(fr<=rr){
		int &u=q[fr++];
		for(int i=le[u]; i; i=pe[i]){
			int &v=ev[i];
			if(dist[v]>-1)continue;
			dist[v]=dist[u]+1;
			q[++rr]=v;
			pre[v]=u;
		}
	}
	return q[n-1];
}
void find_root(){
	int L=bfs(1),R=bfs(L);
	for(int i=R; i; i=pre[i]){
		if(abs(dist[R]-dist[i]-dist[i])<=1)
			rt[++rt[0]]=i;
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d",&n);
	REP(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	REP(i,1,n)scanf("%d",&a[i]);
	REP(i,1,n)scanf("%d",&b[i]);
	int ans=1<<30;
	find_root();
	REP(i,1,rt[0])REP(j,1,rt[0]){
		memset(d,-1,sizeof(d));
		dp(rt[i],rt[j],0,0);
		if(d[rt[i]][rt[j]]!=-1 && ans>d[rt[i]][rt[j]])ans=d[rt[i]][rt[j]];
	}
	printf("%d\n",ans);
	return 0;
}
