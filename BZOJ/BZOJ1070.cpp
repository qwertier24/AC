#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 60
#define M 540
#define INF (1<<30)

typedef long long LL;
using namespace std;
int m,n,w[N][M],slack[M];

int vx[N],vy[M],lx[N],ly[M],mark[M];
bool match(int u){
  vx[u]=1;
  Rep(v,m)
    if(lx[u]+ly[v]==w[u][v]){
      if(vy[v])continue;
      vy[v]=1;
      if(mark[v]==-1 || match(mark[v])){
	mark[v]=u;
	return 1;
      }
    }else
      slack[v]=min(slack[v],lx[u]+ly[v]-w[u][v]);
  return 0;
}
void update(){
  int d=INF;
  Rep(i,m)if(!vy[i])d=min(d,slack[i]);
  Rep(i,n)if(vx[i])lx[i]-=d;
  Rep(i,m){
    if(vy[i])ly[i]+=d;
    else slack[i]-=d;
  }
}
void KM(){
  memset(mark,-1,sizeof(mark));
  Rep(i,n){
    lx[i]=-INF;
    Rep(j,m)
      lx[i]=max(lx[i],w[i][j]);
  }
  Rep(i,n){
    memset(slack,0x3f,sizeof(slack));
    while(true){
      memset(vx,0,sizeof(vx));
      memset(vy,0,sizeof(vy));
      if(match(i))break;
      update();
    }
  }
}
int t[N][N];
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#else
  freopen("scoi2007_repair.in","r",stdin);
  freopen("scoi2007_repair.out","w",stdout);
#endif 
  scanf("%d%d",&m,&n);
  Rep(i,n)Rep(j,m){
    scanf("%d",&t[i][j]);
  }
  Rep(i,n)Rep(j,m)Rep(k,n)w[i][j*n+k]=-t[i][j]*(k+1);
  m*=n;
  KM();
  int ans=0;
  Rep(i,m)if(mark[i]!=-1)ans+=w[mark[i]][i];
  printf("%.2f",-ans/(double)n);
  return 0;
}
