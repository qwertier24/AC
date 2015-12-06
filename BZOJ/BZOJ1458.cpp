#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

typedef long long LL;
using namespace std;

namespace nf{
#define N 300
#define M 30000
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
      if(dfscnt>200000)return ret;
    }
    return ret;
  }
}

int a[110],b[110],n,m,k,mark[110][110],ans;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d",&n,&m,&k);
  nf::init(0,n+m+1);
  ans=n*m;
  For(i,n){
    scanf("%d",&a[i]);
    a[i]=m-a[i];
  }
  For(i,m){
    scanf("%d",&b[i]);
    b[i]=n-b[i];
  }
  For(i,k){
    int x,y;
    scanf("%d%d",&x,&y);
    if(!mark[x][y]){
      a[x]--;
      b[y]--;
      if(a[x]<0 || b[y]<0){
        puts("JIONG");
        return 0;
      }
      ans--;
      mark[x][y]=1;
    }
  }
  For(i,n)nf::addEdge(nf::S,i,a[i]);
  For(i,m)nf::addEdge(i+n,nf::T,b[i]);
  For(i,n)For(j,m)if(!mark[i][j]){
    nf::addEdge(i,j+n,1);
  }
  printf("%d\n",ans-nf::maxFlow());
  return 0;
}
