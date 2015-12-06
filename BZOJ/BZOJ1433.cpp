#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 60

using namespace std;
typedef long long LL;

int n,g[N][N],stu[N],home[N];
int vis[N],mark[N];
int match(int u){
  if(vis[u])return 0;
  vis[u]=1;
  For(v,n)if(g[u][v]&&stu[v]){
    if(!mark[v] || match(mark[v])){
      mark[v]=u;
      return 1;
    }
  }
  return 0;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  int T;
  scanf("%d",&T);
  while(T--){
    int flag=1;
    scanf("%d",&n);
    For(i,n)scanf("%d",&stu[i]);
    For(i,n)scanf("%d",&home[i]);
    For(i,n)For(j,n)scanf("%d",&g[i][j]);
    For(i,n)g[i][i]=1;
    memset(mark,0,sizeof(mark));
    For(i,n)
      if(!stu[i] || !home[i]){
	memset(vis,0,sizeof(vis));
	if(!match(i)){flag=0;break;}
      }
    if(!flag)puts("T_T");
    else puts("^_^");
  }
  return 0;
}
