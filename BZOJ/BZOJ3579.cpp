#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<bitset>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define MOD 1000003

typedef long long LL;
using namespace std;
#define N 2010

int n,m;

inline bool check(bitset<N> &bst){
  REP(i,0,n-1)if(bst[i<<1]&bst[i<<1|1])return 0;
  return 1;
}
bitset<N> g[N];
int ans;
void dfs(int u,bitset<N> &cur){
  if(u==n){
    if(++ans==MOD)ans=0;
    return;
  }
  bitset<N> t;
  t=cur|g[u<<1];
  if(check(t))dfs(u+1,t);
  t=cur|g[u<<1|1];
  if(check(t))dfs(u+1,t);
}

int mark[1010][1010],u,v;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    if(!m){
      printf("%d\n",n-(n==1));
      continue;
    }
    REP(i,0,n*2-1)g[i].reset();
    REP(i,0,n-1)REP(j,0,n-1)mark[i][j]=0;
    REP(i,0,m-1){
      scanf("%d%d",&u,&v);
      mark[u-1][v-1]=mark[v-1][u-1]=1;
    }
    if(m==n*(n-1)/2){
      printf("%d\n",n);
      continue;
    }
    REP(i,0,n-1)REP(j,0,n-1)if(i!=j){
      if(mark[i][j])g[i<<1|1][j<<1]=1;
      else g[i<<1][j<<1|1]=1;
    }
    REP(i,0,n*2-1)g[i][i]=1;
    REP(k,0,n*2-1)REP(i,0,n*2-1)
      if(g[i][k])g[i]|=g[k];
    bitset<N> t;
    ans=0;
    dfs(0,t);
    printf("%d\n",ans);
  }
  return 0;
}
