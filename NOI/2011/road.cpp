#include<stdio.h>
#include<algorithm>
#include<cstring>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 1000010

int le[N],pe[N<<1],ev[N<<1],ed[N<<1],ecnt;
inline void addEdge(int &u,int &v,int &d){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
  ed[ecnt]=d;
}

int n;

typedef long long LL;
LL ans;
int w[N],fa[N],sz[N];
int q[N],fr,rr;
void bfs(int s){
  q[0]=s;
  while(fr<=rr){
    int &u=q[fr++];
    for(int i=le[u]; i; i=pe[i]){
      int &v=ev[i];
      if(v==fa[u])continue;
      q[++rr]=v;
      fa[v]=u;
      w[v]=ed[i];
    }
  }
  RREP(i,rr,0){
    int &u=q[i];
    sz[u]++;
    sz[fa[u]]+=sz[u];
    ans+=abs(n-2*sz[u])*(LL)w[u];
  }
}

int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n-1){
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    addEdge(u,v,w);
    addEdge(v,u,w);
  }
  bfs(1);
  printf("%lld",ans);
  return 0;
}
