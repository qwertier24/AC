#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;
#define N 20010
#define M 100010

int n,pa[N];
int findset(int u){
  if(pa[u]!=u)pa[u]=findset(pa[u]);
  return pa[u];
}
int init(){
  FOR(i,n)pa[i]=i;
}
bool addEdge(int u,int v){
  if(findset(u)==findset(v))return false;
  pa[pa[u]]=pa[v];
  return true;
}

struct E{int u,v,i;}e[2][M];
int sz[2],mark[M],m,k;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d%d",&n,&m,&k);
  FOR(i,m){
    int u,v,d;
    scanf("%d%d%d",&u,&v,&d);
    sz[d]++;
    e[d][sz[d]].u=u;
    e[d][sz[d]].v=v;
    e[d][sz[d]].i=i;
  }
  k=n-1-k;
  int cnt0=0,cnt1=0;
  init();
  FOR(i,sz[0])
    if(addEdge(e[0][i].u,e[0][i].v))
      cnt0++;
  FOR(i,sz[1])
    if(addEdge(e[1][i].u,e[1][i].v)){
      mark[i]=1;
      cnt1++;
    }
  if(cnt0+cnt1<n-1){
    puts("no solution");
    return 0;
  }
  if(cnt1>k){
    puts("no solution");
    return 0;
  }
  init();
  FOR(i,sz[1])
    if(mark[i])
      addEdge(e[1][i].u,e[1][i].v);
  FOR(i,sz[1])
    if(cnt1<k && addEdge(e[1][i].u,e[1][i].v)){
      mark[i]=1;
      cnt1++;
    }
  if(cnt1<k){
    puts("no solution");
    return 0;
  }
  FOR(i,sz[1])
    if(mark[i])
      printf("%d %d 1\n",e[1][i].u,e[1][i].v);
  FOR(i,sz[0])
    if(addEdge(e[0][i].u,e[0][i].v))
      printf("%d %d 0\n",e[0][i].u,e[0][i].v);
  return 0;
}
