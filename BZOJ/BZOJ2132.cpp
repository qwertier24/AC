#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)


using namespace std;

namespace nf{
#define N 20000
#define M 100000
#define INF (1<<30)
  int le[N],pe[M],ecnt,data[M],ev[M];
  void addEdge(int u,int v,int cap){
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
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0},n,m,a[110][110],ans;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  init(n*m,n*m+1);
  Rep(i,n)Rep(j,m){
    scanf("%d",&a[i][j]);
    ans+=a[i][j];
    if((i+j)&1)
      addEdge(S,i*m+j,a[i][j]);
    else
      addEdge(i*m+j,T,a[i][j]);
  }
  Rep(i,n)Rep(j,m){
    scanf("%d",&a[i][j]);
    ans+=a[i][j];
    if((i+j)&1)
      addEdge(i*m+j,T,a[i][j]);
    else
      addEdge(S,i*m+j,a[i][j]);
  }
  Rep(i,n)Rep(j,m)scanf("%d",&a[i][j]);
#define xt (i+dx[k])
#define yt (j+dy[k])
#define check(x,y) (x>=0 && x<n && y>=0 && y<m)
  Rep(i,n)Rep(j,m){
    Rep(k,4)if(check(xt,yt))ans+=a[i][j];
    Rep(k,2){
      if(check(xt,yt)){
        addEdge(i*m+j,xt*m+yt,a[i][j]+a[xt][yt]);
        addEdge(xt*m+yt,i*m+j,a[i][j]+a[xt][yt]);
      }
    }
  }
  printf("%d",ans-maxFlow());
  return 0;
}
