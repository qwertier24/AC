#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define INF (1<<30)

typedef long long LL;
using namespace std;

namespace nf{
#define N 100000
#define M 1000000
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
      if(!a)break;
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

int n,m,h,H;
int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d%d",&n,&m,&h,&H);
  nf::init(n*m*(h+1),n*m*(h+1)+1);
  Rep(i,n)Rep(j,m)nf::addEdge(nf::S,i*m+j,INF),nf::addEdge(h*n*m+i*m+j,nf::T,INF);
  Rep(i,h){
    Rep(j,n)Rep(k,m){
      int v;
      scanf("%d",&v);
      nf::addEdge(i*n*m+j*m+k,(i+1)*n*m+j*m+k,v);
      if(i-H>=0)
        Rep(p,4){
          int xt=j+dx[p],yt=k+dy[p];
          if(xt>=0 && yt>=0 && xt<n && yt<m)
            nf::addEdge(i*n*m+j*m+k,(i-H)*n*m+xt*m+yt,INF);
        }
    }
  }
  printf("%d\n",nf::maxFlow());
  return 0;
}
