#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 1500
#define M 200000
#define INF (1<<29)

typedef long long LL;
using namespace std;

namespace nf{
  struct Edge{
    int u,v,data,cost;
    void init(int a,int b,int c,int d){
      u=a,v=b,data=c,cost=d;
    }
  };
  struct Q{
    int size,inq[N+10],q[N+10],fr,re,contain;
    void init(int n){
      fr=0,re=-1;
      size=n+1;
      contain=0;
      memset(inq,0,sizeof(inq));
    }
    void push(int u){
      if(inq[u])return;
      contain++;
      re++;
      if(re==size)re=0;
      q[re]=u;
      inq[u]=1;
    }
    int front(){
      return q[fr];
    }
    void pop(){
      contain--;
      inq[q[fr]]=0;
      fr++;
      if(fr==size)fr=0;
    }
    bool empty(){
      return contain==0;
    }
  };
  int S,T;
  Edge edges[M];
  int le[N],pe[M],ecnt;
  Q q;
  void addEdge(int u,int v,int cap,int cost){
    //printf("addE:%d %d %d %d\n",u,v,cap,cost);
    pe[ecnt]=le[u];
    edges[ecnt].init(u,v,cap,cost);
    le[u]=ecnt++;
    pe[ecnt]=le[v];
    edges[ecnt].init(v,u,0,-cost);
    le[v]=ecnt++;
  }
  int dist[N],pre[N];
  int flow,cost;
  bool spfa(){
    memset(dist,0x3f,sizeof(dist));
    dist[S]=0;
    q.init(N);
    q.push(S);
    while(!q.empty()){
     int u=q.front();
      q.pop();
      for(int i=le[u]; i!=-1; i=pe[i]){
	Edge &e=edges[i];
	if(e.data){
	  if(dist[e.v]>dist[u]+e.cost){
	    dist[e.v]=dist[u]+e.cost;
	    pre[e.v]=i;
	    q.push(e.v);
	  }
	}
      }
    }
    if(dist[T]>=INF)return false;
    int u=T;
    while(u!=S){
      Edge &e=edges[pre[u]];
      edges[pre[u]].data--;
      edges[1^pre[u]].data++;
      u=edges[pre[u]].u;
    }
    cost+=dist[T];
    flow++;
    return true;
  }
  void mcmf(){
    flow=0;
    cost=0;
    while(spfa());
  }
  void init(int s,int t){
    S=s,T=t;
    memset(le,-1,sizeof(le));
    ecnt=0;
  }
}

int cnt,hi[100][100],id1[100][100],id2[100][100],id3[100][100];
int n,m;
char g1[100][100],g2[100][100],h[100][100];
int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1};
#define check(x,y) (x>=0 && x<n && y>=0 && y<m)
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  Rep(i,n){
    scanf("%s",g1[i]);
    Rep(j,m)
      cnt+=g1[i][j]=='1';
  }
  Rep(i,n){
    scanf("%s",&g2[i]);
    Rep(j,m)
      cnt-=g2[i][j]=='1';
  } 
  Rep(i,n){
    scanf("%s",h[i]);
    Rep(j,m)
      hi[i][j]=h[i][j]-'0';
  }
  if(cnt!=0){
    puts("-1");
    return 0;
  }
  Rep(i,n)Rep(j,m){
    id1[i][j]=i*m+j;
    id2[i][j]=n*m+i*m+j;
    id3[i][j]=n*m+n*m+i*m+j;
  }
  nf::init(n*m*3,n*m*3+1);
  Rep(i,n)Rep(j,m){
    if(g1[i][j]==g2[i][j]){
      nf::addEdge(id1[i][j],id2[i][j],hi[i][j]/2,0);
      nf::addEdge(id2[i][j],id3[i][j],hi[i][j]/2,0);
    }else if(g1[i][j]=='1'){
      cnt++;
      nf::addEdge(nf::S,id2[i][j],1,0);
      nf::addEdge(id1[i][j],id2[i][j],hi[i][j]/2,0);
      nf::addEdge(id2[i][j],id3[i][j],(hi[i][j]+1)/2,0);
    }else{
      nf::addEdge(id2[i][j],nf::T,1,0);
      nf::addEdge(id1[i][j],id2[i][j],(hi[i][j]+1)/2,0);
      nf::addEdge(id2[i][j],id3[i][j],hi[i][j]/2,0);
    }
    Rep(k,8)
      if(check(i+dx[k],j+dy[k]))
        nf::addEdge(id3[i][j],id1[i+dx[k]][j+dy[k]],INF,1);
  }
  nf::mcmf();
  if(nf::flow==cnt)
    printf("%d\n",nf::cost);
  else
    printf("-1\n");
  return 0;
}
