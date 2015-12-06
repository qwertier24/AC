#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 5010

using namespace std;
typedef long long LL;

int n;

int le[N],ev[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}

int fr=1,rr=1,q[N],d[N][3],fa[N],tot[N][3];
LL two[N],ans;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  For(i,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    addEdge(u,v);
    addEdge(v,u);
  }
  q[1]=1;
  while(fr<=rr){
    int &u=q[fr++];
    for(int i=le[u]; i; i=pe[i]){
      int &v=ev[i];
      if(v==fa[u])continue;
      fa[v]=u;
      q[++rr]=v;
    }
  }
  For(i,n)d[i][0]=tot[i][0]=1;
  For(k,n){
    int cur=k%3,lst=(k+2)%3,llst=(k+1)%3;
    For(j,n){
      int &u=q[j];
      d[u][cur]=tot[u][cur]=two[u]=0;
      for(int i=le[u]; i; i=pe[i]){
        int &v=ev[i];
        if(v==fa[u])continue;
        ans+=d[v][lst]*two[u];
        two[u]+=d[u][cur]*(LL)d[v][lst];
        d[u][cur]+=d[v][lst];
      }
      if(fa[u]){
        ans+=two[u]*(tot[fa[u]][lst]-d[u][llst]);
        tot[u][cur]=d[u][cur]+tot[fa[u]][lst]-d[u][llst];
      }else tot[u][cur]=d[u][cur];
    }
  }
  printf("%lld\n",ans);
  return 0;
}
