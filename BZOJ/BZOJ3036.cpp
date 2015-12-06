#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100010

typedef long long LL;
using namespace std;

int le[N],pe[N<<1],ev[N<<1],ed[N<<1],ecnt;
void addEdge(int u,int v,int d){
  ecnt++;
  pe[ecnt]=le[u];
  ev[ecnt]=v;
  ed[ecnt]=d;
  le[u]=ecnt;
}

int n,vis[N],m;
double ep[N];
double dp(int u){
  if(u==n)return 0;
  if(vis[u])return ep[u];
  vis[u]=1;
  int cnt=0;
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i],&d=ed[i];
    cnt++;
    ep[u]+=dp(v)+d;
  }
  ep[u]/=cnt;
  return ep[u];
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  For(i,m){
    int u,v,d;
    scanf("%d%d%d",&u,&v,&d);
    addEdge(u,v,d);
  }
  printf("%.2f\n",dp(1));
  return 0;
}
