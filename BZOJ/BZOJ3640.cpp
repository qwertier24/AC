#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<math.h>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;
#define N 160
#define M 10010

int ecnt,le[N],ev[M],pe[M];
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

struct Prec{
  double A[N][N],C[N];
  int sz,pt[N];
  void init(){
    REP(i,sz)C[i]=0;
  }
  double K[N][N];
  int R[N];
  void pre_calc(){
    REP(i,sz){
      R[i]=i;
      for(int j=i+1; j<sz; j++)
        if(fabs(A[j][i])>fabs(A[R[i]][i]))
          R[i]=j;
      for(int j=i; j<sz; j++)
        swap(A[i][j],A[R[i]][j]);
      for(int j=i+1; j<sz; j++){
        K[i][j]=A[j][i]/A[i][i];
        for(int k=i; k<sz; k++)
          A[j][k]-=A[i][k]*K[i][j];
      }
    }
  }
  void calc(){
    REP(i,sz){
      swap(C[i],C[R[i]]);
      for(int j=i+1; j<sz; j++)
        C[j]-=C[i]*K[i][j];
    }
    for(int i=sz-1; i>=0; i--){
      for(int j=i+1; j<sz; j++)
        C[i]-=C[j]*A[i][j];
      C[i]/=A[i][i];
    }
  }
}prec[N];

int n,m,hp;
int id[N],deg[N],loss[N];
void dfs(int u){
  prec[m].pt[id[u]=prec[m].sz++]=u;
  if(u==n)
    prec[m].A[id[u]][id[u]]=1;
  else
    prec[m].A[id[u]][id[u]]=deg[u];
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(loss[v])continue;
    if(id[v]==-1)dfs(v);
    if(u!=n)prec[m].A[id[u]][id[v]]--;
  }
}

double dp[N][10010];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d%d",&n,&m,&hp);
  FOR(i,n)scanf("%d",&loss[i]);
  while(m--){
    int u,v;
    scanf("%d%d",&u,&v);
    deg[u]++;
    addEdge(u,v);
    if(u!=v){
      deg[v]++;
      addEdge(v,u);
    }
  }
  m=0;
  memset(id,-1,sizeof(id));
  FOR(i,n)if(!loss[i] && id[i]==-1){
    dfs(i);
    prec[m].pre_calc();
    m++;
  }
  FOR(i,hp){
    REP(j,m){
      prec[j].init();
      REP(k,prec[j].sz){
        int &u=prec[j].pt[k];
        if(u==n){
          prec[j].C[k]=1;
          continue;
        }
        for(int l=le[u]; l; l=pe[l]){
          int &v=ev[l];
          if(loss[v])prec[j].C[k]+=dp[v][max(0,i-loss[v])];
        }
      }
      prec[j].calc();
      REP(k,prec[j].sz)
        dp[prec[j].pt[k]][i]=prec[j].C[k];
    }
    FOR(u,n)if(loss[u]){
      for(int j=le[u]; j; j=pe[j])
        dp[u][i]+=dp[ev[j]][max(0,i-loss[ev[j]])]/deg[u];
    }
  }
  printf("%.8f",dp[1][hp]);
  return 0;
}
