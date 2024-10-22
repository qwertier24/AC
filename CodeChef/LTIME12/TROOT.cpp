#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define MOD 1000000007
#define N 100010

int n;

int le[N],ev[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

int id[N];

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
int maxv[N<<2],addv[N<<2];
long long mulv[N<<2];
inline void maintain(int &o){
  maxv[o]=max(maxv[lc],maxv[rc]);
  mulv[o]=1;
  if(maxv[lc]==maxv[o])mulv[o]=mulv[o]*mulv[lc]%MOD;
  if(maxv[rc]==maxv[o])mulv[o]=mulv[o]*mulv[rc]%MOD;
  maxv[o]+=addv[o];
}
void add(int L,int R,int v,int o=1,int l=1,int r=n){
  if(L>R)return;
  //printf("%d %d %d\n",L,R,v);
  if(L<=l && r<=R){addv[o]+=v;maxv[o]+=v;return;}
  if(L<=mid)add(L,R,v,lc,l,mid);
  if(R>mid)add(L,R,v,rc,mid+1,r);
  maintain(o);
}
void build(int o=1,int l=1,int r=n){
  if(l==r){mulv[o]=id[l];return;}
  build(lc,l,mid);
  build(rc,mid+1,r);
  mulv[o]=mulv[lc]*mulv[rc]%MOD;
}

#define LOG 16
int in[N],out[N],dfsn,top[N][LOG+1];
void dfs(int u){
  REP(i,1,LOG)top[u][i]=top[top[u][i-1]][i-1];
  in[u]=++dfsn;
  id[dfsn]=u;
  for(int i=le[u]; i; i=pe[i])
    if(ev[i]!=top[u][0]){
      top[ev[i]][0]=u;
      dfs(ev[i]);
    }
  out[u]=dfsn;
}

int m,cnt;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  REP(i,1,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    addEdge(u,v);
    addEdge(v,u);
  }
  dfs(1);
  build();
  while(m--){
    char op[10];
    int u,v;
    scanf("%s%d%d",op,&u,&v);
    int dx=op[0]=='+'?1:-1;
    cnt+=dx;
    if(in[u]>in[v])swap(u,v);
    if(out[v]<=out[u]){
      add(1,in[u]-1,dx);
      add(out[u]+1,n,dx);
      add(in[v],out[v],dx);
      add(in[u],out[u],dx);

      RREP(i,LOG,0)if(in[top[v][i]]>in[u])v=top[v][i];
      add(in[v],out[v],-dx);
    }else{
      add(in[u],out[u],dx);
      add(in[v],out[v],dx);
    }
    if(maxv[1]==cnt)printf("%lld\n",mulv[1]);
    else puts("-1");
  }
  return 0;
}
