#include<stdio.h>
#include<string.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)

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
	int c;
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
		
		c+=dist[T];
		int u=T;
		while(u!=S){
			data[pre[u]]--;
			data[pre[u]^1]++;
			u=ev[pre[u]^1];
		}
		return true;
	}
	void mcmf(){
		c=0;
		while(spfa()); 
	}
}

using namespace nf;

int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
#define xt ((i+dx[k]+n)%n)
#define yt ((j+dy[k]+m)%m)
int getdir(char c){
	switch(c){
	case 'L':return 0;break;
	case 'R':return 1;break;
	case 'U':return 2;break;
	case 'D':return 3;break;
	}
}

int n,m;
char str[20];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	init(n*m*2,n*m*2+1);
	REP(i,0,n-1){
		scanf("%s",str);
		REP(j,0,m-1){
			addEdge(S,i*m+j,1,0);
			addEdge(n*m+i*m+j,T,1,0);
			int dir=getdir(str[j]);
			REP(k,0,3)
				addEdge(i*m+j,n*m+xt*m+yt,1,k!=dir);
		}
	}
	mcmf();
	printf("%d\n",c);
	return 0;
}
