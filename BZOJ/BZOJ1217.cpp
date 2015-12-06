#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100010
#define INF (1<<29)
 
typedef long long LL;
using namespace std;
 
int le[N],pe[N<<1],ev[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  ev[ecnt]=v;
  pe[ecnt]=le[u];
  le[u]=ecnt;
}
 
int n;
 
int fa[N],q[N]={0,1},front=1,rear=1;
int d1[N],d2[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif 
  memset(d1,0x3f,sizeof(d1));
  scanf("%d",&n);
 
  For(i,n-1){
    int v;
    scanf("%d",&v);
    addEdge(v,i+1);
    addEdge(i+1,v);
  }
 
  while(front<=rear){
    int u=q[front++];
    for(int i=le[u]; i; i=pe[i]){
      if(ev[i]==fa[u])continue;
      fa[ev[i]]=u;
      q[++rear]=ev[i];
    }
  }
   
  int ans=0;
  for(int j=n; j; j--){
    int u=q[j];
    for(int i=le[u]; i; i=pe[i]){
      if(ev[i]==fa[u])continue;
      d1[u]=min(d1[u],d1[ev[i]]+1);
      d2[u]=max(d2[u],d2[ev[i]]+1);
    }
    if(d1[u]<INF && d2[u]+d1[u]<=2)
      d2[u]=-INF;
    else if(d2[u]>=2 || u==1){
      ans++;
      d2[u]=-INF;
      d1[u]=0;
    }
  }
  printf("%d\n",ans);
  return 0;
}
