#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define INF (1<<30)
#define N 100000
#define M 1000000
#define xt (x+dx[i])
#define yt (y+dy[i])
#define zt (z+dz[i])
#define check(x,y,z) (x>=0&&x<n && y>=0&&y<n && z>=0&&z<n)

using namespace std;
int n;
namespace nf{
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
    while(bfs()){
      dfscnt++;
      ret+=dfs(S,INF);
      if(dfscnt>200000)return ret;
    }
    return ret;
  }
}

int dx[6]={0,0,0,0,-1,1},dy[6]={0,0,-1,1,0,0},dz[6]={-1,1,0,0,0,0};
int idx[50][50][50];
int m;
char g[50][50][50];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  nf::init(n*n*n,n*n*n+1);
  Rep(i,n)Rep(j,n){
    scanf("%s",g[i][j]);
  }
  Rep(i,n)Rep(j,n)Rep(k,n)idx[i][j][k]=i*n*n+j*n+k;
  int ans=0;
  Rep(x,n)Rep(y,n)Rep(z,n){
    if(g[x][y][z]!='?'){
      Rep(i,6)
        if(check(xt,yt,zt)&&g[xt][yt][zt]!=g[x][y][z])
          ans++;
      continue;
    }
    Rep(i,6)
      if(check(xt,yt,zt))
        ans++;
    if((x+y+z)&1){
      int cnt1=0,cnt2=0;
      Rep(i,6){
        if(!check(xt,yt,zt))continue;
        if(g[xt][yt][zt]=='?')
          nf::addEdge(idx[x][y][z],idx[xt][yt][zt],1);
        else if(g[xt][yt][zt]=='P')
          cnt1++;
        else
          cnt2++;
      }
      if(cnt1)
        nf::addEdge(nf::S,idx[x][y][z],cnt1);
      if(cnt2)
        nf::addEdge(idx[x][y][z],nf::T,cnt2);
    }else{
      int cnt1=0,cnt2=0;
      Rep(i,6){
        if(!check(xt,yt,zt))continue;
        if(g[xt][yt][zt]=='?')
          nf::addEdge(idx[x][y][z],idx[xt][yt][zt],1);
        else if(g[xt][yt][zt]=='P')
          cnt1++;
        else
          cnt2++;
      }
      if(cnt1)
        nf::addEdge(idx[x][y][z],nf::T,cnt1);
      if(cnt2)
        nf::addEdge(nf::S,idx[x][y][z],cnt2);
    }
  }
  ans>>=1;
  printf("%d\n",ans-nf::maxFlow());
  return 0;
}
