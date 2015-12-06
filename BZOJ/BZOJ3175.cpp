#include<stdio.h>
#include<string.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;

namespace nf{
#define N 40010
#define M 800000
#define INF (1<<30)
#define min(x,y) (x<y?x:y)
  int le[N],pe[M],ecnt,data[M],ev[M];
  void addEdge(int u,int v,int cap){
  	//printf("%d %d\n",u,v);
    pe[ecnt]=le[u];
    ev[ecnt]=v;
    data[ecnt]=cap;
    le[u]=ecnt++;
    
    pe[ecnt]=le[v];
    ev[ecnt]=u;
    data[ecnt]=0;
    le[v]=ecnt++;
  }
  int S,T;
  void init(int s,int t){
    memset(le,-1,sizeof(le));
    ecnt=0;
    S=s,T=t;
  }
  int dist[N],q[N],front,rear;
  int bfs(){
    memset(dist,-1,sizeof(dist));
    front=rear=0;
    q[front]=S;
    dist[S]=0;
    while(front<=rear){
      int u=q[front++];
      for(int i=le[u]; i!=-1; i=pe[i]){
	if(data[i] && dist[ev[i]]==-1){
	  dist[ev[i]]=dist[u]+1;
	  q[++rear]=ev[i];
	}
      }
    }
    return dist[T]!=-1;
  }
  int dfscnt=0,cur[N],mark[N]={0},cnt;
  int dfs(int u,int a){
    cnt++;
    if(u==T || a==0)return a;
    int ret=0,f;
    if(mark[u]!=dfscnt){mark[u]=dfscnt,cur[u]=le[u];}
    for(int &i=cur[u]; i!=-1; i=pe[i]){
      int &v=ev[i];
      if(dist[v]!=dist[u]+1)continue;
      f=dfs(v,min(a,data[i]));
      data[i]-=f;
      data[i^1]+=f;
      a-=f;
      ret+=f;
    }
    return ret;
  }
  int maxFlow(){
    int ret=0;
    dfscnt=0;
    memset(mark,0,sizeof(mark));
    while(bfs()){
      dfscnt++;
      ret+=dfs(S,INF);
    }
    return ret;
  }
}
using namespace nf;

int dx[8]={-2,-2,-1,-1,1,1,2,2},dy[8]={-1,1,-2,2,-2,2,-1,1};
#define xt (i+dx[k])
#define yt (j+dy[k])
int n;
char g[210][210];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d",&n);
	init(n*n,n*n+1);
	int ans=0;
	REP(i,0,n-1){
		scanf("%s",g[i]);
	}
	REP(i,0,n-1){
		REP(j,0,n-1)if(g[i][j]=='0'){
			ans++;
			if((i+j)&1){
				addEdge(S,i*n+j,1);
				REP(k,0,7)
					if(xt>=0 && xt<n && yt>=0 && yt<n && g[xt][yt]=='0')
						addEdge(i*n+j,xt*n+yt,1);
			}else addEdge(i*n+j,T,1);
		}
	}
	printf("%d\n",ans-maxFlow());
	return 0;
}

