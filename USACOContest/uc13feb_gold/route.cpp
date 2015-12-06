#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#define PROB "route"
#define For(i,n) for(int i=1; i<=n; i++)
#define maxr 100000
#define maxn 40000
#define u first
#define v second

using namespace std;

typedef pair<int,int> Edge;
Edge e[maxr+10];
int lval[maxn+10],rval[maxn+10],n,m,r;
long long d[maxn+10];

vector<int> adj[maxn+10];
int main(){
#ifndef ONLINE_JUDGE
  //freopen("in","r",stdin);
#endif
  freopen(PROB".in","r",stdin);
  freopen(PROB".out","w",stdout);
  scanf("%d%d%d",&n,&m,&r);
  For(i,n)scanf("%d",&lval[i]);
  For(i,m)scanf("%d",&rval[i]);
  For(i,r){
    scanf("%d%d",&e[i].u,&e[i].v);
  }
  sort(e+1,e+r+1);
  For(i,r)
    adj[e[i].u].push_back(e[i].v);
  long long ans=0;
  For(i,m)d[i]=rval[i];
  For(i,n){
    long long maxd=0;
    for(int j=0; j<adj[i].size(); j++)if(!j||adj[i][j]!=adj[i][j-1]){
      long long t=maxd;
      maxd=max(maxd,d[adj[i][j]]);
      d[adj[i][j]]=max(d[adj[i][j]],t+lval[i]+rval[adj[i][j]]);
      //printf("%d %d %d\n",i,adj[i][j],d[adj[i][j]]);
    }
    ans=max(ans,maxd+lval[i]);
  }
  For(i,m)
    ans=max(ans,d[i]);
  printf("%lld",ans);
  return 0;
}
