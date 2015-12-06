#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB
using namespace std;

namespace nf{
#define N 400
#define M 500000
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
		
		int u=T;
		while(u!=S){
			data[pre[u]]--;
			data[pre[u]^1]++;
			u=ev[pre[u]^1];
		}
		return true;
	}
	void mcmf(){
		while(spfa()); 
	}
}

int main(){
	scanf("%d",&n);
	For(i,n){
	}
	return 0;
}

