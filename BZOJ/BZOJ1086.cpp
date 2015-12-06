#include<stdio.h>
#include<algorithm>
#include<vector>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 1010

using namespace std;
typedef long long LL;

vector<int> alone[N],adj[N];
int instate[N],state,n,m,cap[N];
void dfs(int u,int fa){
  int t=0,last=0;
  Rep(i,adj[u].size())if(adj[u][i]!=fa){
    dfs(adj[u][i],u);
    t+=(int)alone[adj[u][i]].size();
    if(t>=m){
      ++state;
      cap[state]=u;
      for(int j=last; j<=i; j++)if(adj[u][j]!=fa){
	  int &v=adj[u][j];
	  Rep(k,alone[v].size())
	    instate[alone[v][k]]=state;
      }
      t=0;
      last=i+1;
    }
  }
  for(int i=last; i<adj[u].size(); i++)if(adj[u][i]!=fa){
      int &v=adj[u][i];
      Rep(j,alone[v].size())
	alone[u].push_back(alone[v][j]);
  }
  alone[u].push_back(u);
}
int u,v,g[N][N];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
#endif 
  scanf("%d%d",&n,&m);
  For(i,n-1){
    scanf("%d%d",&u,&v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    g[u][v]=g[v][u]=1;
  }
  dfs(1,0);
  Rep(i,alone[1].size())
    instate[alone[1][i]]=state;
  For(i,n)if(!instate[i]){
    puts("0");
    return 0;
  }
  printf("%d\n",state);
  For(i,n-1)printf("%d ",instate[i]);
  printf("%d\n",instate[n]);
  For(i,state-1)printf("%d ",cap[i]);
  printf("%d\n",cap[state]);
  return 0;
}
