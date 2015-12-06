#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 5010

int n;

int g[N][N/32+10];
inline void addEdge(int &u,int &v){
  g[u][v/32]|=1<<v%32;
  g[v][u/32]|=1<<u%32;
}
inline void delEdge(int &u,int &v){
  g[u][v/32]^=1<<v%32;
  g[v][u/32]^=1<<u%32;
}
inline int check(int &u,int &v){
  REP(i,0,n/32)
    if(g[u][i]&g[v][i])
      return 1;
  return 0;
}
int pa[N];
int findset(int u){
  if(pa[u]!=u)pa[u]=findset(pa[u]);
  return pa[u];
}
int m;
char op[10];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  REP(i,1,n)pa[i]=i;
  int ans=n;
  while(m--){
    int u,v;
    scanf("%d%d",&u,&v);
    u--,v--;
    addEdge(u,v);
    if(findset(u)!=findset(v)){
      ans--;
      pa[pa[u]]=pa[v];
    }
  }
  scanf("%d",&m);
  while(m--){
    int u,v;
    scanf("%s",op);
    if(op[0]=='A'){
      scanf("%d%d",&u,&v);
      u--,v--;
      if(!check(u,v))
        ans--;
      addEdge(u,v);
    }else if(op[0]=='D'){
      scanf("%d%d",&u,&v);
      u--,v--;
      delEdge(u,v);
      if(!check(u,v))ans++;
    }else
      printf("%d\n",ans);
  }
  return 0;
}
