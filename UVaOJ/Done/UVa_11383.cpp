#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<math.h>
#define CLR(t) memset(t,0,sizeof(t))
#define N 100
#define eps 1e-6
#define For(i,n) for(int i=1; i<=n; i++)
#define dist(x1,y1,x2,y2) (sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)))

using std::min;
using std::max;

int n,xa[N+10],xb[N+10],ya[N+10],yb[N+10],mark[N+10],S[N+10],T[N+10];
double w[N+10][N+10],lx[N+10],ly[N+10],slack[N+10];
bool match(int u){
  S[u]=1;
  For(v,n)
    if(!T[v]){
      double t=lx[u]+ly[v]-w[u][v];
      if(t<eps){
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
  double t=1e10;
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
    lx[i]=-(1e9);
    For(j,n)lx[i]=max(lx[i],w[i][j]);
  }
  For(i,n){
    For(j,n)slack[j]=1e9;
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
  bool f=true;
  while(scanf("%d",&n)!=EOF){
    if(f)f=false;
    else printf("\n");
    For(i,n)scanf("%d%d",&xa[i],&ya[i]);
    For(i,n)scanf("%d%d",&xb[i],&yb[i]);
    For(i,n)For(j,n)
      w[j][i]=-dist(xa[i],ya[i],xb[j],yb[j]);
    KM();
    For(i,n)
      printf("%d\n",mark[i]);
  }
  return 0;
}
