#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<set>
#include<iostream>
#define milk first
#define deadline second
#define N 200
#define PROB "vacation"
#define For(i,n) for(int i=1; i<=n; i++)
#define INF (1<<29)

using namespace std;

int n,m,q,K,d[N+10][N+10];
int main(){
  freopen(PROB".in","r",stdin);
  freopen(PROB".out","w",stdout);
  scanf("%d%d%d%d",&n,&m,&K,&q);
  For(i,n){
    For(j,n)d[i][j]=INF;
    d[i][i]=0;
  }
  For(i,m){
    int u,v,dt;
    scanf("%d%d%d",&u,&v,&dt);
    d[u][v]=min(d[u][v],dt);
  }
  long long ans=0;
  int cnt=0;
  For(k,n)
  For(i,n)
    For(j,n){
    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
  For(i,q){
    int u,v;
    scanf("%d%d",&u,&v);
    int t=INF;
    For(k,K)
      t=min(t,d[u][k]+d[k][v]);
    if(t<INF){
      cnt++;
      ans+=t;
    }
  }
  cout<<cnt<<endl<<ans;
  return 0;
}
