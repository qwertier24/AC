#include<stdio.h>
#include<string.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;

namespace nf{
#define N 10000
#define M 60000
	int le[N],pe[M],ev[M],data[M],ecnt;
	int cost[M];
	void addEdge(int u,int v,int cap,int fee){
		pe[ecnt]=le[u];
		le[u]=ecnt;
		ev[ecnt]=v;
		data[ecnt]=cap;
		cost[ecnt]=fee;
		ecnt++;
		
		pe[ecnt]=le[v];
		le[v]=ecnt;
		ev[ecnt]=u;
		data[ecnt]=0;
		cost[ecnt]=-fee;
		ecnt++;
	}
	
	int S,T;
	void init(int s,int t){
		S=s,T=t;
		memset(le,-1,sizeof(le));
	}
	
	int ret;
	int dist[N];
	int q[N+10],inq[N],fr,rr,pre[N];
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
		ret+=dist[T];
		int u=T;
		while(u!=S){
			data[pre[u]]--;
			data[pre[u]^1]++;
			u=ev[pre[u]^1];
		}
		return true;
	}
	void mcmf(){
		ret=0;
		while(spfa()); 
	}
}
using namespace nf;

int n,a[110][110],sz,win[110],lose[110];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d",&n);
	init(0,n+n+1);
	sz=n+n+1;
	REP(i,1,n)REP(j,1,n){
		scanf("%d",&a[i][j]);
		if(i<j){
			if(a[i][j]==0)win[j]++,lose[i]++;
			else if(a[i][j]==1)win[i]++,lose[i]--;
			else{
				++sz;
				addEdge(S,sz,1,-1);
				addEdge(sz,i,1,0);
				addEdge(sz,j,1,0);
			}
		}
		addEdge(i+n,T,1<<30,0);
	}
	int ans=0;
	REP(i,1,n){
		REP(j,win[i]+1,n-lose[i]-1)addEdge(i,i+n,1,2*(j-1)+1);
		ans+=win[i]*win[i]-win[i];
	}
	mcmf();
	printf("%d\n",n*(n-1)*(n-2)/6-(ans+ret)/2);
	RREP(i,n,1)RREP(j,n,i+1){
		if(a[i][j]<2)continue;
		for(int k=le[sz]; k!=-1; k=pe[k])
			if(!data[k] && (ev[k]==i || ev[k]==j)){
				a[i][j]=(ev[k]==i);
				a[j][i]=1^a[i][j];
			}
		sz--;
	}
	REP(i,1,n)REP(j,1,n)printf("%d%s",a[i][j],j==n?"\n":" ");
	return 0;
}

