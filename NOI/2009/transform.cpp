#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;
#define N 10010

int e[N][2];
int vis[N],L[N],R[N],cur,dfsn;
int match(int u){
  if(vis[u]==dfsn)return 0;
  vis[u]=dfsn;
  REP(i,2){
    int &v=e[u][i];
    if(L[v]==-1 || (L[v]>cur && match(L[v]))){
      L[v]=u;
      R[u]=v;
      return 1;
    }
  }
  return 0;
}

int n,d[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,n){
    scanf("%d",&d[i]);
    int t1=(i-d[i]+n)%n,t2=(i+d[i])%n;
    e[i][0]=min(t1,t2);
    e[i][1]=max(t1,t2);
  }
  memset(L,-1,sizeof(L));
  memset(R,-1,sizeof(R));
  cur=-1;
  REP(i,n){
    dfsn++;
    if(!match(i)){
      puts("No Answer");
      return 0;
    }
  }
  REP(u,n){
    if(R[u]!=e[u][0]){
      dfsn++;
      L[R[u]]=-1;
      R[u]=-1;
      cur=u;
      match(u);
    }
    printf("%d ",R[u]);
  }
  return 0;
}
