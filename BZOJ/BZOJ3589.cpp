#include<stdio.h>
#include<string.h>
#include<algorithm>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;
typedef long long LL;
#define N 200010

int le[N],ev[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

int n;

void readint(int &x){
	x=0;
	char c=getchar();
	while(c>'9' || c<'0')c=getchar();
	while('0'<=c && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
int addv[N<<2],sumv[N<<2];
inline void maintain(int &o,int &l,int &r){
	sumv[o]=sumv[lc]+sumv[rc];
	sumv[o]+=addv[o]*(r-l+1);
}
void Add(int L,int R,int v,int o=1,int l=1,int r=n){
  if(L<=l&&r<=R){
    addv[o]+=v;
    sumv[o]+=v*(r-l+1);
    return;
  }
  if(L<=mid)Add(L,R,v,lc,l,mid);
  if(R>mid)Add(L,R,v,rc,mid+1,r);
  sumv[o]=sumv[lc]+sumv[rc];
  sumv[o]+=addv[o]*(r-l+1);
}
int query(int L,int R,int o=1,int l=1,int r=n){
  if(L<=l && r<=R)return sumv[o];
  if(addv[o]){
    addv[lc]+=addv[o];
    sumv[lc]+=addv[o]*(mid-l+1);
    addv[rc]+=addv[o];
    sumv[rc]+=addv[o]*(r-mid);
    addv[o]=0;
  }
  if(R<=mid)return query(L,R,lc,l,mid);
  if(L>mid)return query(L,R,rc,mid+1,r);
  return query(L,R,lc,l,mid)+query(L,R,rc,mid+1,r);
}
int hson[N],fa[N],sz[N],dep[N];
void dfs1(int u){
  sz[u]=1;
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==fa[u])continue;
    fa[v]=u;
    dep[v]=dep[u]+1;
    dfs1(v);
    sz[u]+=sz[v];
    if(sz[v]>sz[hson[u]])
      hson[u]=v;
  }
}
int top[N],lft[N],rgt[N],dfsn;
void dfs2(int u){
  lft[u]=++dfsn;
  if(hson[u]){
    top[hson[u]]=top[u];
    dfs2(hson[u]);
  }
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==fa[u]||v==hson[u])continue;
    top[v]=v;
    dfs2(v);
  }
  rgt[u]=dfsn;
}
int lca(int u,int v){
	while(top[u]!=top[v]){
    if(dep[top[u]]<dep[top[v]])swap(u,v);
    u=fa[top[u]];
  }
  return dep[u]<dep[v]?u:v;
}
int sum(int u,int v){
  int ret=0;
  while(top[u]!=top[v]){
    ret+=query(lft[top[v]],lft[v]);
    v=fa[top[v]];
  }
  return ret+query(lft[u],lft[v]);
}
int m,qu[10],qv[10];
int calc(int S){
  int u,v,i,mul=1;
  for(i=0; i<m; i++)
    if((S>>i)&1){
      u=qu[i],v=qv[i];
      break;
    }
  for(i++; i<m; i++)
    if((S>>i)&1){
      int cu=qu[i],cv=qv[i];
      if(dep[u]>dep[cu]){
        swap(cu,u);
        swap(cv,v);
      }
      if(lft[v]<lft[cu] || lft[v]>rgt[cu])
        return 0;
      else{
        v=lca(v,cv);
        u=cu;
      }
      mul*=-1;
    }
  return sum(u,v)*mul;
}
int Q;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,n-1){
    int u,v;
	readint(u);readint(v);
    addEdge(u,v);
    addEdge(v,u);
  }
  dfs1(1);
  top[1]=1;
  dfs2(1);
  scanf("%d",&Q);
  while(Q--){
    int op;
    readint(op);
    if(op==0){
      int u,dx;
      readint(u);readint(dx);
      Add(lft[u],rgt[u],dx);
    }else{
      int ans=0;
      readint(m);
      REP(i,m){
      	readint(qu[i]);readint(qv[i]);
        if(dep[qu[i]]>dep[qv[i]])
          swap(qu[i],qv[i]);
      }
      for(int i=1; i<(1<<m); i++)
        ans+=calc(i);
      if(ans<0)ans^=(1<<31);
      printf("%d\n",ans);
    }
  }
  return 0;
}

