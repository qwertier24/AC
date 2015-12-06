#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<math.h>
#define CLR(t) memset(t,0,sizeof(t))
#define N 500
#define INF (1<<29)
#define For(i,n) for(int i=1; i<=n; i++)

using std::min;
using std::max;

int n;
int w[N+10][N+10],lx[N+10],ly[N+10],slack[N+10],mark[N+10],S[N+10],T[N+10];
bool match(int u){
  S[u]=1;
  For(v,n)
    if(!T[v]){
      int t=lx[u]+ly[v]-w[u][v];
      if(t==0){
	T[v]=1;
	if(!mark[v]||match(mark[v])){
	  mark[v]=u;
	  return true;
	}
      }if(t<slack[v])
	slack[v]=t;
    }
  return false;
}
void update(){
  int t=INF;
  For(i,n)if(!T[i])
    t=min(t,slack[i]);
  For(i,n){
    if(S[i])lx[i]-=t;
    if(T[i])ly[i]+=t;
    else slack[i]-=t;
  }
}
void KM(){
  CLR(ly);
  CLR(mark);
  For(i,n){
    lx[i]=-INF;
    For(j,n)lx[i]=max(lx[i],w[i][j]);
  }
  For(i,n){
    For(j,n)slack[j]=INF;
    CLR(S);CLR(T);
    while(!match(i)){
      update();
      CLR(S);CLR(T);
    }
  }
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif
  while(scanf("%d",&n)!=EOF){
    For(i,n)For(j,n)scanf("%d",&w[i][j]);
    KM();
    int ans=0;
    For(i,n-1)
      printf("%d ",lx[i]);
    printf("%d\n",lx[n]);
    For(i,n-1)
      printf("%d ",ly[i]);
    printf("%d\n",ly[n]);
    For(i,n)ans+=lx[i]+ly[i];
    printf("%d\n",ans);
  }
  return 0;
}
