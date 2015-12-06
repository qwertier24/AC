#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 80
#define INF (1<<30)

int n,a[N][N],b[N][N];

int lx[N],ly[N],slack[N],vx[N],vy[N],mark[N],w[N][N];
int find(int u){
  vx[u]=1;
  REP(v,1,n)
    if(!vy[v]){
      int t=lx[u]+ly[v]-w[u][v];
      if(!t){
        vy[v]=1;
        if(!mark[v] || find(mark[v])){
          mark[v]=u;
          return 1;
        }
      }else if(t<slack[v])
        slack[v]=t;
    }
  return 0;
}
inline void update(){
  int d=INF;
  REP(i,1,n)if(!vy[i])d=min(d,slack[i]);
  REP(i,1,n){
    if(vx[i])lx[i]-=d;
    if(vy[i])ly[i]+=d;
    else slack[i]-=d;
  }
}
int ans;
void KM(int k1,int k2,int &x,int &y){
  memset(ly,0,sizeof(ly));
  REP(i,1,n){
    lx[i]=-INF;
    REP(j,1,n)lx[i]=max(lx[i],w[i][j]=k1*a[i][j]+k2*b[i][j]);
  }
  //REP(i,1,n)REP(j,1,n)printf("%d %d %d\n",i,j,w[i][j]);
  memset(mark,0,sizeof(mark));
  REP(i,1,n){
    memset(slack,0x3f,sizeof(slack));
    while(true){
      memset(vx,0,sizeof(vx));
      memset(vy,0,sizeof(vy));
      if(find(i))break;
      update();
    }
  }
  x=y=0;
  REP(i,1,n)x+=a[mark[i]][i];
  REP(i,1,n)y+=b[mark[i]][i];
  ans=min(ans,x*y);
}

void proc(int x1,int y1,int x2,int y2){
  int x3,y3;
  KM(y2-y1,x1-x2,x3,y3);
  if((x3-x1)*(y2-y1)-(x2-x1)*(y3-y1)<=0)return;
  proc(x1,y1,x3,y3);
  proc(x3,y3,x2,y2);
}

int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    REP(i,1,n)REP(j,1,n)scanf("%d",&a[i][j]);
    REP(i,1,n)REP(j,1,n)scanf("%d",&b[i][j]);
    int x1,y1,x2,y2;
    ans=INF;
    KM(-1,0,x1,y2);
    KM(0,-1,x2,y2);
    proc(x1,y1,x2,y2);
    printf("%d\n",ans);
  }
  return 0;
}
