#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;

inline int cnt_ones(int x){
  int ret=0;
  while(x){
    ret+=x&1;
    x>>=1;
  }
  return ret;
}

#define N 72
int le[N],ev[N*N],ed[N*N],pe[N*N],ecnt;
void addEdge(int u,int v,int d){
  ecnt++;
  pe[ecnt]=le[u];
  ev[ecnt]=v;
  ed[ecnt]=d;
  le[u]=ecnt;
}

int cur;
int vis[N],mark[N];
int match(int u){
  if(vis[u])return 0;
  vis[u]=1;
  for(int i=le[u]; i; i=pe[i])
    if(!((cur>>ed[i])&1) && (mark[ev[i]]==-1 || match(mark[ev[i]]))){
      mark[ev[i]]=u;
      return 1;
    }
  return 0;
}
int a,b,c,ans;
int hungary(){
  int ret=cnt_ones(cur);
  memset(mark,-1,sizeof(mark));
  REP(i,0,b-1){
    memset(vis,0,sizeof(vis));
    ret+=match(i);
    if(ret>=ans)return ret;
  }
  return ret;
}

int n,g[5010];
#define pos(i,j,k) ((i)*b*c+(j)*c+(k))
void solve(){
  scanf("%d%d%d",&a,&b,&c);
  int ta=a,tb=b,tc=c;
  int tmp[3];
  tmp[0]=a,tmp[1]=b,tmp[2]=c;
  sort(tmp,tmp+3);
  a=tmp[0],b=tmp[1],c=tmp[2];
  REP(i,0,ta-1)REP(j,0,tb-1)REP(k,0,tc-1){
    if(ta<=tb && tb<=tc)
      scanf("%d",&g[pos(i,j,k)]);
    else if(ta<=tc && tc<=tb)
      scanf("%d",&g[pos(i,k,j)]);
    else if(tb<=ta && ta<=tc)
      scanf("%d",&g[pos(j,i,k)]);
    else if(tb<=tc && tc<=ta)
      scanf("%d",&g[pos(j,k,i)]);
    else if(tc<=ta && ta<=tb)
      scanf("%d",&g[pos(k,i,j)]);
    else
      scanf("%d",&g[pos(k,j,i)]);
  }
  memset(le,0,sizeof(le));
  ecnt=0;
  REP(i,0,a-1)REP(j,0,b-1)REP(k,0,c-1)
    if(g[pos(i,j,k)])
      addEdge(j,k,i);
  ans=a;
  for(cur=0; cur<(1<<a); cur++){
    if(cnt_ones(cur)>=ans)continue;
    ans=min(ans,hungary());;
  }
  printf("%d\n",ans);
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  while(T--)
    solve();
  return 0;
}
