#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef unsigned long long  LL;
using namespace std;

struct Node{
  LL hsum;
  int cnt;
  char setv;
  Node(int a,int b):hsum(a),cnt(b),setv(0){}
  Node()hsum(0),cnt(0),setv(0){}
  Node operator+(Node &rhs){
    return Node(hsum*psd[rhs.cnt]+rhs.hsum,cnt+rhs.cnt);
  }
  void Set(char v){
    setv=v;
    hsum=setv*sump[cnt][0];
  }
}tree[N<<2];

inline void pushdown(int o,int l,int r){
  if(node[o].setv){
    node[lc].Set(node[o].setv);
    node[rc].Set(node[o].setv);
    node[o].setv=0;
  }
}
inline void maintain(int o,int l,int r){
  if(!node[o].setv){
    node[o].hsum=node[lc].hsum*psd[node[rc].cnt]+node[rc].hsum;
  }
}
void Set(int o,int l,int r,int L,int R,char v){
  if(L<=l && r<=R){
    node[o].setv=v;
    node[o].hsum=v*sump[node[o].cnt][0];
    return;
  }
  pushdown(o,l,r);
  if(L<=mid)Set(lc,l,mid,L,R,v);
  if(R>mid)Set(rc,mid+1,r,L,R,v);
  maintain(o,l,r);
}
Node Query(int u,int v){
  Node ans1,ans2;
  while(top[u]!=top[v]){
    if(dep[top[u]]>=dep[top[v]]){
      ans=ans+Query(1,1,n,id[top[u]],id[u]);
    }else{
      ans=ans+Query(1,1,n,id[top[v]],id[v],REV);
    }
    u=fa[top[u]],v=fa[top[v]];
  }
  return (ans1+Query(1,1,n,id[+ans2;
}
void Set(int u,int v,char c){
  while(top[u]!=top[v]){
    
  }
}

int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FOR(i,n-1){
      int u,v;
      scanf("%d%d",&u,&v);
      addEdge(u,v);
      addEdge(v,u);
    }
    scanf("%d",&Q);
    while(Q--){
      int op,u,v,c;
      scanf("%d%d%d",&op,&u,&v);
      if(op==1){
        Node q=Query(u,v);
      }else{
        Set(u,v,c);
      }
    }
  }
  return 0;
}
