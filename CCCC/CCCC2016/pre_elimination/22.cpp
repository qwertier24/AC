#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<bitset>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 110

int g[N][N], e[N][N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int n,m ,Q;
  scanf("%d%d%d",&n,&m,&Q);
  FOR(i,m){
      int u,v, w;
      scanf("%d%d%d",&u,&v,&w);
      if(w == 1)
          g[u][v] = g[v][u] = 1;
      else
          e[u][v] = e[v][u] = 1;
  }
  FOR(k,n)FOR(i,n)FOR(j,n)
      g[i][j] |= g[i][k] & g[k][j];
  FOR(i,Q){
      int u,v;
      scanf("%d%d",&u,&v);
      if(g[u][v] && !e[u][v]){
          puts("No problem");
      }else if(!e[u][v]){
          puts("OK");
      }else if(g[u][v]){
          puts("OK but...");
      }else{
          puts("No way");
      }
  }
  return 0;
}
